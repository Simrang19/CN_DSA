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

int findDuplicate(int *arr, int n)
{
    mergeSort(arr,n-1);
    int i=0;
    for(i;i<=n-1;i++){
        if(arr[i]==i){
            continue;
        }
        else{
            return arr[i];
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
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}