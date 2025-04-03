#include <stdio.h>

int main(int argc, char * argv[]){
    printf("Le Programme \"C AINSI\" a pour arguments :\n");
    for (int i=1; i<argc; i++)
    printf("Argument %i : %s \n", i, argv[i]);
    return 0;
}