#include <iostream>
#include <queue>
using namespace std;

class BFS {

    public:

        void bfs(int A[][7], int start, int n);
};


void BFS::bfs(int A[][7], int start, int n) {

    int i = start;
    int visited[7] = {0};

    cout << i << " ";
    visited[i] = 1;

    queue<int> q;
    q.push(i);
    while (!q.empty())
    {
        i = q.front();
        q.pop();
        for(int j = 1; j < n; j++) {

            if(A[i][j] == 1 && visited[j] == 0) {
                cout << j << " ";
                visited[j] = 1;
                q.push(j);
            }
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

    BFS b;
    b.bfs(A, 4, 7);
    
    return 0;

}