#include <iostream>
using namespace std;

int fibrecursive(int n) {

    if(n <= 1)
       return n;
    
    return fibrecursive(n-1) + fibrecursive(n-2);

}

int fibiterative(int n) {

    if(n <= 1)
       return n;
    
    int s = 0;
    int t0 = 0;
    int t1 = 1;

    printf("%d ", 1);
    for(int i = 2; i<=n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;

        printf("%d ", s);

    }

    printf("\n");
    return s;
}

int F[10];

int fibmemoization(int n) {

    if(n <= 1) {

        F[n] = n;
        return n;

    }
    else {

        if(F[n-2] == -1)
            F[n-2] = fibmemoization(n-2);
        if(F[n-1] == -1)
            F[n-1] = fibmemoization(n-1);

        return F[n-2] + F[n-1];
    }

}

int main() {

    int a = fibrecursive(6);
    int b = fibiterative(6);

    for(int i = 0; i<10; i++)
        F[i] = -1;

    int c = fibmemoization(6);
    printf("%d %d %d \n", a, b, c);

    return 0;
}
