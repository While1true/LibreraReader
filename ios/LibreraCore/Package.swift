// Package.swift
// Swift Package for LibreraCore C sources (iOS)
import PackageDescription

let package = Package(
    name: "LibreraCore",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(name: "LibreraCore", targets: ["LibreraCore"]),
    ],
    targets: [
        .target(
            name: "LibreraCore",
            path: "Sources/LibreraCore",
            publicHeadersPath: "include",
            cSettings: [
                .headerSearchPath("include")
            ]
        )
    ]
)
