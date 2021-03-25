#include <iostream>
using namespace std;

int factorial(int n) {

   if(n == 0)
       return 1;

    return factorial(n - 1) * n;    
}

int nCr(int n, int r) {

    if(n == r || r == 0)
       return 1;
    
    int num = factorial(n);
    int den = factorial(r) * factorial(n - r);
    
    return num/den;
}

int nCrRecursive(int n, int r) {

    if(n == r || r == 0)
       return 1;
    
    return nCrRecursive(n - 1, r - 1) + nCrRecursive(n - 1, r);
}

int main() {

    int a = factorial(5);
    int b = nCr(5,2);
    int c = nCrRecursive(5, 2);
    printf("%d %d %d\n", a, b, c);

    return 0;
}
