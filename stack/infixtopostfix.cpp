#include <iostream>
#include "stack.cpp"


using namespace std;


class InfixToPostfix {


    public:
        int getPrecedence(char x);
        int isOperand(char x);
        char* convert(char *infix);
        int evaluate(const char *postfix);

};

int InfixToPostfix::getPrecedence(char x) {

    if(x == '+' || x == '-')
        return 1;
    
    else if(x == '*' || x == '/')
        return 2;

    return 0;
}

int InfixToPostfix::isOperand(char x) {

    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;

}

char* InfixToPostfix::convert(char *infix) {

    int len = strlen(infix);
    char *postfix;

    postfix = (char *) malloc((len + 2) * sizeof(char));

    stack *stk = new stack();
    
    int i = 0, j = 0;
    while(infix[i] != '\0'){

        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        
        else {

            if((getPrecedence(infix[i]) > getPrecedence(stk->stackTop())))
                stk->push(infix[i++]);
            
            else
                postfix[j++] = stk->pop();
        }
    }

    while(!stk->isEmpty())
        postfix[j++] = stk->pop();

    postfix[j] = '\0';
    return postfix;
}

int InfixToPostfix::evaluate(const char *postfix) {

    int op1, op2, res;
    stack *stk = new stack();
    for(int i = 0; postfix[i] != '\0'; i++) {
        if(isOperand(postfix[i]))
            stk->push(postfix[i] - '0');

        else {

            op2 = stk->pop();
            op1 = stk->pop();
            
            switch (postfix[i]) {

                case '+':
                    res = op1 + op2;
                    stk->push(res);
                    break;
                
                case '-':
                    res = op1 - op2;
                    stk->push(res);
                    break;
                
                case '*':
                    res = op1 * op2;
                    stk->push(res);
                    break;
                
                case '/':
                    res = op1 / op2;
                    stk->push(res);
                    break;
                
                default:
                    break;
            }
        }
    }

    return stk->pop();
}


int main() {

    InfixToPostfix ip;

    //a+b*c-d/e
    char *infix = (char *)"2+3*4-8/2";

    char *postfix = (char *)ip.convert(infix);

    cout << "Infix to Postfix: " << postfix << endl;

    //2+3*4-8/2 = 10
    const char *exp = "234*+82/-";
    int res = ip.evaluate(exp);

    cout << "Evaluate: " << res;
    return 0;
}