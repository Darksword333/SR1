#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char * argv[]){
    size_t nboctet = 512;
    int octetlu;
    char buffer[nboctet];
    if (argc != 3){
        perror("Erreur il n'y a pas 2 arguments.\n");
        exit(1);
    }
    int fichierSource;
    if ((fichierSource = open(argv[1], O_RDONLY)) == -1){
        perror("Erreur ouverture fichier source\n");
        exit(-1);
    }
    int fichierDestination;
    if ((fichierDestination = open(argv[2], O_CREAT|O_WRONLY|O_TRUNC|S_IRUSR|S_IRGRP|S_IWUSR)) == -1){
        perror("Erreur ouverture fichier destination\n");
        exit(-2);
    }
    octetlu = read(fichierSource, buffer, nboctet);
    while(octetlu == nboctet){
        write(fichierDestination, buffer, nboctet);
        octetlu = read(fichierSource, buffer, nboctet);
    }
    close(fichierSource);
    close(fichierDestination);
}