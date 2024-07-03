#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned int seed = 9;
    int man = rand_r(&seed);

    printf("%d\n", man);
}