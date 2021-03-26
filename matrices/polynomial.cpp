#include <iostream>
using namespace std;


class Term {

    public:
        int coeff;
        int exp;
};

class Polynomial {

    public:
        int n;
        Term *t;

        Polynomial() {

        }

        Polynomial(int n) {

            this -> n = n;
            t = new Term[this->n];
        }

        ~Polynomial() {

            delete []t;
        }

        void create();
        void display();

        Polynomial sum(Polynomial &p1);
};

void Polynomial::create() {

    cout << "Enter Terms" << endl;
    
    for(int i = 0; i < n; i++)
        cin >> t[i].coeff >> t[i].exp;

}

void Polynomial::display() {

    cout << "Polynomial" << endl;

    for(int i = 0; i < n; i++) {

        if(t[i].exp != 0)
            cout << t[i].coeff << "x" << t[i].exp;
        else
            cout << t[i].coeff;

        if(i < n - 1)
            cout << "+";
    }

    cout << endl;
}

Polynomial Polynomial::sum(Polynomial &p1) {

    int i = 0, j = 0, k = 0;

    Polynomial sum(n + p1.n);

    while(i < n && j < p1.n) {

        if(t[i].exp > p1.t[j].exp)
            sum.t[k++] = t[i++];
        
        else if(t[i].exp < p1.t[j].exp)
            sum.t[k++] = p1.t[j++];

        else{

            sum.t[k].exp = t[i].exp;
            sum.t[k++].coeff = t[i++].coeff + p1.t[j++].coeff; 
        }
    }   

    for(; i < n; i++)
        sum.t[k++] = t[i];
    
    for(; j < p1.n; j++)
        sum.t[k++] = p1.t[j];

    sum.n = k;

    return sum;
}

int main() {

    int n;
    cout << "Enter Number of Terms" << endl;
    cin >> n;

    Polynomial p(n);

    p.create();
    p.display();

    cout << "Enter Number of Terms" << endl;
    cin >> n;
    Polynomial p1(n);

    p1.create();
    p1.display();

    Polynomial sum = p.sum(p1);
    sum.display();

    return 0;
}