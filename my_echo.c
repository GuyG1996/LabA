#include <stdio.h>

int main(int argc, char *argv[]) {
    for(int i=1 ;i<argc;i++){
        printf("argNum: %d, %s " ,i,argv[i]);
    }
    printf("\n");
    return 0;
}