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

class BST {

    public:
        Node *root;
    
    BST(){
        root = NULL;
    }

    void insert(int key);

    Node * insertRec(Node *p, int key);

    void inorder(Node *p);

    Node * search(int key);

    Node * deleteNode(Node *p, int key);

    int height(Node *p);
};

Node * BST::insertRec(Node *p, int key) {

    if(p == NULL) {

        Node *t = new Node(key);
        if(root == NULL)
            root = t;

        return t;
    }
        
    if(key < p->data) 
        p->left = insertRec(p->left, key);
        
    else if(key > p->data)
        p->right = insertRec(p->right, key);

    return p;

}

void BST::insert(int key) {

    Node *p, *q;

    if(root == NULL) {

        root = new Node(key);
        return;
    }

    Node *temp = root;
    while(temp != NULL) {

        q = temp;
        if(key < temp -> data)
            temp = temp -> left;

        else if(key > temp -> data)
            temp = temp -> right;

        else
            return;
    }

    p = new Node(key);
    if(key < q->data)
        q->left = p;
    else
        q->right = p;
}

void BST::inorder(Node *p) {

    if(p == NULL)
        return;

    inorder(p->left);
    cout << p->data << " ";
    inorder(p->right);

}

Node * BST::search(int key) {

    Node *p = root;

    while(p != NULL) {

        if(key == p->data)
            return p;
        
        else if(key < p->data)
            p = p->left;
        
        else
            p = p->right;
    }

    return NULL;
}

// find inorder predecessor
Node* InPre(Node *p) {

    while(p != NULL && p->right != NULL)
        p = p->right;

    return p;

}

// find inorder successor
Node* InSucc(Node *p) {

    while(p != NULL && p->left != NULL)
        p = p->left;

    return p;

}

Node * BST::deleteNode(Node *p, int key) {

    if(p == NULL)
        return NULL;

    if(p->left == NULL && p->right == NULL) {   // if the deleted node does not has any of the child
        
        if(p == root)
            root = NULL;
        
        free(p);
        return NULL;
    }

    Node *q;
    if(key < p->data)
        p->left = deleteNode(p->left, key);
        
    else if(key > p->data)
        p->right = deleteNode(p->right, key);
    
    else {                                               // key is found

        if(height(p->left) > height(p->right)) {        

            q = InPre(p->left);                         // find Inorder Predecessor in the left sub tree
            p->data = q->data;
            p->left = deleteNode(p->left, q->data);     // Delete the Inorder Predecessor Node

        } else {                                        

            q = InSucc(p->right);                       // find Inorder Successor in the right sub tree
            p->data = q->data;
            p->right = deleteNode(p->right, q->data);   // Delete the Inorder Successor Node

        }
    }
    return p;
}

int BST::height(Node *p) {
    
    int l = 0;
    int r = 0;
    if (p == nullptr){
        return 0;
    }
 
    l = height(p->left);
    r = height(p->right);
 
    return l > r ? l + 1 : r + 1;
}



int main() {

    BST bst;

    /*t.insert(10);
    t.insert(5);
    t.insert(20);
    t.insert(8);
    t.insert(30);
    */

    bst.insertRec(bst.root, 10);
    bst.insertRec(bst.root, 5);
    bst.insertRec(bst.root, 20);
    bst.insertRec(bst.root, 8);
    bst.insertRec(bst.root, 30);

    bst.inorder(bst.root);
    cout << endl;

    Node * p = bst.search(20);
    if(p != NULL)
        cout << "Element Found " << p->data << endl;
    else
        cout << "Element Not Found" << endl;


    cout << "Delete Node: 10 " << endl;
    bst.deleteNode(bst.root, 10);
    bst.inorder(bst.root);
    cout << endl;
}

