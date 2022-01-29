#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

// int len(char input[]){
//     int i=0;
//     int ans=0;
//     while(input[i]!='\0'){
//         ans++;
//         i++;
//     }
//     return ans;
// }

// bool checkAB(char input[]) {
    
//     if (len(input) == 0){
//         return true;
//     }
//     if (len(input) == 1){
//         if (input[0] == 'a' ){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }   

//     if (input[0] == 'a'){
//         return checkAB(input+1);
//     }
//     else if (input[0] == 'b'){
//         if (input[1] == 'b'){
//             return checkAB(input+2);
//         }
//         else{
//             return false;
//         }
//     } 
//     else{
//         return false;
//     }
    // bool ans=true;
    // if (input[0]=='\0'){
    //     return ans;
    // }
    
    // if(input[0]=='a' and (input[1]=='a' or (input[1]=='b' && input[2]=='b')or input[1]=='\0')){
    //     ans=true;
    //     return true;
    // }
    // if((input[0]=='b' and input[1]='b') and (input[2]=='a' or input[1]=='\0')){
    //     ans=true;
    //     return true;
    // }
    // else{
    //     ans=false;
    //     return false;
    // }
    // bool smallans=checkAB(input+1);
    // for(int i=0;input[i]!='\0';i++){
    //     if((input[i]=='a' and input[i+1]=='\0') or (input[i]=='a' and input[i+1]=='b' and input[i+2]=='b')){
    //         ans=true;
    //     }
    //     else{
    //         ans=false;
    //     }
    //     if (input[i]=='b' and input[i+1]=='b' and input[i+2]=='a' or (input[i]=='b' and input[i+1]=='b' and input[i+2]=='\0')){
    //         ans=true;
    //     }
    //     else{
    //         ans=false;
    //     }
    // }
    // return ans;

	// Write your code here

// }

bool check(char input[], string s){
    if(s==""){
        if(input[0]=='a'){
            bool ans = check(input+1,"a");
            return ans;
        }else{
            return false;
        }
    }else if(s=="a"){
        if(input[0]=='\0'){
            return true;
        }else if(input[0]=='a'){
            bool ans = check(input+1,"a");
            return ans;
        }else if(input[0]=='b' & input[1]=='b'){
            bool ans = check(input+2,"bb");
            return ans;
        }else{
            return false;
        }
    }else if(s=="bb"){
        if(input[0]=='\0'){
            return true;
        }else if(input[0]=='a'){
            bool ans = check(input+1,"a");
            return ans;
        }else{
            return false;
        }
    }
}

bool checkAB(char input[]) {
    // Write your code here
    string ss="";
    return check(input, ss);

}


int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
