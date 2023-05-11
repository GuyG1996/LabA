#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[]) {
    bool debug_mode = false;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "+D") == 0) {
            debug_mode = true;
        } else if (strcmp(argv[i], "-D") == 0) {
            debug_mode = false;
        }
        else if (debug_mode) {
            fprintf(stderr, "%s\n", argv[i]);
        }
    }   
    return 0;
}