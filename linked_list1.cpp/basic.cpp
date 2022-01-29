#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

class Node {
	public :
	int data;
	Node *next;

	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};

int main() {
	Node n1(1);
	Node *head = &n1;

	Node n2(2);

	Node n3(3);
	Node n4(4);
	Node n5(5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	Node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
	cout<<count;
	int f=count-3;
    temp=head;
    while(f){
        f--;
        temp=temp->next;
    }
	cout<<temp->next->data;
	
	// Statically
	// Node n1(1);
	// Node *head = &n1;

	// Node n2(2);

	// n1.next = &n2;

	// cout << n1.data << " " << n2.data << endl;
	// cout << head->data << endl;


}