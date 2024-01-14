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

int main(int argc, char **argv){
    int base_len = 5;
    char arr1[base_len];
    char* arr2 = map(arr1, base_len, my_get);
    char* arr3 = map(arr2, base_len, cprt);
    char* arr4 = map(arr3, base_len, xprt);
    char* arr5 = map(arr4, base_len, encrypt);
    free(arr2);
    free(arr3);
    free(arr4);
    free(arr5);
}
