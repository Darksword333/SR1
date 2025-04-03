#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>

long TailleRepCour(void){
    struct stat st;
    long taille = 0;
    if (stat(".", &st) == -1){
        perror("stat");
        exit(EXIT_FAILURE);
    }
    if (S_ISDIR(st.st_mode)){
        DIR *dirp;
        struct dirent *dptr;
        if ((dirp = opendir(".")) == NULL){
            perror("opendir");
            exit(EXIT_FAILURE);
        }
        while ((dptr = readdir(dirp)) != NULL){
            if (stat(dptr->d_name, &st) == -1){
                perror("stat");
                exit(EXIT_FAILURE);
            }
            taille += st.st_size;
        }
        closedir(dirp);
    }
    return taille;
}

int main(void){
    printf("Taille du répertoire courant : %ld octets\n", TailleRepCour());
    return EXIT_SUCCESS;
}
