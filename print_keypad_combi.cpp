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


void myfun(string ans, string output){
}
void printKeypad(int num){



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
    
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

