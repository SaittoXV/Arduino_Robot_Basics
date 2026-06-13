#include <stdio.h>

void first() {
    printf("This is First\n");
}

void second() {
    printf("This is Second\n");
}

void (*actions[])() = { first, second };
const int action_count = sizeof(actions) / sizeof(actions[0]);

int main(void) {
    printf("Hello World\n");
    printf("Action Count: %d\n",action_count);
    for(int x=0;x<action_count;x++)
    {
        actions[x]();   // call the function pointer
    }
    return 0;
}

