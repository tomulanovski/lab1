#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* map(char *array, int array_length, char (*f) (char)){
    char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
    /* TODO: Complete during task 2.a */
    for (int i = 0; i < array_length; i++) {
        mapped_array[i] = f(array[i]);
    }
/* need to free memory */
    return mapped_array;
}
char xprt(char c) {
    printf("%x\n", c);
    return c;
}
char my_get(char c){
    char input =  (char) fgetc(stdin);
    return input;
}
char cprt(char c){
    if (c >= 0x20 && c <= 0x7E) {
        printf("%c\n", c);
    }
    else {
        printf(".\n");
    }
    return c;
}
char encrypt(char c){
    if (c >= 0x20 && c <= 0x7E) {
        return (c+1);
    }
    else return c;
}
char decrypt(char c) {
    if (c >= 0x20 && c <= 0x7E) {
        return c-1;
    }
    else return c;
}
struct fun_desc {
    char *name;
    char (*fun)(char);
};

void MenuLoop(){
    char* carray = (char*)(malloc(5*sizeof(char)));
    char input[10];
    struct fun_desc menu[] = {
            {"Get string", &my_get},
            {"Print string", &cprt},
            {"Print Hex", &xprt},
            {"Encrypt", &encrypt},
            {"Decrypt", &decrypt},
            {NULL,NULL}
    };
    int bound = sizeof(menu) / (sizeof(menu[0]))-1;
    int opChosen;
    while (1) {
        printf("Select operation from the following menu or press Control D for exit:\n");
        for (int i = 0; menu[i].name != NULL; i++) {
            printf("%d- %s\n", i, menu[i].name);
        }
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Exit the loop on EOF
            printf("Exiting\n");
            exit(1);
        }
        sscanf(input,"%d",&opChosen);
        if (opChosen>-1 && opChosen<bound) {
            printf("Within bounds\n");
            char *tmp = map(carray, 5, menu[opChosen].fun);
            free(carray);
            carray = tmp;
            printf("DONE.\n");
        }
        else {
            printf ("Not within bounds\nExiting\n");
            exit(1);
        }


    }
}
int main(int argc, char **argv)
{
    MenuLoop();
    return 0;
}
