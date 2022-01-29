#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string
#define sz size()
using namespace std;
using ls= string;
using ld=double;

int partition(int input[],int l,int r){
    int j=l-1;
    for(int i=l;i<=r-1;i++){
        if (input[i]<input[r]){
            j++;
            int g=input[i];
            input[i]=input[j];
            input[j]=g;
    
        }
    }
    int g=input[j+1];
    input[j+1]=input[r];
    input[r]=g;
    
    return j+1;

}
void quick(int input[],int l,int r){
    if (l<r){
        int p=partition(input,l,r);
        quick(input,l,p-1);
        quick(input,p+1,r);
    }
}

void quickSort(int input[], int size) {
    quick(input,0,size-1);

  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}
