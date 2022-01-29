#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

// int returnPermutations(string input, string output[]){
//     static int i=0;
//     if(input.size()==1 or input.size()==0 ){
//         output[0]=input[0];
//         return 1;
//     }
//     i++;
    
//     int smallans=returnPermutations(input.substr(0,i-1)+input.substr(i+1),output);
//     for(int j=0;j< smallans;j++){
//         output[j]=input[i]+ output[j];
//     }
//     return smallans*(smallans+1);

    
//    	/* Don't write main() function.
// 	 * Don't read input, it is passed as function argument.
// 	 * Print output as specified in the question
// 	*/
// }

int returnPermutations(string input, string output[]){
    if(input.length() == 0){
        output[0] = ""; 
        return 1;
    }
    
    string smallOutput[10000];
    int smallSize = returnPermutations(input.substr(1), smallOutput); 
    int k = 0;
    for(int i = 0; i < smallSize; i++){
        for(int j = 0; j <=smallOutput[i].length(); j++){ 
            output[k++] = smallOutput[i].substr(0,j) + input[0] + smallOutput[i].substr(j); 
            
        }
    }
    
    return k;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
