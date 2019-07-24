Param(
    [string]$DependenciesPath,
    [string]$InstallPath,
    [switch]$Install = $false
)

if (-Not (Get-Module -Name RDTask)) {
    $RDModulePath = "$PSScriptRoot\psbuild"
    if (-Not (Test-Path -Path $RDModulePath)) { 
        git clone --depth 1 git@bitbucket.org:readdle/psbuild.git $RDModulePath
    }
    $Env:PSModulePath += ";$RDModulePath"
}

$ProjectRoot = "$(Resolve-Path ""$PSScriptRoot\..\"")"

$SourceFiles = Get-ChildItem -Path "$ProjectRoot\src\swift\*.swift" -Recurse -File 

$ModuleName = "MailCore"
$IntermediatesPath = "$ProjectRoot\.build\$ModuleName\Intermediates"
$ProductsPath = "$ProjectRoot\.build\$ModuleName"
if (-Not $InstallPath) {
    $InstallPath = "$ProjectRoot\.build\install"
}

$IcuVersion = 64
$IcuPath = "C:\Library\icu-$IcuVersion\usr"

$SwiftIncludePaths = 
    "$ProjectRoot\.build\install\include"

$HeaderSearchPaths = 
    "$ProjectRoot\Externals\include",
    "$IcuPath\include"

$LibrarySearchPaths = 
    "$ProjectRoot\Externals\lib64",
    "$ProjectRoot\.build\install\lib"

$Configuration = @{
    ToolchainPath = "C:\Library\Developer\Toolchains\unknown-Asserts-development.xctoolchain"
    SDKPath = "C:\Library\Developer\Platforms\Windows.platform\Developer\SDKs\Windows.sdk"
    
    ModuleName = $ModuleName

    WorkPath = $ProjectRoot

    IntermediatesPath = $IntermediatesPath
    ProductsPath = $ProductsPath

    SwiftVersion = 5
    EnableTesting = $false
    BuildType = "Release"

    SwiftIncludePaths = $SwiftIncludePaths
    HeaderSearchPaths = $HeaderSearchPaths
    LibrarySearchPaths = $LibrarySearchPaths

    SourceFiles = $SourceFiles

    Libraries = "libetpan"
    OtherCFlags = @()
    # OtherSwiftFlags = "-DDEBUG"
}

Push-Task -Name $ModuleName -ScriptBlock {
    Push-Task -Name "Initialize" -ScriptBlock {
        Invoke-VsDevCmd -Version "2019"
    }

    & $PSScriptRoot\Build-Mailcore2.ps1 -InstallPath $InstallPath -DependenciesPath $DependenciesPath -Install

    Invoke-BuildModuleTarget -Configuration $Script:Configuration

    if ($Install) {
        Push-Task -Name "Install" -ScriptBlock {
            Copy-Item -Path "$ProductsPath\MailCore.lib" -Destination "$InstallPath\lib" -Force -ErrorAction Stop
            Copy-Item -Path "$ProductsPath\MailCore.exp" -Destination "$InstallPath\lib" -Force -ErrorAction Stop
            Copy-Item -Path "$ProductsPath\MailCore.swiftdoc" -Destination "$InstallPath\include" -Force -ErrorAction Stop
            Copy-Item -Path "$ProductsPath\MailCore.swiftmodule" -Destination "$InstallPath\include" -Force -ErrorAction Stop
            Copy-Item -Path "$ProductsPath\MailCore.dll" -Destination "$InstallPath\bin" -Force -ErrorAction Stop
        }
    }
 
}