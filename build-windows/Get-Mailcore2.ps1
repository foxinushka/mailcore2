Param(
    [string]$InstallPath
)

$ProjectRoot = "$(Resolve-Path ""$PSScriptRoot\..\"")"

if (-Not $InstallPath) {
    $InstallPath = "$ProjectRoot\.build\install"
}

$PrebuiltMailcoreVersion = 1
$PrebuiltMailcoreArchive = "mailcore2-all-$PrebuiltMailcoreVersion.zip"
$PrebuiltMailcoreUrl = "https://spark-prebuilt-binaries.s3.amazonaws.com/$PrebuiltMailcoreArchive"

$S3Key = $env:SPARK_PREBUILT_KEY
if (!$S3Key) {
    throw "Spark prebuilt storage key(SPARK_PREBUILT_KEY) is required"
}

Push-Task -Name "mailcore2" -ScriptBlock {
    Push-Task -Name "Initialize" -ScriptBlock {
        Write-TaskLog "Working in $ProjectRoot"
        Push-Location -Path $ProjectRoot
    }

    try {
        $TempFile = [System.IO.Path]::GetTempFileName() + ".zip"
        Write-Host $TempFile

        Invoke-RestMethod -Uri $PrebuiltMailcoreUrl -OutFile $TempFile -UserAgent $S3Key
        Expand-Archive -Path $TempFile -DestinationPath $InstallPath -Force

        Remove-Item $TempFile
    }
    finally {
        Push-Task -Name "Shutdown" -ScriptBlock {
            Pop-Location
        }
    }
}
