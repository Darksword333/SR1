#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char * argv[]){
    char * endptr;
    long int val;
    if (argc<2){
        fprintf(stderr,"Erreur nombre argument minimum 1\n");
        return 1;
    }
    for (int i=1; i<argc; i++){
        errno = 0;
        val = strtol(argv[i], &endptr, 10);
        if (errno != 0)
            perror("Débordement . ");
        if (endptr == argv[i])
            fprintf(stderr, "Echec.\n");
        printf("Argument %i : %li\n", i, val);
    }
    return 0;
}