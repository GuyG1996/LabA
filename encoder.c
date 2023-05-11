#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    int encode = 0, key_val, key_pos = 2;
    bool debug = false;
    FILE *infile = stdin;
    FILE *outfile = stdout;
    int encode_index = 0;
    char *input_file = NULL;
    char *output_file = NULL;
    char c;

    // parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '+') {
            if (argv[i][1] == 'D') {
                debug = true;
            }
            else if (argv[i][1] == 'e') {
                encode = 1;
                encode_index = i;
            }
        }
        else if (argv[i][0] == '-') {
            if (argv[i][1] == 'D') {
                debug = false;
            }
            else if (argv[i][1] == 'e') {
                encode = -1;
                encode_index = i;
            }
            else if (argv[i][1] == 'i') {
                input_file = &argv[i][2];
            }
            else if (argv[i][1] == 'o') {
                output_file = &argv[i][2];
            }
        }

        // print debug info
        if(debug) {
            fprintf(stderr, "%s\n", argv[i]);
        }

        // set input file
        if (input_file != NULL) {
            infile = fopen(input_file, "r");
            if (infile == NULL) {
                fprintf(stderr, "Error: could not open input file\n");
                return 1;
            }
        }
        // set output file
        if (output_file != NULL) {
            outfile = fopen(output_file, "w");
            if (outfile == NULL) {
                fprintf(stderr, "Error: could not open output file\n");
                return 1;
            }
        }
    }

        if(encode != 0){
            while ((c = fgetc(infile)) != EOF) {
                if(argv[encode_index][key_pos] == '\0')
                    key_pos = 2;
                key_val = encode * (argv[encode_index][key_pos] - '0');
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
                key_pos++;
                fputc(c, outfile);
            }
        }
        
    if(infile)
        fclose(infile);
    if(outfile)
        fclose(outfile);
    return 0;
}
    
