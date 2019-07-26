// swift-tools-version:5.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

// TODO: move to toolchain
import Foundation

private func files(in folder: String, withExtension ext: Set<String>, anchor: String = #file) -> [String] {
    let baseURL = URL(fileURLWithPath: anchor)
        .deletingLastPathComponent()
        .appendingPathComponent(folder)

    let allFiles = FileManager.default
        .enumerator(atPath: baseURL.path)?
        .allObjects ?? []

    return allFiles
        .flatMap { $0 as? String }
        .map { URL(fileURLWithPath: $0) }
        .filter { ext.contains($0.pathExtension) }
        .map { $0.relativePath } 
}
// end

let package = Package(
    name: "MailCore",
    products: [
        .library(
            name: "MailCore",
            targets: ["MailCore"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/readdle/tidy-html5.git", .branch("android-swift-5"))
    ],
    targets: [
        .target(
            name: "MailCore",
            dependencies: ["CMailCore"],
            path: "src/swift",
            exclude: files(in: "src/swift", withExtension: ["mm"])
        ),
        .target(
            name: "CMailCore",
            path: "build-android-swift/CMailCore"
        ),
        .testTarget(
            name: "MailCoreTests", 
            dependencies: ["MailCore"],
            path: "unittest",
            exclude: files(in: "unittest", withExtension: ["mm", "cpp"])
        )
    ],
    swiftLanguageVersions: [.v5],
    cxxLanguageStandard: .cxx11
)
