#include <stdio.h>

void greet();

int main() {
    printf("Hello, World!\n");
    printf("add printf");
    printf("change the main file");
    greet();
    return 0;
}


void greet(){
    printf("Hello, user!");
}