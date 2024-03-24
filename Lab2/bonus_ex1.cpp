#include <iostream>
#include <ctype.h>
#define MAX_DEGREE 100
using namespace std;


// Rare polynomials with integer coefficients are polynomials
// of large degrees and many coefficients equal to 0. They can be represented by a data structure defined as below.
// Write functions for writing, reading, addition and multiplication of rare polynomials .

struct monom{
    int Coef;
    unsigned int Exponent;
};

struct polynomial{
    int degree;
    monom monoms[MAX_DEGREE * MAX_DEGREE];
};

void printPolynomial(polynomial p) {
    bool first = true;
    for(monom m : p.monoms) {
        if(m.Coef != 0) {
            if(!first) {
               if(m.Coef < 0) {
                    cout << " - ";
               } else {
                    cout << " + ";
               }
            } else {
                first = false;
            }
            cout << m.Coef << "*x^" << m.Exponent;
        }
    }
}

void clearArray(polynomial &p) {
    for(int i = 0; i < MAX_DEGREE * MAX_DEGREE; i++) {
        p.monoms[i].Coef = 0;
        p.monoms[i].Exponent = 0;
    }
}

bool readPolynomial(polynomial &p) {
    cout << "Enter the degree of the polynomial lower than " << MAX_DEGREE << ": ";
    cin >> p.degree;
    if (p.degree >= MAX_DEGREE) {
        cout << "Polynomial degree is too high!";
        return false;
    } else {
        clearArray(p);

        bool ok = true;
        char ans;

        while(ok) {
            cout << "Do you want to add more members? Y/N    ";
            cin >> ans;
            switch(tolower(ans)) {
                case 'y': {
                    int coef;
                    unsigned int exponent;
                    cout << "\tCoefficient: ";
                    cin >> coef;
                    cout << "\tExponent: ";
                    cin >> exponent;
                    if (exponent > p.degree) {
                        cout << "Exponent is bigger than the degree of the polynomial!\n";
                        break;
                    } else {
                        monom iMonom;
                        iMonom.Coef = coef;
                        iMonom.Exponent = exponent;
                        p.monoms[exponent] = iMonom;
                        break;
                    }
                }
                case 'n': {
                    cout << "Polynomial input ended.\n";
                    ok = false;
                    break;
                }
                default : {
                    cout << "Not a valid input.\n";
                }
            }
        }
        return true;
    }
}

polynomial addPolynomials(polynomial p1, polynomial p2) {
    polynomial sum;
    clearArray(sum);
    int maxDegree = max(p1.degree, p2.degree);
    sum.degree = maxDegree;
    for(int i = 0; i <= maxDegree; i++) {
        if(p1.monoms[i].Coef != 0) {
            if(p2.monoms[i].Coef != 0) {
                sum.monoms[i].Coef = p1.monoms[i].Coef + p2.monoms[i].Coef;
                sum.monoms[i].Exponent = p1.monoms[i].Exponent;
            } else {
                sum.monoms[i] = p1.monoms[i];
            }

        } else if (p2.monoms[i].Coef != 0) {
            sum.monoms[i] = p2.monoms[i];
        }
    }
    return sum;
}

polynomial multiplyPolynomials(polynomial p1, polynomial p2) {
    polynomial mul;
    mul.degree = p1.degree + p2.degree;
    clearArray(mul);
    for(int i = 0; i <= p1.degree && p1.monoms[i].Coef != 0; i++) {
        for(int j = 0; j <= p2.degree && p2.monoms[j].Coef != 0; j++){
            mul.monoms[p1.monoms[i].Exponent + p2.monoms[j].Exponent].Coef += p1.monoms[i].Coef * p2.monoms[j].Coef;
            mul.monoms[p1.monoms[i].Exponent + p2.monoms[j].Exponent].Exponent = p1.monoms[i].Exponent + p2.monoms[j].Exponent;
        }
    }
    return mul;
}



int main()
{
    polynomial p1, p2;
    bool validPolynomial1 = readPolynomial(p1);
    bool validPolynomial2 = readPolynomial(p2);
    if (validPolynomial1 && validPolynomial2) {
        cout << "\n\tThe first polynomial is: " << endl;
        printPolynomial(p1);

        cout << "\n\tThe second polynomial is: " << endl;
        printPolynomial(p2);

        cout << "\n\tThe sum of the two polynomials is: " << endl;
        printPolynomial(addPolynomials(p1, p2));

        cout << "\n\tThe multiplication of the two polynomials is: " << endl;
        printPolynomial(multiplyPolynomials(p1, p2));
    }

    return 0;
}
