param([string]$DirectoryToHarvest, [string]$OutFile)

Write-Host "DirectoryToHarvest: $DirectoryToHarvest"
Write-Host "OutFile: $OutFile"

$heat = "$($env:WIX)bin\heat.exe"
$parameters = "dir", "`"$DirectoryToHarvest`"", "-ag", "-cg", "UnrealFiles", "-dr", "INSTALLDIR", "-scom", "-sfrag", "-srd", "-sreg",
"-var", "REPLACETHIS", "-out", "`"$OutFile`""
$proc = Start-Process -FilePath $heat -ArgumentList $parameters -PassThru -Wait -NoNewWindow
if ($proc.ExitCode -ne 0) {
	exit $proc.ExitCode
}

(Get-Content $OutFile).replace('$(REPLACETHIS)', "$DirectoryToHarvest") | Set-Content $OutFile