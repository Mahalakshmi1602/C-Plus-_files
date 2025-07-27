#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;
public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    bool operator==(const Complex& c) {
        return (real == c.real) && (imag == c.imag);
    }

    // Stream insertion and extraction
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
};


int main() {
    Complex c1, c2;
    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "Enter second complex number:\n";
    cin >> c2;

    cout << "\n--- Operations ---\n";
    cout << "Addition: " << c1 + c2 << endl;
    cout << "Subtraction: " << c1 - c2 << endl;
    cout << "Multiplication: " << c1 * c2 << endl;

    if (c1 == c2)
        cout << "Both complex numbers are equal.\n";
    else
        cout << "Complex numbers are not equal.\n";

    return 0;
}
