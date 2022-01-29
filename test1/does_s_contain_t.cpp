#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

bool myfun(char large[],char*small,int start){
    if(*small=='\0'){
        return 1;
    }
    if(large[start]=='\0'){
        return 0;
    }
    // for (int i=0;large[i]!='\0';i++){
    //     for(int j=0;small[j]!='\0';j++){

    //     }
    // }
    if(large[start]==*small){
        myfun(large,small+1,start+1);
    }
    else{
        myfun(large,small,start+1);
    }

}

bool checksequenece(char large[] , char*small) {
    int start=0;
    int start2=0;
    bool ans=myfun(large,small,start);
    return ans;
}

int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
