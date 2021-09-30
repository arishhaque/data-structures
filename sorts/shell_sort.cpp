#include <iostream>

using namespace std;

void shellSort(int A[], int n) {

    int i,j,gap;
    for(gap=n/2; gap>=1; gap/=2) {

        for(j=gap; j<n; j++) {

            int tmp = A[j];
            i = j-gap;
            while(i>=0 && A[i] > tmp) {

                A[i+gap] = A[i];
                i=i-gap;
            }
            A[i+gap] = tmp;
        }
    }
}


int main() {

    int A[] = {13, 9, 7, 10, 16, 5, 3, 4, 8, 6};
    int n = sizeof(A)/sizeof(A[0]);

    cout<< "Shell Sort:" << endl;
    shellSort(A, n);

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    
    cout << endl;

    return 0;
}