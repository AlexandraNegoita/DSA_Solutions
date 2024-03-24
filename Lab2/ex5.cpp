#include <iostream>
using namespace std;

// Add to the complex class new methods for adding and multiplying complex numbers.
class complex {
private:    //class variables
	double re;
    double im;
public:
	complex() {}; // constructor without params
	complex(double param_re, double param_im) {//constructor
         // used to initialize the members of the class with values and to allocates memory for  some members
		this->re=param_re; //re=param_re or (*this).re, later
		this->im=param_im;//im=param_im
	}
	double getRe(){//method: getter
		return re;
	}
	void setRe(double re) {
        this->re = re;
	}
	double getIm(){ //method: getter
		return im;
	}
	void setIm(double im) {
        this->im = im;
	}
	complex complex_conjugate() { //method- conjugate of a complex number
        complex conjugate(re,-im);//object of type complex
        return conjugate;
    }

    complex add(complex c2) {
        complex c; // c = (a + c) + (b + d)i, where c1 = a + bi; c2 = c + di;
        c.setRe(this->re + c2.getRe());
        c.setIm(this->im + c2.getIm());
        return c;
    }

    complex multiply(complex c2) {
        complex c; // c = (ac - bd) + (bc + ad)i, where c1 = a + bi; c2 = c + di;
        c.setRe(this->re * c2.getRe() - this->im * c2.getIm());
        c.setIm(this->im * c2.getRe() + this->re * c2.getIm());
        return c;
    }

    void print(){
        cout << "(" << this->re << " + " << this->im << "i)";
    }
};



int main()
{
    complex c1(2, -3), c2(4, 5);
    cout << "C1: "; c1.print();
    cout << "\nC2: "; c2.print();
    cout << "\nThe conjugate of c1 is: ";
    c1.complex_conjugate().print();
    cout << endl;

    cout << "Sum: ";
    c1.print(); cout << " + "; c2.print(); cout << " = "; c1.add(c2).print(); cout << endl;

    cout << "Multiply: ";
    c1.print(); cout<< " * "; c2.print(); cout << " = "; c1.multiply(c2).print(); cout << endl;

    return 0;
}
