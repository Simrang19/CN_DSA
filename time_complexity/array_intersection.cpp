#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

void merge(int input[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    
    for(int i=0; i<n1;i++){
        a[i]=input[l+i];
    }
    for(int i=0; i<n2;i++){
        b[i]=input[mid+1+i];
    }
    int i=0;int j=0;
    int k=l;
    while (i<n1 && j<n2){
        if (a[i]<b[j]){
            input[k]=a[i];
            k++;
            i++;
        }
        else{
            input[k]=b[j];
            k++;
            j++;
        }

    }
    while(i<n1){
        input[k]=a[i];
        i++;
        k++;
    }
    while(j<n2){
        input[k]=b[j];
        j++;
        k++;
    }
}

void myfun(int input[],int l,int r){
    if(l>=r){
        return;
    }
    else{
        int mid=(l+r)/2;
        myfun(input,l,mid);
        myfun(input,mid+1,r);
        merge(input,l,mid,r);
    }
}

void mergeSort(int input[], int size){
    
    myfun(input,0,size-1);
	// Write your code here
        
}




void intersection(int *arr1, int *arr2, int n, int m) 
{
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);    
    int i=0;
    int j=0;
    while(i<n and j<m ){
        if (arr1[i]<arr2[j]){
            i++;
            continue;
        }
        if (arr1[i]>arr2[j]){
            j++;
            continue;
        }
        if (arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
    }

    //Write your code here
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}