#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;


void myfun(char input[],int size,int start){
    if (input[start]=='\0'){
        return;
    }
    myfun(input,size,start+1);
    if (input[start]=='p' && input[start+1]=='i'){
        int l=strlen(input);
        input[l+1]='\0';
        for (int i=l+1;i>start+3;i--){
            input[i]=input[i-2];
        }
        input[start]='3';
        input[start+1]='.';
        input[start+2]='1';
        input[start+3]='4';
        return;
        //pixuvpupi\0
        
    }
    else{
        return;
    }

}

void replacePi(char input[]) {
    int size=strlen(input);
    myfun(input,size,0);
    
	// Write your code here

}
// void replacePi(char input[]) {
//     int size=strlen(input);
//     // static int one=1;
//     // static int two=2;
    
//     // if (size<=1){
//     //     return;
//     // }
    
//     // // if(input[1]=='i'){
//     // //     if (input[0]=='p'){
//     // //         for(int i=size+3;i>2;i--){
//     // //             input[i]=input[i-2];
//     // //         }
             
//     // //         input[0]='3';
//     // //         input[size]='.';
//     // //         input[size+1]='1';
//     // //         input[size+2]='4';
//     // //     }
//     // // replacePi(input);

//     // // }
//     // if(input[0]=='p'){
//     //     if (input[1]=='i'){
//     //         for(int i=size+3;i>2;i--){
//     //             input[i]=input[i-2];
//     //         }
             
//     //         input[0]='3';
//     //         input[1]='.';
//     //         input[2]='1';
//     //         input[3]='4';
//     //     }
//     //     replacePi(input);
//     //     size+=4;
//     // }
    
//     // else{
//     //     replacePi(input);
        
//     // }
//     // size--;

    
// 	// // Write your code here


//     if(start=='\0'){
//         return;
//     }
//     if(input[0]=='p'){
//         if (input[1]=='i'){
//             for(int i=size+3;i>2;i--){
//                 input[i]=input[i-2];
//             }
             
//             input[0]='3';
//             input[1]='.';
//             input[2]='1';
//             input[3]='4';
//         }
//         replacePi(input);
//     }

// }

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
