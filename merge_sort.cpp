#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

void merge(int input[], int se,int mid, int ee){
    int n1=mid-se+1;
    int n2=ee-mid;

    int a[n1];
    int b[n2];

    for(int i=0; i<n1;i++){
        a[i]=input[se+i];
    }
    for(int i=0; i<n2;i++){
        b[i]=input[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=se;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            input[k]=a[i];
            k++;
            i++;
        }
        else{
            input[k]=b[j];
            k++;j++;
        }
    }
    while(i<n1){
        input[k]=a[i];
            k++;i++;
    }
    while(j<n2){
        input[k]=b[j];
            k++;j++;
    }


}

void myfun(int input[], int se,int ee){
    if (se>=ee){
        return;
    }
    else{
        int mid=(se+ee)/2;
        myfun(input,se,mid);
        myfun(input,mid+1,ee);
        merge(input,se,mid,ee);
    }
}

void mergeSort(int input[], int size){
    
    myfun(input,0,size-1);
	// Write your code here
        
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}