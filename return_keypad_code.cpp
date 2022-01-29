/*Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

string two="abc";
string three="def";
string four="ghi";
string five="jkl";
string six="mno";
string seven="pqrs";
string eight="tuv";
string nine="wxyz";

int keypad(int num, string output[]){
    int newnum=num%10;
    num=num/10;
    string ans="";
    if (newnum==2){
        ans=two;
    }
    if (newnum==3){
        ans=three;
    }
    if (newnum==4){
        ans=four;
    }
    if (newnum==5){
        ans=five;
    }
    if (newnum==6){
        ans=six;
    }
    if (newnum==7){
        ans=seven;
    }
    if (newnum==8){
        ans=eight;
    }
    if (newnum==9){
        ans=nine;
    }
    if (ans.empty()){
        output[0]="";
        return 1;
    }
    
    int smallsize=keypad(num,output);
    
    
    int j=0;
    int i=0;


    for(int i=smallsize;i<ans.size()*smallsize;i++){
        if(j==smallsize){
            j=0;
        }
        output[i]= output[j];
        j++;
    } 
    // int k=0;

    // for(i=1;i<smallsize;i++){
    //     if(i==ans.size()-1){
    //         k+=1;
    //     }
    //     output[i]=output[k];

    // }

    j=0;
    int k=0;
    for ( i=0;i<smallsize*ans.size();i++){
        if (j==ans.size()){
            j=0;
        }
        k++;
        output[i]=output[i]+ans[j];
        if (k<smallsize){
            continue;
        }
        else{
            j++;
            k=0;
        }
    }
    
    
    
    return (ans.size())*smallsize ;
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
}
// int j=0;
//     int i=0;
//     int size=smallsize*ans.size();
//     string temp[size];
//     for ( i=0;i<smallsize;i++){
//         for ( int k=0;k<ans.size();k++){
//             temp[j]=output[i]+ans[k];
//             j++;
//         }
//     }
//     for (int i=0;i<size;i++){
//         output[i]=temp[i];
//     }

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
