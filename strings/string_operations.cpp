#include <iostream>

using namespace std;

class StringOp {

    private:
        char *A;
        int n;

    public:

        StringOp() {

            A = new char[10];
        }

        StringOp(int n) {

           this -> n = n;
           A = new char[n];

        }

        StringOp(int n, char *B) {

           this -> n = n;
           A = new char[n];
           A = B;

        }

        int get_length();
        void display();

        int num_of_vowels();
        int num_of_words();

        void validate();
        void compare(char *B);
        void reverse();

        void find_duplicates();

        void anagram(char *B);

};

int StringOp::get_length() {

    int count  = 0;
    for(int i = 0; A[i] != '\0'; i++) {
        count++;
    }
    return count;
}

void StringOp::display() {

    cout << "\n";
    for(int i = 0; A[i] != '\0'; i++) {
        cout << A[i];
    }
    cout << "\n";
}

int StringOp::num_of_vowels() {

    int count  = 0;
    for(int i = 0; A[i] != '\0'; i++) {
        
        if((A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u')
            || (A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U'))
            count++;
    }
    return count;
}

int StringOp::num_of_words() {

    int count  = 1;
    for(int i = 0; A[i] != '\0'; i++) {
        
        if(A[i] == ' ' && A[i-1] != ' ')
            count++;
    }
    return count;
}

void StringOp::validate() {

    int i;
    for(i = 0; A[i] != '\0'; i++) {

        if(!(A[i] >= 65 && A[i] <= 90) 
                && !(A[i] >= 97 && A[i] <= 122)
                && !(A[i] >= 48 && A[i] <= 57)
                && !(A[i] == 32)) {

            cout << "Invalid String" << "\n";
            break;
        }
    }

    if(A[i] == '\0')
        cout << "Valid String" << "\n";
}

void StringOp::compare(char *B) {

    int i, j;

    for(i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++){

        if(A[i] != B[j])
            break;
    }

    cout << "\n";
    if(A[i] == B[j])
        cout << "Strings are Equal";
    else if(A[i] > B[j])
        cout << "Given String is smaller";
    else
        cout << "Given String is greater";

    cout << "\n";

}

void StringOp::reverse() {

    int i,j = 0;
    for(i = 0; A[i] != '\0'; i++)
        j++;

    j = j - 1 ;
    for(i = 0; i < j; i++, j--) {

        int t = A[i];
        cout << A[i];
        cout << A[j];
        A[i] = (char) A[j];
        A[j] = t;
    }
}

 void StringOp::find_duplicates() {

    int i, H[26] = {0};

    for(i = 0; A[i] != '\0'; i++)
        H[A[i] - 97] += 1;

    for(i = 0; i < 26; i++) {

        if(H[i] > 1){

            cout << "Duplicate Character: " << (char)(i + 97) << " ";
            cout << "Frequency: " << H[i] << "\n";
        }
    }
 }

 void StringOp::anagram(char *B) {

    int i, H[26] = {0};

    for(i = 0; A[i] != '\0'; i++)
        H[A[i] - 97] += 1;
    
    for(i = 0; B[i] != '\0'; i++) {

        H[A[i] - 97] -= 1;

        if(H[A[i] - 97] < 0) {

            cout << "Not Anagram";
            break;
        }
    }

    if(B[i] == '\0')
        cout << "Anagram";

 }

int main() {

    StringOp sp(5, (char *) "how");

    sp.validate();
    cout << sp.get_length();
    
    sp.display();

    cout << "Number of Vowels: " << sp.num_of_vowels();
    cout << "\n";
    cout <<  "Number of Words: " << sp.num_of_words();

    sp.reverse();
    sp.compare("arish");

    sp.find_duplicates();

    sp.anagram("who");
    sp.display();
    
}