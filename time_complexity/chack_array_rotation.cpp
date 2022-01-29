#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

int arrayRotateCheck(int *input, int size)
{
    if (size==0){
        return 0;
    }
    int i=0;
    for(i;i<size-1;i++){
        if(input[i]<input[i+1]){
            continue;
        }
        else{
            return i+1;
        }
    }
    if(i==size-1){
        return 0;
    }
    //Write your code here
}

int main()
{

	int t;
	cin >> t;
	while (t--)
	{

		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
	
	return 0;
}