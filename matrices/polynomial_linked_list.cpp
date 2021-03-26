#include <iostream>
using namespace std;

class PlynomialNode {

    public:
        int coeff;
        int exp;
        PlynomialNode *next;

    PlynomialNode() {

    }

    void create();
    void display();
    
    long evaluate(int x);

} *pn = NULL;

void PlynomialNode::create() {

    PlynomialNode *temp, *last;
    int num, i;
    cout << "Enter number of terms" << endl;
    cin >> num;

    cout << "Enter each term with coefficient and exponent" << endl;
    for(i = 0; i < num; i++) {

        temp = new PlynomialNode();
        cin >> temp -> coeff >> temp -> exp;

        temp->next = NULL;
        if(pn == NULL) {

            pn = last = temp;

        } else {

            last -> next = temp;
            last = temp; 
        }   
    }
}

void PlynomialNode::display() {
    
    cout << "Polynomial" << endl;
    PlynomialNode *temp = pn;
    while(temp != NULL ) {

        cout << temp -> coeff;
        if(temp -> exp != 0) {
            
            cout <<"x" << temp -> exp;
            cout << "+";
        }
        temp = temp -> next;
    }
    cout << endl;
}

long PlynomialNode::evaluate(int x) {

    long val = 0;

    PlynomialNode *temp = pn;
    while (temp != NULL) {
        
        val += temp -> coeff * pow(x, temp -> exp);
        temp = temp -> next;

    }
    return val;
}

int main() {

    pn->create();
    pn->display();

    cout << "Evaluated Polynomial = " << pn -> evaluate(2);
    
    return 0;
}



