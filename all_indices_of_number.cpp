#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

int* insertX(int n, int arr[],
             int x, int pos)
{
    int i;
  
    // increase the size by 1
    n++;
  
    // shift elements forward
    for (i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
  
    // insert x at pos
    arr[pos - 1] = x;
  
    return arr;
}
int allIndexes(int input[], int size, int x, int output[]) {
    if (size==0){
        return 0;
    }
    int sm=allIndexes(input+1,size-1,x,output);
    int arrSize = *(&output + 1) - output;
    // for (int i=1;i<arrSize;i++){
    //     output[i]++;
    // }
    if (input[0]==x){

        for (int i=sm-1;i>=0;i--){
            output[i+1]=output[i]+1;
        }
        output[0]=0;
        sm++;
    }
    else{
        for (int i=sm-1;i>=0;i--){
            output[i]=output[i]+1;
        }
    }
    arrSize = *(&output + 1) - output;
    return sm;
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
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
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}

