#include <iostream>

using namespace std;



class LinearProbing{

public:
	int *HT;
    int size;

	LinearProbing(int size);
   // ~LinearProbing();

	int hash(int key);
    int probe(int key);
	void insert(int key);
	int search(int key);

    void print();
	
};

LinearProbing::LinearProbing(int size) {
	
    this->size = size;
    this->HT = new int[size];
	for (int i=0; i<size; i++){
		HT[i] = 0;
	}
}


int LinearProbing::hash(int key) {
    return key % size;
}

int LinearProbing::probe(int key) {

    int idx = hash(key);
    int i=0;
    while(HT[(idx + i) % size] != 0)
        i++;

    return (idx + i) % size;
}

void LinearProbing::insert(int key) {

    int idx = hash(key);
    if(HT[idx] != 0) 
        idx = probe(key);
    
    HT[idx] = key;
}


int LinearProbing::search(int key) {

    int idx = hash(key);
    int i=0;
    while(HT[(idx + i) % size] != key && HT[(idx + i) % size] != 0)
        i++;

    if(HT[(idx + i) % size] == key)
        return (idx+i)%size;
    else
        return 0;
}


void LinearProbing::print() {

    cout << size << endl;
    for(int i=0; i<size; i++)
        cout << HT[i] << " ";

    cout << endl;
}


int main() {

    int H[] = {0};

    LinearProbing lp(10);
    lp.insert(12);
    lp.insert(25);
    lp.insert(30);
    lp.insert(35);

    lp.print();

    cout << "Search Result: " << lp.search(55) << endl;

    return 0;
}