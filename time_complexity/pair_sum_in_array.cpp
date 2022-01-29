#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

// int binarysearch(int *arr,int l,int r, int s){
//     if(r>=l){
//         int mid=l + (r-l)/2;
//         if (arr[mid]==s){
//             return mid;
//         }
    
       
//         if(arr[mid]>s){
//             return binarysearch(arr,l,mid-1,s);
//         }
//         return binarysearch(arr,mid+1,r,s);
//     }
//     return 0;
    
// }

// int occurrenceCnt(int *arr , int n, int x)
// {
//   int cnt = 0;
//   for(int i = 0; i<n; i++)
//     if(arr[i] == x)
//       cnt++;
//   return cnt;
// }

// int pairSum(int *arr, int n, int num)
// {
//     sort(arr,arr+n);
//     int ans=0;
//     for(int i=0;i<n;i++){
//         int j=binarysearch(arr+i,0,n,num-arr[i]);
//         if(j){
//             ans+=occurrenceCnt(arr+i,n,num-arr[j]);
//             // arr[binarysearch(arr+i+1,0,n-i-1,num-arr[i])]=-1;
//         }
//         else{
//             continue;
//         }
//     }
//     return ans;
// 	//Write your code here
// }



int occurrenceCnt(int *arr , int n, int x)
{
  int cnt = 0;
  for(int i = 0; i<n; i++)
    if(arr[i] == x)
      cnt++;
  return cnt;
}

int pairSum(int *arr, int n, int num)
{
    sort(arr,arr+n);
    int ans=0;
    for(int i=0;i<n-1;i++){
        
        ans+=occurrenceCnt(arr+i+1,n,num-arr[i]);

    }
    return ans;
	//Write your code here
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}