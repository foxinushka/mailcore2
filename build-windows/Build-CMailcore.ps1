if (-Not (Get-Module -Name RDTask)) {
    $RDModulePath = "$PSScriptRoot\psbuild"
    if (-Not (Test-Path -Path $RDModulePath)) { 
        git clone --depth 1 git@bitbucket.org:readdle/psbuild.git $RDModulePath
    }
    $Env:PSModulePath += ";$RDModulePath"
}

Import-Module RDBuildCMake
Import-Module RDBuildMSVC
Import-Module RDDependency

$ProjectRoot = "$(Resolve-Path ""$PSScriptRoot\..\"")"
$DependenciesPath = "$ProjectRoot\.build\Dependencies"

$IcuVersion = 64
$IcuPath = "C:\Library\icu-$IcuVersion\usr"
$LibXml2Path = "C:\Library\libxml2-development\usr"

$Dependencies = @(
    @{ Name = "CTemplate"; WebUrl = "http://d.etpan.org/mailcore2-deps/ctemplate-win32/ctemplate-win32-1.zip"; Directory = "CTemplate"; }
    @{ Name = "LibEtPan"; WebUrl = "http://d.etpan.org/mailcore2-deps/libetpan-win32/libetpan-win32-2.zip"; Directory = "LibEtPan"; }
    @{ Name = "Cyrus SASL"; WebUrl = "http://d.etpan.org/mailcore2-deps/cyrus-sasl-win32/cyrus-sasl-win32-2.zip"; Directory = "SASL"; }
    @{ Name = "zlib"; WebUrl = "http://d.etpan.org/mailcore2-deps/zlib-win32/zlib-win32-1.zip"; Directory = "zlib"; }
    @{ Name = "OpenSSL"; WebUrl = "http://d.etpan.org/mailcore2-deps/misc-win32/openssl-1.0.1j-vs2013.zip"; Directory = "OpenSSL"; }
    @{ Name = "pthreads"; WebUrl = "http://d.etpan.org/mailcore2-deps/misc-win32/pthreads-w32-2-9-1-release.zip"; Directory = "pthreads"; }

    @{ Name = "Tidy HTML5"; GitUrl = "git@github.com:readdle/tidy-html5.git"; GitTag = "5.4.24"; Directory = "TidyHTML5"; }
)

Push-Task -Name "CMailcore" -ScriptBlock {
    Push-Task -Name "Initialize" -ScriptBlock {
        Write-TaskLog "Working in $ProjectRoot"
        Push-Location -Path $ProjectRoot
    }

    try {
        Initialize-Dependencies -Path $Script:DependenciesPath -Dependencies $Script:Dependencies

        Push-Task -Name "Prepare Build Environment" -ScriptBlock {
            Test-Directory $IcuPath -SuccessMessage "Found ICU at $IcuPath" -FailMessage "ICU not found at $IcuPath"
            Test-Directory $LibXml2Path -SuccessMessage "Found LibXml2 at $LibXml2Path" -FailMessage "ICU not found at $LibXml2Path"

            Write-TaskLog "Configuring VS environment"
            Invoke-VsDevCmd -Version "2019"
            
            Test-VCModules
        }

        Push-Task -Name "Build Tidy HTML5" -ScriptBlock {

        }
    }
    finally {
        Push-Task -Name "Shutdown" -ScriptBlock {
            Pop-Location
        }
    }
}
