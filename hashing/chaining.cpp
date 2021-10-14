#include <iostream>

using namespace std;


// Linked List node
class Node{

public:
	int data;
	Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Hash Table
class HashTable{

public:
	Node** HT;

	HashTable();
    ~HashTable();

	int hash(int key);
	void Insert(int key);
	int Search(int key);
	
};

HashTable::HashTable() {
	HT = new Node* [10];
	for (int i=0; i<10; i++){
		HT[i] = nullptr;
	}
}

HashTable::~HashTable() {

	for (int i=0; i<10; i++) {

		Node *p = HT[i];
		while (HT[i]){
			HT[i] = HT[i]->next;
			delete p;
			p = HT[i];
		}
	}
	delete []HT;
}

int HashTable::hash(int key) {
	return key % 10;
}

void HashTable::Insert(int key) {

	int hIdx = hash(key);
	Node *t = new Node(key);

	// Case: No nodes in the linked list
	if (HT[hIdx] == nullptr){
		HT[hIdx] = t;

	} else {

		Node *p = HT[hIdx];
		Node *q = nullptr;

		// Traverse to find insert position
		while (p && p->data < key){
			q = p;
			p = p->next;
		}
		// Case: insert position is first
		if (q == nullptr){
			t->next = HT[hIdx];
			HT[hIdx] = t;
		} else {
			t->next = q->next;
			q->next = t;
		}
	}
}

int HashTable::Search(int key) {

	int hIdx = hash(key);
	Node *p = HT[hIdx];

	while(p) {
		if (p->data == key){
			return p->data;
		}
		p = p->next;
	}
	return -1;
}


int main() {

	int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int n = sizeof(A)/sizeof(A[0]);

	HashTable H;
	for (int i=0; i<n; i++){
		H.Insert(A[i]);
	}
	cout << "Successful Search" << endl;
	int key = 122;
	int value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;

	cout << "Unsuccessful Search" << endl;
	key = 95;
	value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;

	return 0;
}