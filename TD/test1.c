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
/* Pour arriver a 512 octet
zubefubzfubzubfuzef
zef
zef
z
__FD_SETSIZEef
ze
__FD_SETSIZEf
zef
zfe
zf
zf
z*/