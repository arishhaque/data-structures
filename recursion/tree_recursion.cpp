#include <iostream>
using namespace std;

int fun(int n) {

    
    if(n > 0){

       printf("%d ", n);
       fun(n-1);
       fun(n-1);
    }
    return 0;

}

int main() {

    fun(3);

    //printf("%d\n", a);
    return 0;
}
