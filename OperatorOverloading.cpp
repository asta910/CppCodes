//operator overloading - 
//same for Multiply,Divide,Sub,Modulo all
#include <iostream>
using namespace std;
class A{
    int real;
    int img;

    public:
    A(){}
    A(int a,int b) : real(a), img(b){}
    void show(){    cout<<"Number is : " <<real <<" + "<<img<<"i"<<endl;}

    //pre- increment
    A operator++(){
        ++this -> real;
        ++this-> img;
        return *this;
    }

    //post increment - remember to add (int)
    A operator++(int){
        A temp = *this;
        ++this -> real;
        ++this -> img;
        return temp;
    }

    //is Equalto operator - return & to avoid chaining and creating unnecessary copy
    A& operator=(A& a){
        this -> real = a.real;
        this -> img = a.img;
        return *this;  
    }

    //isEqual to operator
    bool operator==(A& a){
        if( this-> real == a.real && this -> img == a.img) return true;
        return false;
    }
};

int main(){
    A a(10,20);
    a.show();
    ++a;
    a.show();
    A b = a++;
    b.show();
    a.show();

    A c(100,200);
    a = c;
    a.show();
    c = b;
    c.show();

    if(c==a){
        cout<<"C and A are same "<<endl;
    }else{
        cout<<"Not same "<<endl;
    }

    return 0;

}