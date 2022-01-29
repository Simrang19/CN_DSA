#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

class ComplexNumbers {
    private:
        int real;
        int imaginary;

    public:
        ComplexNumbers(int r,int i){
            
		
		    this -> real = r;
		    this -> imaginary = i;
	

        }

        void print(){
            cout<<real<<" "<<"+ "<<"i"<<imaginary;
        }

        void plus(ComplexNumbers c){
            int img= imaginary + c.imaginary;
            int re= real+ c.real;
            imaginary=img;
            real=re;
        }
        void multiply(ComplexNumbers c){
            int img=real*c.imaginary + imaginary*c.real;
            int re=real*c.real - imaginary*c.imaginary;
            imaginary=img;
            real=re;
        }
    // Complete this class
    
};

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