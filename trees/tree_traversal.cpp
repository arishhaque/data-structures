#include <iostream>
#include "tree.cpp"
#include <queue>
#include <stack>

using namespace std;

class TreeTraversal {


    public:

        void preorder(Node *p);
        void iPreorder(Node *p);

        void inorder(Node *p);
        void iInorder(Node *p);
        
        void postorder(Node *p);
        void iPostorder(Node *p);
        
        void levelorder(Node *p);
};


void TreeTraversal::preorder(Node *p) {

    if(p == NULL)
        return;

    cout << p -> data << " ";
    preorder(p -> left);
    preorder(p -> right);
}

void TreeTraversal::iPreorder(Node *p) {

    stack<Node*> stk;
    while(p != NULL || !stk.empty()) {

        if(p != NULL) {

            cout << p->data << " ";
            stk.push(p);
            p = p->left;
        
        } else {

            p = stk.top();
            stk.pop();
            p = p->right;
        }
    }  
}


void TreeTraversal::inorder(Node *p) {

    if(p == NULL) 
        return;

    inorder(p -> left);  
    cout << p -> data << " ";
    inorder(p -> right);
}

void TreeTraversal::iInorder(Node *p) {

    stack<Node*> stk;
    while(p != NULL || !stk.empty()) {

        if(p != NULL) {

            stk.push(p);
            p = p->left;
        
        } else {

            p = stk.top();
            stk.pop();
            cout << p->data << " ";
            p = p->right;
        }
    }
}


void TreeTraversal::postorder(Node *p) {

    if(p == NULL)
        return;
    
    postorder(p -> left);
    postorder(p -> right);
    cout << p -> data << " ";
}

void TreeTraversal::iPostorder(Node *p) {

    stack<Node*> stk;
    while(p != NULL || !stk.empty()) {

        if(p != NULL) {

            stk.push(p);
            p = p->left;
        
        } else {

            p = stk.top();
            stk.pop();
            if(p->data > 0) {
                p->data = -1 * (p->data);
                stk.push(p);
                p = p->right;
            } else {

                p->data = -1 * p->data;
                cout << (p->data) << " ";
                p = NULL;
            } 
        }
    }
}


void TreeTraversal::levelorder(Node *p) {

    queue<Node*> q;
    cout << p->data << " " << flush;
    q.push(p);
 
    while (!q.empty()){

        p = q.front();
        q.pop();
 
        if (p->left){
            cout << p->left->data << " " << flush;
            q.push(p->left);
        }
 
        if (p->right){
            cout << p->right->data << " " << flush;
            q.push(p->right);
        }
    }
}


int main() {


    Tree t;
    Node *p = t.createTree();       // 8,3,5,4,9,7,2

    TreeTraversal tt;

    cout << "PreOrder: ";
    tt.preorder(p);
    cout << endl;

    cout << "Iterative PreOrder: ";
    tt.iPreorder(p);
    cout << endl;

    cout << "InOrder: ";
    tt.inorder(p);
    cout << endl;

    cout << "Iterative InOrder: ";
    tt.iInorder(p);
    cout << endl;

    cout << "PostOrder: ";
    tt.postorder(p);
    cout << endl;

    cout << "Iterative PostOrder: ";
    tt.iPostorder(p);
    cout << endl;

    cout << "LevelOrder: ";
    tt.levelorder(p);
    cout << endl; 

    

    return 0;
}


