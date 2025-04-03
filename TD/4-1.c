#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char * argv[]){
    struct stat infos;
    if (argc !=2){
        fprintf(stderr, "Nombre argument incorrect\n");
        exit(1);
    }
    if (stat (argv[1], &infos) == -1){
        perror("echec stat\n");
        exit(2);
    }

    printf("La désignation du fichier est : %s \n sa taille : %ld \n sa date de derniere modification : %s\n", argv[1], infos.st_size, ctime(&infos.st_mtime));
    return 0;
}

