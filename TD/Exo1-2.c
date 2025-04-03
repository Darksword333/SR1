#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    if (argc != 2){
        fprintf(stderr, "Erreur sur le nombre d'argument\n");
        return 1;
    }
    char * val = getenv(argv[1]);
    if (val == NULL){
        fprintf(stderr, "Erreur l'argument n'est pas existant dans getenv\n");
        return 2;
    }
    printf("%s=%s\n", argv[1], val);
    return 0;
}