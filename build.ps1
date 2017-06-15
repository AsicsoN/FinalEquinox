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

$version = GetBuildNumber
Write-Host "BuildNumber: $version"

SetUnrealBuildNumber $version

BuildUnreal "Win64"
BuildUnreal "Win32"
BuildInstaller $version

#Set the number back so source control doesn't see a change
SetUnrealBuildNumber "1.0.0.9999"