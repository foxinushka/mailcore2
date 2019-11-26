if (-Not (Get-Module -ListAvailable -Name RDTask -All)) {
    $RDModulePath = "$PSScriptRoot\psbuild"
    if (-Not (Test-Path -Path $RDModulePath)) { 
        git clone --depth 1 git@ssh.dev.azure.com:v3/readdle/Desktop%20Spark/psbuild $RDModulePath
    }
    $Env:PSModulePath += ";$RDModulePath"
}
