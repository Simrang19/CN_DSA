#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;


class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    public:
    Polynomial(){        
        degCoeff=new int[5];
        for(int i=0;i<5;i++){
            degCoeff[i]=0;
        }
        capacity=5;
    }
    Polynomial(const Polynomial &d){
        this->degCoeff=new int[d.capacity];
        for(int i=0;i<d.capacity;i++){
            this->degCoeff[i]=d.degCoeff[i];

        }
        this->capacity=d.capacity;
    }
    void setCoefficient(int deg,int coef){
        int * ndegCoefficient;
        if(capacity<=deg){
            ndegCoefficient=new int[deg+1];
            int i=0;
        	for(;i<capacity;i++){
            ndegCoefficient[i]= this->degCoeff[i];
        	}
            for(i=capacity;i<deg+1;i++){
                ndegCoefficient[i]=0;
            }

            delete [] this->degCoeff;
            this->degCoeff=ndegCoefficient;
            this->capacity=deg+1;
            
        }
        this->degCoeff[deg]=coef;
        
    }
    Polynomial operator+(Polynomial &p2){
        Polynomial p3;
        int c=this->capacity;
        int c2=p2.capacity;
        int h=0;
        int l=0;
        int p=0;
        if (c>c2){
            h=c;
            l=c2;
            p=0;
        }
        else{
            h=c2;
            l=c;
            p=1;
        }
        p3.capacity=h;
        p3.degCoeff=new int[h];

        int j=0;
        for(;j<l;j++){
            int g=this->degCoeff[j]+p2.degCoeff[j];
            p3.degCoeff[j]=g;
        }

        for(;j<h;j++){
            int m;
            if(h==c){
                m=degCoeff[j];
            }
            else{
                m=p2.degCoeff[j];
            }
            p3.degCoeff[j]=m;
        }
        return p3;
    } 
    Polynomial operator-(Polynomial &p2){
        Polynomial p3;
        int c=this->capacity;
        int c2=p2.capacity;
        int h=0;
        int l=0;
        int p=0;
        if (c>c2){
            h=c;
            l=c2;
            p=0;
        }
        else{
            h=c2;
            l=c;
            p=1;
        }
        p3.capacity=h;
        p3.degCoeff=new int[h];
        int j=0;
        for(;j<l;j++){
            int g=this->degCoeff[j]-p2.degCoeff[j];
            p3.degCoeff[j]=g;
        }
        for(;j<h;j++){
            int m;
            if(h==c){
                m=degCoeff[j];
            }
            else{
                m= (-p2.degCoeff[j]);
            }
            p3.setCoefficient(j,m);
        }
        
        return p3;
    } 
    Polynomial operator*(Polynomial const &p2){
        Polynomial p3;
        p3.capacity = p2.capacity+capacity;
        p3.degCoeff = new int[p3.capacity];
        // int c=this->capacity;
        // int c2=p2.capacity;
        // int h=0;
        // int l=0;
        // int p=0;
        for(int i=0;i<p3.capacity;i++){
            p3.degCoeff[i]=0;
        }
        for (int i=0; i<this->capacity;i++){
            for(int k=0;k<p2.capacity;k++){
                int x=p2.degCoeff[k]*this->degCoeff[i];
                p3.setCoefficient(k+i,x);
            }
        }
        
        return p3;
    }
    void print(){
        for(int i=0;i<this->capacity;i++){
            if(degCoeff[i]){
                cout<<this->degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
    Polynomial operator=(Polynomial const &d) {
		this -> degCoeff = new int[d.capacity];
		for(int i = 0; i < d.capacity; i++) {
			this -> degCoeff[i] = d.degCoeff[i];
		}
		this -> capacity = d.capacity;
        return *this;
	}
};


// class Polynomial {
// public :
//     int *degCoeff;      // Name of your array (Don't change this)
// 	int capacity;			// total size
// public :
//  Polynomial() {
// 		degCoeff = new int[10];
//          for(int i=0;i<10;i++)degCoeff[i]=0;
// 		capacity = 10;
// 	}

// 	 Polynomial(const Polynomial &d) {
// 		this -> degCoeff = new int[d.capacity];
// 		for(int i = 0; i < d.capacity; i++) {
// 			this -> degCoeff[i] = d.degCoeff[i];
// 		}
// 		this -> capacity = d.capacity;
// 	}
    
//    void setCoefficient(int deg,int coeff) {
//           if(deg>=capacity)
//           {
//               //int size = this->capacity;
//               int size=deg+1;
//               int *newarr = new int[size];
//               for(int i=0;i<capacity;i++)newarr[i]=this->degCoeff[i];
//               for(int i=capacity;i<size;i++)newarr[i]=0;
//               delete[] this->degCoeff;
//               this->degCoeff=newarr;
//               this->capacity = size;
//           }
//           this->degCoeff[deg]=coeff;
//     }
//     // Complete the class
//     void print() {
//         for(int i = 0;i<capacity;i++) {
//             if(degCoeff[i])
// 			cout << degCoeff[i] << "x" <<i << " ";
// 		}
// 		cout << endl;
//     }
    
//     Polynomial operator+(Polynomial &p) {
//         Polynomial newP;
//         newP.capacity = max(p.capacity,capacity);
//         newP.degCoeff = new int[newP.capacity];
        
//         if (capacity<p.capacity) {
//             int k;
//             for (k=0;k<capacity;k++) {
//                 newP.degCoeff[k]=degCoeff[k]+p.degCoeff[k];
//             }
//             for (;k<p.capacity;k++) {
//                 newP.degCoeff[k]=p.degCoeff[k];
//             }
//         } else {
//             int k;
//             for ( k=0;k<p.capacity;k++) {
//                 newP.degCoeff[k]=degCoeff[k]+p.degCoeff[k];
//             }
//             for (;k<capacity;k++) {
//                 newP.degCoeff[k]=degCoeff[k] ;
//             }
//         }
//         return newP;
//     }
    
//     Polynomial operator-(Polynomial &p) {
//         Polynomial newP;
//         newP.capacity = max(capacity,p.capacity);
//         newP.degCoeff = new int[newP.capacity];
        
//         if (capacity<p.capacity) {
//             int k;
//             for (k=0;k<capacity;k++) {
//                 newP.degCoeff[k]=degCoeff[k]-p.degCoeff[k];
//             }
//             for (;k<p.capacity;k++) {
//                 newP.degCoeff[k]=-p.degCoeff[k];
//             }
//         } else {
//             int k;
//             for ( k=0;k<p.capacity;k++) {
//                 newP.degCoeff[k]=degCoeff[k]-p.degCoeff[k];
//             }
//             for (;k<capacity;k++) {
//                 newP.degCoeff[k]=degCoeff[k] ;
//             }
//         }
//         return newP;
//     }
//     Polynomial operator*(Polynomial const &p) {
//         Polynomial newP;
//         newP.capacity = p.capacity+capacity;
//         newP.degCoeff = new int[newP.capacity];
        
//         for(int i=0;i<newP.capacity;i++)
//             newP.degCoeff[i]=0;
        
//         for (int i=0;i<capacity;i++) {
//             for (int j=0;j<p.capacity;j++) {
//                 newP.degCoeff[i+j] += degCoeff[i]*p.degCoeff[j];
//             }
//         }
//         return newP;
//     }
//     Polynomial operator=(Polynomial const &d) {
// 		this -> degCoeff = new int[d.capacity];
// 		for(int i = 0; i < d.capacity; i++) {
// 			this -> degCoeff[i] = d.degCoeff[i];
// 		}
// 		this -> capacity = d.capacity;
//         return *this;
// 	}
    
// };