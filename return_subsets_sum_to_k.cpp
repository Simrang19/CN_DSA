#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

int subsetSumToK1(int input[], int n, int output[][50], int k) {
    if(n==0){
        output[0][0]=0;
        return 1;
    }

    int m=subsetSumToK(input+1,n-1,output,k);

    for (int i=0;i<m;i++){
        output[i+m][0]=output[i][0]+1;
        output[i+m][1]=input[0];
        for (int j=1;j<=output[i][0];j++){
            output[i+m][j+1]=output[i][j];
        }
    }
    int ans=0;
    for (int i=0;i<m;i++){
        for (int j=1;j<=output[i][0];j++){
            ans+=output[i][j];
        }
        if(ans!=k){
            output[i][0]=0;
            ans=0;
        }
    }
    return 2*m;
    // Write your code here

}

int subsetSumToK2(int input[], int n, int output[][50], int k) {
    if(n==0){
        output[0][0]=0;
        return 1;
    }

    int m=subsetSumToK(input+1,n-1,output,k);

    for (int i=0;i<m;i++){
        output[i+m][0]=output[i][0]+1;
        output[i+m][1]=input[0];
        for (int j=1;j<=output[i][0];j++){
            output[i+m][j+1]=output[i][j];
        }
    }
    int ans=0;
    for (int i=0;i<m;i++){
        for (int j=1;j<=output[i][0];j++){
            ans+=output[i][j];
        }
        if(ans!=k){
            output[i][0]=0;
            ans=0;
        }
    }
    return 2*m;
    // Write your code here

}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    if(n==0){
        output[0][0]=0;
        return 1;
    }

    int m=subsetSumToK(input+1,n-1,output,k);

    for (int i=0;i<m;i++){
        output[i+m][0]=output[i][0]+1;
        output[i+m][1]=input[0];
        for (int j=1;j<=output[i][0];j++){
            output[i+m][j+1]=output[i][j];
        }
    }
    int ans=0;
    for (int i=0;i<m;i++){
        for (int j=1;j<=output[i][0];j++){
            ans+=output[i][j];
        }
        if(ans!=k){
            output[i][0]=0;
            ans=0;
        }
    }
    return 2*m;
    // Write your code here

}

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}