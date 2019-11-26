Param(
    [string]$DependenciesPath,
    [string]$InstallPath,
    [switch]$Install = $false
)

.\Resolve-PSBuild.ps1

Import-Module RDBuildCMake
Import-Module RDBuildMSVC
Import-Module RDDependency

$ProjectRoot = "$(Resolve-Path ""$PSScriptRoot\..\"")"
if (-Not $DependenciesPath) {
    $DependenciesPath = "$ProjectRoot\.build\Dependencies"
}
if (-Not $InstallPath) {
    $InstallPath = "$ProjectRoot\.build\install"
}

$IcuVersion = 64
$IcuPath = "C:\Library\icu-$IcuVersion\usr"
$LibXml2Path = "C:\Library\libxml2-development\usr"

$CTemplateDependencyDir = "CTemplate"
$CTemplateDependencyPath = "$DependenciesPath\$CTemplateDependencyDir\ctemplate-win32-1"
$LibEtPanDependencyDir = "LibEtPan"
$LibEtPanDependencyPath = "$DependenciesPath\$LibEtPanDependencyDir"
$TidyDependencyDir = "TidyHTML5"
$TidyDependencyPath = "$DependenciesPath\$TidyDependencyDir"
$ZlibDependencyDir = "zlib"
$ZlibDependencyPath = "$DependenciesPath\$ZlibDependencyDir\zlib-win32-1"
$SaslDependencyDir = "SASL"
$SaslDependencyPath = "$DependenciesPath\$SaslDependencyDir\cyrus-sasl-win32-2"
$OpenSslDependencyDir = "OpenSSL"
$OpenSslDependencyPath = "$DependenciesPath\$OpenSslDependencyDir\openssl-1.0.1j-vs2013"

$Dependencies = @(
    @{ Name = "CTemplate"; WebUrl = "http://d.etpan.org/mailcore2-deps/ctemplate-win32/ctemplate-win32-1.zip"; Directory = $CTemplateDependencyDir; }
    @{ Name = "Cyrus SASL"; WebUrl = "http://d.etpan.org/mailcore2-deps/cyrus-sasl-win32/cyrus-sasl-win32-2.zip"; Directory = $SaslDependencyDir; }
    @{ Name = "zlib"; WebUrl = "http://d.etpan.org/mailcore2-deps/zlib-win32/zlib-win32-1.zip"; Directory = $ZlibDependencyDir; }
    @{ Name = "OpenSSL"; WebUrl = "http://d.etpan.org/mailcore2-deps/misc-win32/openssl-1.0.1j-vs2013.zip"; Directory = $OpenSslDependencyDir; }
    
    @{ Name = "LibEtPan"; GitUrl = "git@github.com:dinhviethoa/libetpan.git"; GitTag = "1.9.3"; Directory = $LibEtPanDependencyDir; }
    @{ Name = "Tidy HTML5"; GitUrl = "git@github.com:readdle/tidy-html5.git"; GitBranch = "feature/windows"; Directory = $TidyDependencyDir; }
)

Push-Task -Name "mailcore2" -ScriptBlock {
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
            $CMakeArgs =
                "-G Ninja",
                "-DCMAKE_BUILD_TYPE=RelWithDebInfo",
                "-DCMAKE_INSTALL_PREFIX=$TidyDependencyPath",
                "-DCMAKE_C_COMPILER=cl.exe",
                "-DCMAKE_CXX_COMPILER=cl.exe",
                "-DCMAKE_EXE_LINKER_FLAGS_INIT=/INCREMENTAL:NO",
                "-DCMAKE_SHARED_LINKER_FLAGS_INIT=/INCREMENTAL:NO" -join " "

            Invoke-CMakeTasks -WorkingDir $TidyDependencyPath -CMakeArgs $CMakeArgs
        }

        Push-Task -Name "Setup LibEtPan Dependencies" -ScriptBlock {
            Copy-Item "$ProjectRoot\build-windows\vs2019\libetpan\libetpan.vcxproj" -Destination "$LibEtPanDependencyPath\build-windows\libetpan" -Force -ErrorAction Stop

            $ExternalsPath = "$LibEtPanDependencyPath\third-party"
            if (-Not (Test-Path "$ExternalsPath\include")) {
                New-Item -Path "$ExternalsPath\include" -ItemType Directory -ErrorAction Stop
            }
            
            if (-Not (Test-Path "$ExternalsPath\lib64")) {
                New-Item -Path "$ExternalsPath\lib64" -ItemType Directory -ErrorAction Stop
            }

            Copy-Item -Path "$ZlibDependencyPath\include" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop
            Copy-Item -Path "$ZlibDependencyPath\lib64" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop
            Copy-Item -Path "$SaslDependencyPath\include" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop
            Copy-Item -Path "$SaslDependencyPath\lib64" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop
            Copy-Item -Path "$OpenSslDependencyPath\include" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop
            Copy-Item -Path "$OpenSslDependencyPath\lib64" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop
        }

        Push-Task -Name "Build LibEtPan" -ScriptBlock {
            MSBuild "$LibEtPanDependencyPath\build-windows\libetpan.sln" /t:libetpan /p:Configuration="Release" /p:Platform="x64"
        }

        Push-Task -Name "Setup CMailcore Dependencies" -ScriptBlock {
            $ExternalsPath = "$ProjectRoot\Externals"
            if (-Not (Test-Path "$ExternalsPath\include")) {
                New-Item -Path "$ExternalsPath\include" -ItemType Directory -ErrorAction Stop
            }
            
            if (-Not (Test-Path "$ExternalsPath\lib64")) {
                New-Item -Path "$ExternalsPath\lib64" -ItemType Directory -ErrorAction Stop
            }

            Copy-Item -Path "$ZlibDependencyPath\include" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$ZlibDependencyPath\lib64" -Destination $ExternalsPath -Exclude "*.dll" -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$SaslDependencyPath\include" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$SaslDependencyPath\lib64" -Destination $ExternalsPath -Exclude "*.dll" -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$OpenSslDependencyPath\include" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$OpenSslDependencyPath\lib64" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$CTemplateDependencyPath\include" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$CTemplateDependencyPath\lib64" -Destination $ExternalsPath -Exclude "*.dll" -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$SaslDependencyPath\include" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$SaslDependencyPath\lib64" -Destination $ExternalsPath -Exclude "*.dll" -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$ZlibDependencyPath\include" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$ZlibDependencyPath\lib64" -Destination $ExternalsPath -Exclude "*.dll" -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$OpenSslDependencyPath\include" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$OpenSslDependencyPath\lib64\ssleay32MD.lib" -Destination "$ExternalsPath\lib64" -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$OpenSslDependencyPath\lib64\libeay32MD.lib" -Destination "$ExternalsPath\lib64" -Force -ErrorAction Stop -PassThru | Write-Host
            
            Copy-Item -Path "$LibEtPanDependencyPath\build-windows\include" -Destination $ExternalsPath -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$LibEtPanDependencyPath\build-windows\x64\Release\libetpan.lib" -Destination "$ExternalsPath\lib64" -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$LibEtPanDependencyPath\build-windows\x64\Release\libetpan.pdb" -Destination "$ExternalsPath\lib64" -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$TidyDependencyPath\include" -Destination "$ExternalsPath\include\tidy" -Recurse -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$TidyDependencyPath\rdtidy.lib" -Destination "$ExternalsPath\lib64" -Force -ErrorAction Stop -PassThru | Write-Host
            Copy-Item -Path "$TidyDependencyPath\rdtidy.exp" -Destination "$ExternalsPath\lib64" -Force -ErrorAction Stop -PassThru | Write-Host
        }

        Push-Task -Name "Build mailcore2/CMailCore" -ScriptBlock {
            $CMakeArgs =
                "-G Ninja",
                $ProjectRoot,
                "-DCMAKE_BUILD_TYPE=RelWithDebInfo",
                "-DCMAKE_INSTALL_PREFIX=$InstallPath",
                "-DCMAKE_C_COMPILER=clang-cl.exe",
                "-DCMAKE_CXX_COMPILER=clang-cl.exe",
                "-DLIBXML_INCLUDE_DIR=C:\Library\libxml2-development\usr\include",
                "-DLIBXML_LIBRARY=C:\Library\libxml2-development\usr\lib\libxml2s.lib",
                "-DICU4C_INCLUDE_DIR=C:\Library\icu-64\usr\include",
                "-DICU4C_UC_LIBRARY=C:\Library\icu-64\usr\lib\icuuc64.lib",
                "-DICU4C_IN_LIBRARY=C:\Library\icu-64\usr\lib\icuin64.lib",
                "-DDISPATCH_INCLUDE_DIR=C:\Library\Developer\Platforms\Windows.platform\Developer\SDKs\Windows.sdk\usr\lib\swift",
                "-DDISPATCH_LIBRARY=C:\Library\Developer\Platforms\Windows.platform\Developer\SDKs\Windows.sdk\usr\lib\swift\windows\dispatch.lib",
                "-DDISPATCH_BLOCKS_LIBRARY=C:\Library\Developer\Platforms\Windows.platform\Developer\SDKs\Windows.sdk\usr\lib\swift\windows\BlocksRuntime.lib" -join " "

            Invoke-CMakeTasks -WorkingDir "$ProjectRoot\.build\mailcore2" -CMakeArgs $CMakeArgs -NoInstall:$(-not $Install)
        }

    }
    finally {
        Push-Task -Name "Shutdown" -ScriptBlock {
            Pop-Location
        }
    }
}
