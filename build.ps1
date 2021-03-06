Add-Type -Assembly "System.IO.Compression.FileSystem"

function PrepUnreal
{
	Write-Host "SECTION PrepUnreal"

	$engineVersion = GetUnrealVersion
	$pathToEngine = (Get-Item env:unreal_$engineVersion).Value
	
	$pathToUBT = "$pathToEngine\Engine\Binaries\DotNET\UnrealBuildTool.exe"
	$parameters = "-projectfiles", "-project=`"$PSScriptRoot\Battleship.uproject`"", "-game", "-rocket", "-progress"
	$ubt = Start-Process -FilePath $pathToUBT -ArgumentList $parameters -PassThru -NoNewWindow
	
	$time = 0
	while ($ubt.HasExited -eq $false) {
		if ($time -gt 1800) {
			Write-Host "Timeout exceeded"
			exit -1
		}
		$time = $time + 10
		Start-Sleep -s 10
	}
}

function BuildMaps
{
	$pathToEngine = GetUnrealPath

	Get-ChildItem -Path Content\*.umap -Recurse -Force | ForEach-Object {
		$Base = "$PSScriptRoot\Content\"
		$MapPath = $_.FullName.Replace($Base, "\Game\").Replace(".umap", "").Replace("\", "/")
		Write-Host "MapPath: $MapPath"
		
		$pathToEditor= "$pathToEngine\Engine\Binaries\Win64\UE4Editor-Cmd.exe"
		$parameters = "$PSScriptRoot\Battleship.uproject", "-run=resavepackages", "-buildlighting", "-allowcommandletrendering", "-map=$MapPath"
		$ue = Start-Process -FilePath $pathToEditor -ArgumentList $parameters -PassThru -NoNewWindow

		$time = 0
		while ($ue.HasExited -eq $false) {
			if ($time -gt 7200) {
				Write-Host "Timeout exceeded"
				exit -1
			}
			$time = $time + 10
			Start-Sleep -s 10
		}
		
		Start-Sleep -s 30
	}
}

function BuildVisualStudioSolution
{
	param([string]$Platform)
	
	Write-Host "SECTION BuildVisualStudioSolution $Platform"
	
	$pathToMSBuild = "C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe"
	$pathToSolution = "`"$PSScriptRoot\Battleship.sln`""
	$parameters = "$pathToSolution", "/t:rebuild", "/p:Configuration=Shipping", "/p:Platform=$Platform;verbosity=diagnostic"
	$msbuild = Start-Process -FilePath $pathToMSBuild -ArgumentList $parameters -PassThru -NoNewWindow
	
	$time = 0
	while ($msbuild.HasExited -eq $false) {
		if ($time -gt 1800) {
			Write-Host "Timeout exceeded"
			exit -1
		}
		$time = $time + 10
		Start-Sleep -s 10
	}
}

function BuildUnrealPlugins
{
	param([string]$Platform)
	
	Write-Host "SECTION BuildUnrealPlugins $Platform"

	$engineVersion = GetUnrealVersion
	$pathToEngine = (Get-Item env:unreal_$engineVersion).Value
	
	$pathToUBT = "$pathToEngine\Engine\Binaries\DotNET\UnrealBuildTool.exe"
	$parameters = "Development", "$Platform", "-Project=`"$PSScriptRoot\Battleship.uproject`"", "-TargetType=Editor",  "-Progress", "-NoHotReloadFromIDE"
	$ubt = Start-Process -FilePath $pathToUBT -ArgumentList $parameters -PassThru -NoNewWindow
	
	$time = 0
	while ($ubt.HasExited -eq $false) {
		if ($time -gt 1800) {
			Write-Host "Timeout exceeded"
			exit -1
		}
		$time = $time + 10
		Start-Sleep -s 10
	}
}

function BuildUnreal
{
	param([string]$Platform)
	
	Write-Host "SECTION BuildUnreal $Platform"
	
	$engineVersion = GetUnrealVersion
	$pathToEngine = (Get-Item env:unreal_$engineVersion).Value
	
	$pathToEditor= "$pathToEngine\Engine\Binaries\Win64\UE4Editor.exe"
	$parameters = "$PSScriptRoot\Battleship.uproject", "-run=cook", "-targetplatform=WindowsNoEditor", "-CookAll"
	$ue = Start-Process -FilePath $pathToEditor -ArgumentList $parameters -PassThru -NoNewWindow
	
	$time = 0
	while ($ue.HasExited -eq $false) {
		if ($time -gt 7200) {
			Write-Host "Timeout exceeded"
			exit -1
		}
		$time = $time + 10
		Start-Sleep -s 10
	}
	
	$pathToUAT = "$pathToEngine\Engine\Build\BatchFiles\RunUAT.bat"
	$parameters = "-ScriptsForProject=`"$PSScriptRoot\Battleship.uproject`"", "BuildCookRun", "-nocompile", "-nocompileeditor", "-installed", "-nop4",
	 "-project=`"$PSScriptRoot\Battleship.uproject`"", "-cook", "-stage", "-archive", "-archivedirectory=`"$PSScriptRoot\Output\$Platform`"", "-package", 
	 "-clientconfig=Shipping", "-ue4exe=UE4Editor-Cmd.exe", "-clean", "-prereqs", "-distribution", "-nodebuginfo", "-targetplatform=$Platform",
	 "-build", "-CrashReporter", "-utf8output"
	$uat = Start-Process -FilePath $pathToUAT -ArgumentList $parameters -PassThru -NoNewWindow
	
	$time = 0
	while ($uat.HasExited -eq $false) {
		if ($time -gt 7200) {
			Write-Host "Timeout exceeded"
			exit -1
		}
		$time = $time + 10
		Start-Sleep -s 10
	}
}

function BuildInstaller
{
	param([string]$buildNum)
	
	Write-Host "SECTION BuildInstaller"
	
	$pathToMSBuild = "C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe"
	$pathToSolution = "`"$PSScriptRoot\Installer\BattleshipInstaller.sln`""
	$parameters = "$pathToSolution", "/p:Version=$buildNum", "/p:Configuration=Release", "/p:Platform=x86"
	$msbuild = Start-Process -FilePath $pathToMSBuild -ArgumentList $parameters -PassThru -NoNewWindow
	
	$time = 0
	while ($msbuild.HasExited -eq $false) {
		if ($time -gt 1800) {
			Write-Host "Timeout exceeded"
			exit -1
		}
		$time = $time + 10
		Start-Sleep -s 10
	}
}

function GetBuildNumber
{
	$versionFile = "$PSScriptRoot\..\NextVersionBattleship.txt"	
	$version = Get-Content -Path $versionFile	
	$major, $minor, $revision, $build = $version.split('.', 4)
	[int]$nextbuild = [convert]::ToInt32($build, 10) + 1
	"$($major).$($minor).$($revision).$($nextbuild)" | Out-File $versionFile
	
	return $version
}

function SetUnrealBuildNumber
{
	param([string]$unrealBuildNumber)
	$filepath = "$PSScriptRoot\Config\DefaultGame.ini"
	(Get-Content ($filepath)) | Foreach-Object {$_ -replace '^ProjectVersion=.+$', ("ProjectVersion=" + $unrealBuildNumber)} | Set-Content ($filepath)
}

function GetUnrealVersion
{
	$projectFile = "$PSScriptRoot\Battleship.uproject"	
	$battleship = Get-Content $projectFile | Out-String | ConvertFrom-Json
	
	return $battleship.EngineAssociation
}

function GetUnrealPath
{
	$engineVersion = GetUnrealVersion
	$pathToEngine = (Get-Item env:unreal_$engineVersion).Value
	
	return $pathToEngine
}

function DeployArtifacts
{
	Write-Host "SECTION DeployArtifacts"
	$version = $env:FULL_BUILD_NUMBER
	
	$path = "C:\Users\Jonathan\Google Drive\Frozen Wasteland Entertainment\Battleship\Builds\$version"
	if(!(test-path $path))
	{
		New-Item -ItemType Directory -Force -Path $path
	}
	
	Copy-Item "$PSScriptRoot\Installer\Bundle\bin\Release\FinalEquinoxTheArrivalSetup.exe" $path
}

function StageUnrealOutput
{
	Write-Host "SECTION StageUnrealOutput"
	
	$path = "$PSScriptRoot\Output\Win64\FinalEquinox64bit"
	if(!(test-path $path))
	{
		New-Item -ItemType Directory -Force -Path $path
	}
	
	$path = "$PSScriptRoot\Output\Win32\FinalEquinox32bit"
	if(!(test-path $path))
	{
		New-Item -ItemType Directory -Force -Path $path
	}
	
	$path = "$PSScriptRoot\Output\Linux\FinalEquinoxLinux"
	if(!(test-path $path))
	{
		New-Item -ItemType Directory -Force -Path $path
	}
	
	Move-Item "$PSScriptRoot\Output\Win64\WindowsNoEditor\Engine\Extras\Redist\en-us\UE4PrereqSetup_x64.exe" "$PSScriptRoot\Output\Win64\FinalEquinox64bit\UE4PrereqSetup_x64.exe"
	Move-Item "$PSScriptRoot\Output\Win32\WindowsNoEditor\Engine\Extras\Redist\en-us\UE4PrereqSetup_x86.exe" "$PSScriptRoot\Output\Win32\FinalEquinox32bit\UE4PrereqSetup_x86.exe"
	Move-Item "$PSScriptRoot\Output\Win64\WindowsNoEditor\Manifest_NonUFSFiles_Win64.txt" "$PSScriptRoot\Output\"
	Move-Item "$PSScriptRoot\Output\Win64\WindowsNoEditor\Manifest_UFSFiles_Win64.txt" "$PSScriptRoot\Output\"
	Move-Item "$PSScriptRoot\Output\Win32\WindowsNoEditor\Manifest_NonUFSFiles_Win32.txt" "$PSScriptRoot\Output\"
	Move-Item "$PSScriptRoot\Output\Win32\WindowsNoEditor\Manifest_UFSFiles_Win32.txt" "$PSScriptRoot\Output\"
	
	Move-Item "$PSScriptRoot\Output\Win64\WindowsNoEditor" "$PSScriptRoot\Output\Win64\FinalEquinox64bit\Battleship"
	Move-Item "$PSScriptRoot\Output\Win32\WindowsNoEditor" "$PSScriptRoot\Output\Win32\FinalEquinox32bit\Battleship"
	Move-Item "$PSScriptRoot\Output\Linux\LinuxNoEditor" "$PSScriptRoot\Output\Linux\FinalEquinoxLinux"
}

function CreateZipFiles
{
	[IO.Compression.ZipFile]::CreateFromDirectory("$PSScriptRoot\Output\Win64\FinalEquinox64bit\", "$PSScriptRoot\Output\FinalEquinox64bit.zip")
	[IO.Compression.ZipFile]::CreateFromDirectory("$PSScriptRoot\Output\Win32\FinalEquinox32bit\", "$PSScriptRoot\Output\FinalEquinox32bit.zip")
	
	$pathTo7Zip = "C:\Program Files\7-Zip\7z.exe"
	
	$parameters = "a", "-ttar", "$PSScriptRoot\Output\FinalEquinoxLinux.tar", "$PSScriptRoot\Output\Linux\FinalEquinoxLinux\LinuxNoEditor\*"
	$process = Start-Process -FilePath $pathTo7Zip -ArgumentList $parameters -PassThru -NoNewWindow
	
	$time = 0
	while ($process.HasExited -eq $false) {
		if ($time -gt 1800) {
			Write-Host "Timeout exceeded"
			exit -1
		}
		$time = $time + 10
		Start-Sleep -s 10
	}
	
	$parameters = "a", "-tgzip", "$PSScriptRoot\Output\FinalEquinoxLinux.tar.gz", "$PSScriptRoot\Output\FinalEquinoxLinux.tar"
	$process = Start-Process -FilePath $pathTo7Zip -ArgumentList $parameters -PassThru -NoNewWindow
	
	$time = 0
	while ($process.HasExited -eq $false) {
		if ($time -gt 1800) {
			Write-Host "Timeout exceeded"
			exit -1
		}
		$time = $time + 10
		Start-Sleep -s 10
	}
}

function DeployZipFiles
{
	Write-Host "SECTION DeployZipFiles"
	$version = $env:FULL_BUILD_NUMBER
	
	$path = "E:\BattleshipBuilds\$version"
	if(!(test-path $path))
	{
		New-Item -ItemType Directory -Force -Path $path
	}
	
	Copy-Item "$PSScriptRoot\Output\FinalEquinox64bit.zip" $path
	Copy-Item "$PSScriptRoot\Output\FinalEquinox32bit.zip" $path
	Copy-Item "$PSScriptRoot\Output\FinalEquinoxLinux.tar.gz" $path
}

#Clean up output from previous build
Remove-Item "$PSScriptRoot\Output" -Recurse -ErrorAction Ignore

$version = $env:FULL_BUILD_NUMBER
Write-Host "BuildNumber: $version"

SetUnrealBuildNumber $version

PrepUnreal
BuildVisualStudioSolution "Win64"
BuildUnrealPlugins "Win64"
BuildMaps
BuildUnreal "Win64"
BuildVisualStudioSolution "Win32"
BuildUnreal "Win32"
BuildUnreal "Linux"
StageUnrealOutput
CreateZipFiles
DeployZipFiles

#Set the number back so source control doesn't see a change
SetUnrealBuildNumber "1.0.0.9999"