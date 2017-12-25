#include <stdio.h>

int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    printf("fibonacci(0) %d\n", fib(0));
    printf("fibonacci(8) %d\n", fib(8));
    printf("fibonacci(10) %d\n", fib(10));
    return 0;
}
