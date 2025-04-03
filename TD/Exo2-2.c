#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/*
int main(void){
    pid_t pfils = fork();
    int pidSucesseur = getpid();
    int x;
    for(int i=0; i<5; i++){

            pfils = fork();

    if (pfils == -1){
        perror("Echec fork : ");
        exit(1);
    }
    else if (pfils){
        printf("Mon numéro est : %d, mon PID est : %d, mon successeur est : %d\n",i ,getpid(), pfils);
    }
    else{
        printf("Mon fils avait pour pid : %d, et pour code retour : %d\n", pfils, WEXITSTATUS(wait(&x)));
    }
    }
    return 0;
}
*/

#define NF 4

int main(void){
    int i, cr; 
    pid_t succF, pidf;
    for (i=NF; i > 0; i--){
        succF = getpid();
        switch(pidf = fork()){
            case -1 : perror("Echec fork");
                exit(1);
            case 0 : fils(i, succF);
                default : pere();
        }
    }
    while((pidf = wait(&cr)) != -1){
        printf("Fils de pid %d a fini avec le code %d\n", pidf, WEXITSTATUS(cr));
    }
    return 0;
}

#define N 4
void fils(int rg, pid_t succ){
    int i;
    for (i = 0; i<N; i++)
        printf("Proc de pid %d de n %d de succ %d\n", getpid(), rg, succ);
    exit(rg);
}