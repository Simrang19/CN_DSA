#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string
#include <sstream>
#include<math.h>
#include <string.h>
#define sz size()
using namespace std;
using ls = string;
using ld = double;

int myfun(char input[], int size)
{
    static int i = 0;
    if (size == 1)
    {
        return input[0]-'0';
    }
    double sm = myfun(input+1, size - 1);
    double ans=input[0]-'0';
    ans = sm + pow(10, strlen(input)-1)*ans;
    
    return int(ans);
}

int stringToNumber(char input[])
{
    int size = strlen(input);
    static int si = size;
    int sma = myfun(input, size);
    return sma;
    // Write your code here
}
int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
