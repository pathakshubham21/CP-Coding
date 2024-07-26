// Problem statement
// A ComplexNumber class contains two data members : one is the real part (R) and the other is imaginary (I) (both integers).

// Implement the Complex numbers class that contains following functions -

// 1. constructor
// You need to create the appropriate constructor.

// 2. plus -
// This function adds two given complex numbers and updates the first complex number.

// e.g.

// if C1 = 4 + i5 and C2 = 3 +i1
// C1.plus(C2) results in: 
// C1 = 7 + i6 and C2 = 3 + i1
// 3. multiply -
// This function multiplies two given complex numbers and updates the first complex number.

// e.g.

// if C1 = 4 + i5 and C2 = 1 + i2
// C1.multiply(C2) results in: 
// C1 = -6 + i13 and C2 = 1 + i2
// 4. print -
// This function prints the given complex number in the following format :

// a + ib
// Note : There is space before and after '+' (plus sign) and no space between 'i' (iota symbol) and b.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 4 5
// 6 7
// 1
// Sample Output 1 :
// 10 + i12
// Sample Input 2 :
// 4 5
// 6 7
// 2
// Sample Output 2 :
// -11 + i58


/**********
 
Following is the main function we are using internally.
Refer this for completing the ComplexNumbers class.
 
 
int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
    
}
 
 ************/


class ComplexNumbers {
private:
    int real;
    int imag;

public:
    // Constructor
    ComplexNumbers(int r, int i) : real(r), imag(i) {}

    // Plus function to add two complex numbers
    void plus(const ComplexNumbers& other) {
        this->real += other.real;
        this->imag += other.imag;
    }

    // Multiply function to multiply two complex numbers
    void multiply(const ComplexNumbers& other) {
        int r = (this->real * other.real) - (this->imag * other.imag);
        int i = (this->real * other.imag) + (this->imag * other.real);
        this->real = r;
        this->imag = i;
    }

    // Print function to display the complex number
    void print() const {
        std::cout << real << " + i" << imag << std::endl;
    }
};
