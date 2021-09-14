#include <iostream>
#include <queue>

using namespace std;

class Node {

    public:
        int data;
        int height;
        Node *left;
        Node *right;

    Node(int data) {

        this->data = data;
        this->height = 1;
        left = right = NULL;

    }
};

class AvlTree {

    public:
        Node *root;

        AvlTree() {

            root = NULL;
        }

        int height(Node *p);
        int balanceFactor(Node *p);

        void inorder(Node *p);
        Node* inorderPredecessor(Node *p);
        Node* inorderSuccessor(Node *p);

        Node * insertRec(Node *p, int key);
        Node* deleteNode(Node* p, int key);

        Node* LLRotation(Node* p);
        Node* RRRotation(Node* p);
        Node* LRRotation(Node* p);
        Node* RLRotation(Node* p);
};

void AvlTree::inorder(Node *p) {

    if(p == NULL)
        return;

    inorder(p->left);
    cout << p->data << " ";
    inorder(p->right);

}

// right most child in the left subtree
Node* AvlTree::inorderPredecessor(Node *p) {
    while (p && p->right != nullptr){
        p = p->right;
    }
    return p;
}

// left most child in the right subtree
Node* AvlTree::inorderSuccessor(Node *p) {
    while (p && p->left != nullptr){
        p = p->left;
    }
    return p;
}


int AvlTree::height(Node *p) {
    
    int l = 0;
    int r = 0;
    if (p == nullptr){
        return 0;
    }
 
    l = height(p->left);
    r = height(p->right);
 
    return l > r ? l + 1 : r + 1;
}


int AvlTree::balanceFactor(Node *p) {
    
    int l = 0;
    int r = 0;
    if (p == nullptr){
        return 0;
    }
 
    l = height(p->left);
    r = height(p->right);
 
    return l - r;
}


Node * AvlTree::insertRec(Node *p, int key) {

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


    // update height
    p->height = height(p);

     // Balance Factor and Rotation
    if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1) {
        cout << "LL" << endl;
        return LLRotation(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1){
         cout << "LR" << endl;
        return LRRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1){
         cout << "RR" << endl;
        return RRRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1){
         cout << "RL" << endl;
        return RLRotation(p);
    }

    return p;
}


 Node* AvlTree::deleteNode(Node* p, int key) {

     if (p == nullptr) {
        return nullptr;
    }
 
    if (p->left == nullptr && p->right == nullptr) {

        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
 
    if (key < p->data){
        p->left = deleteNode(p->left, key);

    } else if (key > p->data){
        p->right = deleteNode(p->right, key);

    } else {

        Node* q;
        if (height(p->left) > height(p->right)){
            q = inorderPredecessor(p->left);
            p->data = q->data;
            p->left = deleteNode(p->left, q->data);
        } else {
            q = inorderSuccessor(p->right);
            p->data = q->data;
            p->right = deleteNode(p->right, q->data);
        }
    }
 
    // Update height
    p->height = height(p);
 
    // Balance Factor and Rotation
    if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1){  // L-1 Rotation
        return LRRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->left) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 0){  // R0 Rotation
        return RRRotation(p);
    }
    return p;
 }

Node* AvlTree::LLRotation(Node* p) {

    Node *pl = p->left;
    Node *plr = pl->right;

    pl->right = p;
    p->left = plr;

    p->height = height(p);
    pl->height = height(pl);

    if(root == p)
        root = pl;

    return root;
}

Node* AvlTree::RRRotation(Node *p) {

    Node* pr = p->right;
    Node* prl = pr->left;
 
    pr->left = p;
    p->right = prl;
 
    // Update height
    p->height = height(p);
    pr->height = height(pr);
 
    // Update root
    if (root == p)
        root = pr;
    
    return root;
}
 
Node* AvlTree::LRRotation(Node *p) {

    Node *pl = p->left;
    Node *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    p->height = height(p);
    pl->height = height(pl);
    plr->height = height(plr);

    if(root == p)
        root = plr;

    return root;
}
 
Node* AvlTree::RLRotation(Node *p) {
    
    Node* pr = p->right;
    Node* prl = pr->left;
 
    pr->left = prl->right;
    p->right = prl->left;
 
    prl->right = pr;
    prl->left = p;
 
    // Update height
    pr->height = height(pr);
    p->height = height(p);
    prl->height = height(prl);
 
    // Update root
    if (root == p){
        root = prl;
    }
    return prl;
}


int main() {

    AvlTree avlLL;

    avlLL.root = avlLL.insertRec(avlLL.root, 10);
    avlLL.root = avlLL.insertRec(avlLL.root, 5);
    avlLL.root = avlLL.insertRec(avlLL.root, 2);

    cout << "LL Rotation" << endl;
    avlLL.inorder(avlLL.root);
    cout << endl;


    // RR Rotation
    AvlTree avlRR;

    avlRR.root = avlRR.insertRec(avlRR.root, 10);
    avlRR.root = avlRR.insertRec(avlRR.root, 20);
    avlRR.root = avlRR.insertRec(avlRR.root, 30);
 
    cout << "RR Rotation" << endl;
    avlRR.inorder(avlRR.root);
    cout << endl;


    // LR Rotation
    AvlTree avlLR;

    avlLR.root = avlLR.insertRec(avlLR.root, 50);
    avlLR.root = avlLR.insertRec(avlLR.root, 10);
    avlLR.root = avlLR.insertRec(avlLR.root, 20);
 
    cout << "LR Rotation" << endl;
    avlLR.inorder(avlLR.root);
    cout << endl;

    AvlTree tree;
 cout << "Delete Node: 28 1" << endl;
    int A[] = {10, 20, 30, 25, 28, 27, 5};
    tree.root = tree.insertRec(tree.root, A[0]);
    for (int i=1; i<sizeof(A)/sizeof(A[0]); i++){
        tree.insertRec(tree.root, A[i]);
    }
 
    //tree.inorder(tree.root);
    cout << "Delete Node: 28" << endl;
 
    tree.deleteNode(tree.root, 28);
   
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}