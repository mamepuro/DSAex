#include <stdio.h>
#include <stdlib.h>
int euclid(int, int);

int main(int argc, char *argv[]) {
    // Process arguments.
    if (argc != 3) {
    fprintf(stderr, "Usage: %s <number1> <number2>\n", argv[0]);
    return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    // Find the greatest common divisor.
    int gcd = euclid(n, m);
    printf("The GCD of %d and %d is %d.\n", n, m, gcd);

    return EXIT_SUCCESS;
}