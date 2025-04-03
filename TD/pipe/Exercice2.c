#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    int tube[2];
    char car;

    if (pipe(tube) == -1){
        perror("pipe");
        exit(1);
    }
    switch(fork()){
        case -1:
            perror("fork");
            exit(2);
        case 0:
    
        default:
            break;   
    }
    
}