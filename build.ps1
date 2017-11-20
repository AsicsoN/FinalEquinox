function PrepUnreal
{
	$engineVersion = GetUnrealVersion
	$pathToEngine = (Get-Item env:unreal_$engineVersion).Value
	
	$pathToUBT = "$pathToEngine\Engine\Binaries\DotNET\UnrealBuildTool.exe"
	$parameters = "-projectfiles", "-project=`"$PSScriptRoot\Battleship.uproject`"", "-game", "-rocket", "-progress"
	$ubt = Start-Process -FilePath $pathToUBT -ArgumentList $parameters -PassThru -Wait -NoNewWindow
	if ($ubt.ExitCode -ne 0) {
		exit $ubt.ExitCode
	}
}

function BuildVisualStudioSolution
{
	param([string]$Platform)
	
	$pathToMSBuild = "C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe"
	$pathToSolution = "`"$PSScriptRoot\Battleship.sln`""
	$parameters = "$pathToSolution", "/t:rebuild", "/p:Configuration=Shipping", "/p:Platform=$Platform;verbosity=diagnostic"
	$msbuild = Start-Process -FilePath $pathToMSBuild -ArgumentList $parameters -PassThru -NoNewWindow
	
	$time = 0
	while ($msbuild.HasExited -eq $false) {
		if ($time > 600) {
			Write-Host "Timeout exceeded"
			exit -1
		}
		$time = $time + 10
		Start-Sleep -s 10
	}
	
	if ($msbuild.ExitCode -ne 0) {
		#exit $msbuild.ExitCode
	}
}

function BuildUnrealPlugins
{
	param([string]$Platform)

	$engineVersion = GetUnrealVersion
	$pathToEngine = (Get-Item env:unreal_$engineVersion).Value
	
	$pathToUBT = "$pathToEngine\Engine\Binaries\DotNET\UnrealBuildTool.exe"
	$parameters = "Battleship", "Development", "$Platform", "-project=`"$PSScriptRoot\Battleship.uproject`"", "-editorrecompile",  "-progress", "-NoHotReloadFromIDE"
	$ubt = Start-Process -FilePath $pathToUBT -ArgumentList $parameters -PassThru -Wait -NoNewWindow
	if ($ubt.ExitCode -ne 0) {
		exit $ubt.ExitCode
	}
}

function BuildUnreal
{
	param([string]$Platform)
	
	$engineVersion = GetUnrealVersion
	$pathToEngine = (Get-Item env:unreal_$engineVersion).Value
	
	$pathToUAT = "$pathToEngine\Engine\Build\BatchFiles\RunUAT.bat"
	$parameters = "-ScriptsForProject=`"$PSScriptRoot\Battleship.uproject`"", "BuildCookRun", "-nocompile", "-nocompileeditor", "-installed", "-nop4",
	 "-project=`"$PSScriptRoot\Battleship.uproject`"", "-cook", "-stage", "-archive", "-archivedirectory=`"$PSScriptRoot\Output\$Platform`"", "-package", 
	 "-clientconfig=Shipping", "-ue4exe=UE4Editor-Cmd.exe", "-clean", "-pak", "-prereqs", "-distribution", "-nodebuginfo", "-targetplatform=$Platform",
	 "-build", "-CrashReporter", "-utf8output"
	$uat = Start-Process -FilePath $pathToUAT -ArgumentList $parameters -PassThru -Wait -NoNewWindow
	if ($uat.ExitCode -ne 0) {
		exit $uat.ExitCode
	}
}

function BuildInstaller
{
	param([string]$buildNum)
	$pathToMSBuild = "C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe"
	$pathToSolution = "`"$PSScriptRoot\Installer\BattleshipInstaller.sln`""
	$parameters = "$pathToSolution", "/p:Version=$buildNum", "/p:Configuration=Release", "/p:Platform=x86"
	$msbuild = Start-Process -FilePath $pathToMSBuild -ArgumentList $parameters -PassThru -Wait -NoNewWindow
	if ($msbuild.ExitCode -ne 0) {
		exit $msbuild.ExitCode
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

#Clean up output from previous build
Remove-Item "$PSScriptRoot\Output" -Recurse -ErrorAction Ignore

$version = $env:FULL_BUILD_NUMBER
Write-Host "BuildNumber: $version"

SetUnrealBuildNumber $version

PrepUnreal
BuildVisualStudioSolution "Win64"
BuildUnrealPlugins "Win64"
BuildUnreal "Win64"
BuildVisualStudioSolution "Win32"
BuildUnrealPlugins "Win32"
BuildUnreal "Win32"
BuildInstaller $version

#Set the number back so source control doesn't see a change
SetUnrealBuildNumber "1.0.0.9999"