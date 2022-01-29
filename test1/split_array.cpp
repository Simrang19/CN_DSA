#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

int sum(int input[],int n){
    int ans=0;
    for (int i=0;i<n;i++){
        ans+=input[i];
    }
    return ans;
}

bool splitArray(int *input, int size) {
    int five[50];
    int f=0;
    int three[50];
    int t=0;
    int extra[50];
    int e=0;
    for(int i=0;i<size;i++){
        if(input[i]%5==0 and input[i]%3!=0){
            five[f]=input[i];
            f++;
        }
        else if(input[i]%3==0 and input[i]%5!=0){
            three[t]=input[i];
            t++;
        }
        else{
            extra[e]=input[i];
            e++;
        }
    }
    int sum3=sum(three,t+1);
    int sum5=sum(five,f+1);
    int sume=sum(extra,e+1);

    int diff=sum3-sum5;
    if (diff<0){
        diff*=-1;
    }
    int jk[1000000];

    


    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}
