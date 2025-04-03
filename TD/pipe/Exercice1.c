#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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
            close(tube[0]);
            read(tube[0], &car, 1);
            printf("Caractere : %c\n", car);
            close(tube[0]);
        default:
            break;
    }

    close(tube[1]);
    while (read (tube[0], (void *)&car, sizeof(char)))
        printf("Caractere : %c\n", car);
    //scanf("%c", &car);
    //write(tube[1], &car, 1);
    close(tube[0]);
    
    exit(0);
}