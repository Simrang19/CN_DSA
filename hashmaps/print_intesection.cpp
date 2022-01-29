
#include <iostream>
#include <unordered_map>
using namespace std;



int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}

void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int,int> a1;
    unordered_map<int,int> a2;
    for(int i=0;i<m;i++){
        a2[arr2[i]]++;
    }
    for(int i=0;i<n;i++){
        
        if(a2[arr1[i]]>0){
            a2[arr1[i]]--;
            cout<<arr1[i]<<endl;
        }
        // a2[arr2[i]]++;
    }
    
    // Write your code here
}