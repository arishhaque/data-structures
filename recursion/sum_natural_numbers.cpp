#include <iostream>
using namespace std;

int sum(int n) {

    if(n == 0)
       return 0;
       
    return sum(n-1) + n;

}

int main() {

    int a = sum(5);
    printf("%d\n", a);
    
    return 0;
}
