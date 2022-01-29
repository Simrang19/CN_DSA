// input - input array
// size - length of input array
// element - value to be searched
#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

int binary(int input[],int l,int r,int element){
    if(r>=l){
        int mid=(r+l)/2;
        if(input[mid]==element){
            return mid;
        }
        // if(input[mid]!=element || r<l){
        //     return -1;
        // }
    
        if (input[mid]<element){
            l=mid+1;
            return binary(input,l,r,element);
        
        }
        else if(input[mid]>=element){
            r=mid-1;
            return binary(input,l,r,element);
        }
    }
    return -1;
}

int binarySearch(int input[], int size, int element) {
    binary(input,0,size-1,element);
    // Write your code here

}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}