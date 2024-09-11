#include <iostream>
using namespace std;

class Complex {
    int real;
    int img;

public:
    Complex(){
    	real = 0;
		img = 0;
	}

    Complex(int r, int i){
    	real = r;
    	img = i;
	}

    Complex operator+(Complex& b) {
        Complex temp;
        temp.real = this->real + b.real;
        temp.img = this->img + b.img;
        return temp;
    }

    Complex operator-(Complex& b) {
        Complex temp;
        temp.real = this->real - b.real;
        temp.img = this->img - b.img;
        return temp;
    }

    Complex operator*(Complex& a){
        Complex temp;
        temp.real = this->real * a.real;
        temp.img = this->img * a.img;
        return temp;
    }

    Complex operator/(Complex& a){
        Complex temp;
        if (a.real != 0 && a.img != 0) {
            temp.real = this->real / a.real;
            temp.img = this->img / a.img;
        } else {
            cout << "Error: Division by zero." << endl;
        }
        return temp;
    }

    Complex operator%(Complex& a) const {
        Complex temp;
        if (a.real != 0 && a.img != 0) {
            temp.real = this->real % a.real;
            temp.img = this->img % a.img;
        } else {
            cout << "Error: Division by zero." << endl;
        }
        return temp;
    }
	
	Complex operator^(Complex &a){
		Complex temp;
		
		int mReal = (this -> real > a.real) ? this -> real : a.real;
		int mImg = (this -> img > a.img ) ? this -> img : a.img;
		
		temp.real = mReal * mReal;
		temp.img = mImg * mImg;
		
		return temp;
	}
	
    Complex operator==(Complex& a){
        Complex temp;
        if (this->real == a.real && this->img == a.img) {
            temp.real = this->real;
            temp.img = this->img;
            cout << "Both are equal." << endl;
        } 
		else
		{
            temp.real = (this->real > a.real) ? this->real : a.real;
            temp.img = (this->img > a.img) ? this->img : a.img;
            cout << "Both are not equal, so higher values assigned." << endl;
        }
        return temp;
    }

    Complex operator-(){
        Complex temp;
        temp.real = -this->real;
        temp.img = -this->img;
        return temp;
    }

    void show(string str) {
        if (this->img >= 0) {
            cout << "Complex Number " << str << " is : " << this->real << " + " << this->img << "i" << endl;
        } else {
            cout << "Complex Number " << str << " is : " << this->real << " - " << (-this->img) << "i" << endl;
        }
    }
};

int main() {
    Complex c1(10, 20);
    c1.show("c1");

    Complex c2(100, 200);
    c2.show("c2");

    Complex c3 = c1 + c2;
    c3.show("c3");

    Complex c4(50, 0);
    Complex c5 = c4 == c1;
    c5.show("c5");
	
	Complex c6 = c1 ^ c2;
	c6.show("c6");
	
    return 0;
}

