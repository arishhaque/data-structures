#include <iostream>
using namespace std;

int factorial(int n) {

    if(n == 0)
       return 1;
       
    return factorial(n-1) * n;

}

int main() {

    int a = factorial(5);
    printf("%d\n", a);
    
    return 0;
}
