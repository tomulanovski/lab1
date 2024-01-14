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
    return (char) fgetc(stdin);
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
        printf("Select operation from the following menu:\n");
        for (int i = 0; menu[i].name != NULL; i++) {
            printf("%d) %s\n", i, menu[i].name);
        }
    }
}
int main(int argc, char **argv)
{
    MenuLoop();
    return 0;
}
