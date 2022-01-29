#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string
#define sz size()
using namespace std;
using ls= string;
using ld=double;


int subset(int input[], int n, int output[][20]) {
    if (n==0){
        output[0][0]=0;
        // output[0][1]={0};
        return 1;
    }
    int smallans=subset(input+1,n-1,output);
    int i=0;
    for(i ;i<smallans;i++){
        output[smallans+i][0]=output[i][0]+1;
        output[smallans+i][1]=input[0];
        for(int j =1;j<=output[i][0];j++){
            output[smallans+i][j+1]=output[i][j];
        }
    }
    return smallans+i;

    // Write your code here

}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

