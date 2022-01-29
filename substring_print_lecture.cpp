#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

void print_subs(string input, string output) {
	if (input.length() == 0) {
		cout << output << endl;
		return;
	}

	print_subs(input.substr(1), output);
	print_subs(input.substr(1), output + input[0]);
}

int main() {
	string input;
	cin >> input;
	string output = "";
	print_subs(input, output);
}
