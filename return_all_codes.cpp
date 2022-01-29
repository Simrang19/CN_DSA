#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string
using namespace std;
#include <string.h>

// char giveno(string f){

// char getchar(int g){
//     char b='a'-g+1;
//     return b;
// }
// //     if (f=="1"){
// //         return 'a';
// //     }
// //     if (f=="2"){
// //         return 'b';
// //     }
// //     if (f=="3"){
// //         return 'c';
// //     }
// //     if (f=="4"){
// //         return 'd';
// //     }
// //     if (f=="5"){
// //         return 'e';
// //     }
// //     if (f=="6"){
// //         return 'f';
// //     }
// //     if (f=="7"){
// //         return 'g';
// //     }
// //     if (f=="8"){
// //         return 'h';
// //     }
// //     if (f=="9"){
// //         return 'i';
// //     }
// //     if (f=="10"){
// //         return 'j';
// //     }
// //     if (f=="11"){
// //         return 'k';
// //     }
// //     if (f=="12"){
// //         return 'l';
// //     }
// //     if (f=="13"){
// //         return 'm';
// //     }
// //     if (f=="14"){
// //         return 'n';
// //     }
// //     if (f=="15"){
// //         return 'o';
// //     }
// //     if (f=="14"){
// //         return 'p';
// //     }
// //     if (f=="15"){
// //         return 'q';
// //     }
// //     if (f=="18"){
// //         return 'r';
// //     }
// //     if (f=="19"){
// //         return 's';
// //     }
// //     if (f=="20"){
// //         return 't';
// //     }
// //     if (f=="21"){
// //         return 'u';
// //     }
// //     if (f=="22"){
// //         return 'v';
// //     }
// //     if (f=="23"){
// //         return 'w';
// //     }
// //     if (f=="24"){
// //         return 'x';
// //     }
// //     if (f=="25"){
// //         return 'y';
// //     }
// //     if (f=="26"){
// //         return 'z';
// //     }
// // }

// int getCodes(string input, string output[10000]) {
//     if(input.empty()){
//         output[0]='\0';
//         return 1;
        
//     }
    
//     if(input.size()>=2){
//         int small1= getCodes(input.substr(1),output);
//     }
//     else{
//         int small1=0;
//     }
//     if(input.size()>=3){
//         int small2= getCodes(input.substr(2),output);
//     }
//     else{
//         int small2=0;
//     }
//     char l;
//     int h=input[0]-'0';
//     l=getchar(h);
//     // for(int i=0;i<=26;i++){
        
//     // }
//     char output1[10000];    
//     for (int i=0;i<small1;i++){
//         output1[i]=l+output1[i];
//     }
//     char f;
//     h=input[0]+input[1]-'0';
//     if(h>=10 and h<=26){
//         f=getchar(h);
//     }
//     for(int k=0;k<small1;k++){
//         output[k]=output1[k];
//     }
    
//     char output2[10000];
//     for (int i=0;i<small2;i++){
//         output2[i]=f+output2[i];
//     }
//     for(int k=small1;k<small1+small2;k++){
//         output[k]=output2[k];
//     }
//     return small1+small2;


//     // string s(1, input[i]);
//     // output[i]=l;


//     /*

//     You are given the input text and output string array. Find all possible codes and store in the output string array. Donât print the codes.
//     Also, return the number of codes return to the output string. You do not need to print anything.
//     */
// }

char getchar(string s){
    int num = s[0] - '0';
    if(s.length()==2){
        num = 10*(s[0] - '0') + s[1] - '0';
    }
    char ans =  'a' + num - 1;
    return ans;
}

int getCodes(string input, string output[10000]) {
    if(input.empty()){
        output[0]="";
        return 1;
   	}
	if(input.size()==1){
        char aa = getchar(input.substr(0,1));
        output[0]=aa;
        return 1;
    }
    string result1[10000],result2[10000];
    int size2=0;
    int size1=getCodes(input.substr(1),result1);
    if(input.size()>1){
        int num = 10*(input[0] - '0') + (input[1] - '0');
        if(num >=10 && num<=26)
        {
            size2=getCodes(input.substr(2),result2);
        }
    }
    int k=0;
    for(int i=0;i<size1;i++){
        char aa = getchar(input.substr(0,1));
        output[k++]=aa + result1[i];
    }
    for(int i=0;i<size2;i++){
        char aa = getchar(input.substr(0,2));
        output[k++]=aa + result2[i];
    }

    return k;
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Donât print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
}
int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}