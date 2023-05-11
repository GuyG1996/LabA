#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int c, key_len, key_pos = 0, key_val;
    char *key_str = NULL;

    if (argc > 1 && ((argv[1][0] == '-' || argv[1][0] == '+') && argv[1][1] == 'e'))   {
        key_str = argv[1] + 2;
        key_len = 0;
        while (key_str[key_len] != '\0') {
            key_len++;
        }
    }
    while ((c = fgetc(stdin)) != EOF) {
        if (key_str && isalnum(c)) {
            key_val = key_str[key_pos] - '0';
            key_pos = (key_pos + 1) % key_len;
            if (argv[1][0] == '-') {
                key_val = -key_val;
            }
        } 
        else {
            key_val = 0;
        }
        if (c >= 'A' && c <= 'Z') {
            if (c + key_val > 'Z') {
                c = c + key_val - 26;
            }
            else if (c + key_val < 'A') {
                c = c + key_val + 26;
            }
            else {
                c = c + key_val;
            }
        }
        else if (c >= 'a' && c <= 'z') {
            if (c + key_val > 'z') {
                c = c + key_val - 26;
            }
            else if (c + key_val < 'a') {
                c = c + key_val + 26;
            }
            else {
                c = c + key_val;
            }
        }
        else if (c >= '0' && c <= '9') {
            if (c + key_val > '9') {
                c = c + key_val - 10;
            }
            else if (c + key_val < '0') {
                c = c + key_val + 10;
            }
            else {
                c = c + key_val;
            }
        }
        fputc(c, stdout);
    }
    return 0;
}


