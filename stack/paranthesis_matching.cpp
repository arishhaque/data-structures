#include <iostream>
#include "stack.h"


using namespace std;
class stack;

class ParanthesisMatching {

    private:
        //Stack stk;
        int A[];
        

    public:
        int isBalanced(char *exp);
    
};


int ParanthesisMatching::isBalanced(char *exp) {

    stack *stk = new stack();
    for (int i=0; i < strlen(exp); i++){
        if (exp[i] == '('){
            stk->push(exp[i]);
        } else if (exp[i] == ')'){
            if (stk->isEmpty()){
                return false;
            } else {
                stk->pop();
            }
        }
    }
    return stk->isEmpty() ? true : false;
}


int main() {
 
    ParanthesisMatching pm;

    char E[] = "((a+b)*(c-d))";
    cout << pm.isBalanced(E) << endl;
 
    char F[] = "((a+b)*(c-d)))";
    cout << pm.isBalanced(F) << endl;
 
    char G[] = "(((a+b)*(c-d))";
    cout << pm.isBalanced(G) << endl;
 
    return 0;
 
}