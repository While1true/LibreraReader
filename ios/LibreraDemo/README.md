Librera iOS integration demo

This folder contains instructions and a small Swift sample showing how to use the LibreraCore Swift Package from an iOS app (SwiftUI).

Quick steps to try locally

1) Open the Xcode project for your app (or create a new SwiftUI app).
2) Add the local package: File -> Add Packages... -> Add Local... and choose the repository root, then select ios/LibreraCore (or point directly to ios/LibreraCore/Package.swift).
3) In your Swift code import the module and call the C APIs:

```swift
import SwiftUI
import LibreraCore

struct ContentView: View {
    @State private var output = ""

    var body: some View {
        VStack(spacing: 16) {
            Text("LibreraCore version: \(String(cString: librera_version()))")
            Button("Init & Process") {
                librera_init()
                if let ptr = librera_process_text("Hello from iOS") {
                    output = String(cString: ptr)
                    free(ptr)
                }
            }
            Text(output)
                .padding()
        }
        .padding()
    }
}
```

Notes
- The current package contains a stub implementation (librera_core.c). To share your existing C/C++ core, replace the contents of `ios/LibreraCore/Sources/LibreraCore/` or update the Package.swift target path to point to the existing source directory in the repository.
- If your existing native code depends on Android/JNI, you'll need to extract platform-independent core functions into a folder that the package can consume; keep platform adapters (JNI) under their platform directories (e.g., `native/platform/android`).
- For building a more production-ready integration, see `ios/README.md`.
