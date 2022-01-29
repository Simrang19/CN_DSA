#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

// void myfun(char *input,int size)

void removeConsecutiveDuplicates(char *input) {
    if (input[0]=='\0'){
        return;
    }
    if (input[0]==input[1]){
        int i=0;
        for (;input[i]!='\0';i++){
            input[i]=input[i+1];
        }
        input[i]='\0';
        removeConsecutiveDuplicates(input);
    }
    else{
        removeConsecutiveDuplicates(input+1);
    }
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/


}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}