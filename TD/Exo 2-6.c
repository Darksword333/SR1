#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    int pid_fork=fork();
    if (pid_fork == -1){
        exit(-1);
    }
    else if (pid_fork==0){
        execl("/bin/ls", "ls", "-l", NULL);
        exit(1);
    }
    else{
        wait(NULL);
        switch(pid_fork=fork()){
            case -1 : perror("Echec Fork");
                exit(3);
            case 0 : execl("pwd", "pwd", NULL);
            perror("Echec fork exec 2");
            exit(4);
        default : wait(NULL);
        }
    }
    exit(0);
}
