#include <iostream>
#include <queue>
using namespace std;

class Node {

    public:
        int data;
        Node *left;
        Node *right;

    Node(int data) {

        this -> data = data;
        left = right = NULL;

    }  
};

class Tree {

    public:

        Node *root;

        Tree(){
            root = NULL;
        }

        Node* createTree();
        
        int Height(Node *p);

        int countNodes(Node *p);

};

Node* Tree::createTree() {

    Node *temp, *p;
    queue<Node*> q;
    
    int x;
    cout << "Enter root value ";
    cin >> x;

    root = new Node(x);
    
    q.push(root);
    while (!q.empty()) {

        p = q.front();
        q.pop();
    
        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
       if (x > 0){

            temp = new Node(x);
            p->left = temp;
            q.push(temp);
        }
 
        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x > 0){
            
            temp = new Node(x);
            p->right = temp;
            q.push(temp);
        }
    }

    return root;
}


int Tree::Height(Node *p) {
    
    int l = 0;
    int r = 0;
    if (p == nullptr){
        return 0;
    }
 
    l = Height(p->left);
    r = Height(p->right);
 
    if (l > r) {
        return l + 1;
    } else {
        return r + 1;
    }
}

int Tree::countNodes(Node *p) {

    if(p != NULL)
        return countNodes(p->left) + countNodes(p->right) + 1;
    
    return 0;
}


int main() {

    Tree t; // 8,3,5,4,9,7,2

    t.createTree(); 

    cout << "Height: " << t.Height(t.root) << endl;

    cout << "Num of Nodes: " << t.countNodes(t.root) << endl;

}
