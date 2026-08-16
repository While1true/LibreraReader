#include "include/librera_core.h"
#include <stdlib.h>
#include <string.h>

const char* librera_version(void) {
    return "librera-core-ios-stub-0.1";
}

void librera_init(void) {
    // Stub init. Replace with actual core initialization.
}

char* librera_process_text(const char* input) {
    if (!input) return NULL;
    const char* prefix = "Processed: ";
    size_t lp = strlen(prefix);
    size_t li = strlen(input);
    char* out = (char*)malloc(lp + li + 1);
    if (!out) return NULL;
    memcpy(out, prefix, lp);
    memcpy(out + lp, input, li);
    out[lp + li] = '\0';
    return out;
}
