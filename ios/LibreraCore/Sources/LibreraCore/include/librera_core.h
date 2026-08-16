#ifndef LIBRERA_CORE_H
#define LIBRERA_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

// Minimal public C API for Librera core. Replace or extend with real APIs.

// Return a version string owned by the library (static literal).
const char* librera_version(void);

// Initialize core. Call once at app startup.
void librera_init(void);

// Example function: process a simple string and return a heap-allocated result.
// The caller owns the returned string and should free() it.
char* librera_process_text(const char* input);

#ifdef __cplusplus
}
#endif

#endif // LIBRERA_CORE_H
