iOS integration for LibreraReader

What I added

- ios/LibreraCore: a Swift Package (SPM) providing a minimal C public header and a stub C implementation. This is intended to be the place where the shared native core is exposed for iOS.
- ios/LibreraDemo: a short README with a SwiftUI usage sample showing how to call the C functions from Swift.

How to replace stubs with real core

1) Identify the platform-independent C/C++ sources in the repository (core logic). Common locations: `native/`, `core/`, `src/main/cpp/` etc.
2) Option A (recommended): Move or symlink those source files into `ios/LibreraCore/Sources/LibreraCore/` and ensure public headers are placed under `ios/LibreraCore/Sources/LibreraCore/include/`.
3) Option B: Edit `ios/LibreraCore/Package.swift` and change the `path` for the `LibreraCore` target to the existing source folder (for example, `path: "native/core"`).

JNI & Android-specific code

- If current C files include `jni.h` or Android-specific APIs, extract the platform-agnostic logic into a core folder and keep JNI glue under `native/platform/android/` (or similar). I can help with this extraction if you point me to the paths.

Next steps I can take (choose)
- I can locate the C/C++ files in the repo and move or reference them automatically in the SPM package and open a PR with those changes.
- I can add an Xcode demo app (full project) that imports the package directly and runs on device/simulator.
- I can add a CMake -> XCFramework script for binary distribution.

If you want me to continue and wire the real core into the package, reply "wire core" and I will scan the repo for C/C++ source files and update the SPM package to reference them and commit the changes.
