#include <iostream>
#include <cstring>

using namespace std;

class Complex{
    int size;
    char* pointer;

    public:
        Complex(char* ch){
            int size = strlen(ch);
            pointer = new char[size+1];
            strcpy(pointer,ch);
        }
        Complex(){}
        Complex& operator=(Complex&);
        void show();
        ~Complex(){
            delete[] pointer;
            cout<<"Destructor called " <<endl;
        }
};
Complex& Complex::operator=(Complex& a){
    delete[] pointer;

    size = a.size;
    pointer = new char[size+1];
    strcpy(pointer,a.pointer);
    return *this;

}
void Complex::show(){
    cout<<" name is " << pointer << endl;
}
int main(){
    Complex c("Yogesh");
    {
        Complex c1;
        c1=c;
        c1.show();
    }
    c.show();

    return 0;
}
