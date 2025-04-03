#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    pid_t pfils;
    pfils = fork();
    if (pfils == -1){
        perror("Echec fork : ");
        exit(1);
    }
    else if (pfils){
        printf("Pere %d : mon fils est %d\n", getpid(), pfils); // on peut caster chaque getpid ou getppid
    }
    else{
        printf("Fils %d : mon père est %d\n", getpid(), getppid());
    }
    return 0;
}