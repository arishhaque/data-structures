#include <iostream>

using namespace std;


void dfs(int A[][7], int start, int n) {

    static int visited[7] = {0};

    int i = start;
    if(visited[i] == 0) {

        cout << i << " ";
        visited[i] = 1;
        for(int j = 1; j < n; j++) {

            if(A[i][j] == 1 && visited[j] == 0)
                dfs(A, j, n);

        }      
    }
}

int main() {

     int A[7][7]={{0,0,0,0,0,0,0},
             {0,0,1,1,0,0,0},
             {0,1,0,0,1,0,0},
             {0,1,0,0,1,0,0},
             {0,0,1,1,0,1,1},
             {0,0,0,0,1,0,0},
             {0,0,0,0,1,0,0}};

    
    dfs(A, 1, 7);
    
    return 0;
}