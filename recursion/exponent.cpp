#include <iostream>
using namespace std;

int power(int m, int n) {

    if(n == 0)
       return 1;
       
    return power(m,n-1) * m;

}

int pow(int m, int n) {

    if(n == 0)
       return 1;
    
    if(n % 2 == 0)
        return pow(m*m, n/2);
    else
        return m * pow(m*m,(n-1)/2);

}

int main() {

    int a = power(2,9);
    int b = pow(2,9);
    printf("%d %d\n", a, b);
    
    return 0;
}
