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
$DependenciesPath = "$ProjectRoot\.build\Dependencies"
$IntermediatesPath = "$ProjectRoot\.build\$ModuleName\Intermediates"
$ProductsPath = "$ProjectRoot\.build\$ModuleName"

$IcuVersion = 64
$IcuPath = "C:\Library\icu-$IcuVersion\usr"

$SwiftIncludePaths = 
    "$ProjectRoot\.build\install\include\CMailCore"

$HeaderSearchPaths = 
    "$ProjectRoot\Externals\include",
    "$IcuPath\include"

$LibrarySearchPaths = @()

$Configuration = @{
    ToolchainPath = "C:\Library\Developer\Toolchains\unknown-Asserts-development.xctoolchain"
    SDKPath = "C:\Library\Developer\Platforms\Windows.platform\Developer\SDKs\Windows.sdk"
    
    ModuleName = $ModuleName

    WorkPath = $ProjectRoot

    IntermediatesPath = $IntermediatesPath
    ProductsPath = $ProductsPath

    SwiftVersion = 5
    EnableTesting = $true
    BuildType = "Release"

    SwiftIncludePaths = $SwiftIncludePaths
    HeaderSearchPaths = $HeaderSearchPaths
    LibrarySearchPaths = $LibrarySearchPaths

    SourceFiles = $SourceFiles

    Libraries = @()
    OtherCFlags = @()
    # OtherSwiftFlags = "-DDEBUG"
}

Push-Task -Name $ModuleName -ScriptBlock {
    Push-Task -Name "Initialize" -ScriptBlock {
        Invoke-VsDevCmd -Version "2019"
    }

    Invoke-BuildModuleTarget -Configuration $Script:Configuration    
}