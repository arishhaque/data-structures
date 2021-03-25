#include <iostream>
using namespace std;

double taylor(int x, int n) {

    if(n == 0)
       return 1;
    
    static double p=1, f=1;
    double r = 1;
    
    r = taylor(x, n-1);
    p = p * x;
    f = f * n;

    return r + p/f;
}

double taylorhorner(int x, int n) {

    static double s;
    if(n == 0)
       return s;
    
    s = 1 + x * s/n;

    return taylorhorner(x, n - 1);
}


double tayloriterative(int x, int n) {

    double s = 1;
    double num = 1;
    double den = 1;
    int i;
    for(i = 1; i <= n; i++){
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

int main() {

    double a = taylor(3, 10);
    double b = taylorhorner(3, 10);
    double c = tayloriterative(3, 10);
    printf("%f %f %f\n", a, b, c);

    return 0;
}
