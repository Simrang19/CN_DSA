#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string
#include <stack>
#define sz size()
using namespace std;
using ls= string;
using ld=double;


bool isBalanced(string expression) 
{
    int i=0;
    stack  <char> s1;
    char t;
    while(expression[i]!='\0'){
        i++;
        if(expression[i]=='('){
            s1.push('(');
        }
        if(expression[i]=='['){
            s1.push('[');
        }
        if(expression[i]=='{'){
            s1.push('{');
        }
        if(expression[i]==')'){
            t=s1.top();
            s1.pop();
            if(t=='('){
                continue;
            }
            else{
                return false;
            }
        }
        
        if(expression[i]==']'){
            t=s1.top();
            s1.pop();
            if(t=='['){
                continue;
            }
            else{
                return false;
            }
        }
        
        if(expression[i]=='}'){
            t=s1.top();
            s1.pop();
            if(t=='{'){
                continue;
            }
            else{
                return false;
            }
        }
        
        
    }
    if(s1.empty()){
        return true;
    }
    else{
        return false;
    }
    // Write your code here
}