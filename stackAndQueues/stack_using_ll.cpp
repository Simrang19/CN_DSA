#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;


class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
// template <typename T>
// class stack{
//     Node <T> *head;
//     int size;
//     public:
//     stack(){
//         head=NULL;
//         size=0;
//     }

//     void push(int a){
//         Node *h;
//         h->data=a;
//         if (head==NULL){
//             head=h;
//             head->next=NULL;
//             size++;
//         }
//         else{
//             h->next=head;
//             head=h;
//             size++;
//         }
//     }
//     T top(){
//         return tail->data;
//     }
//     T pop(){
//         if(tail==NULL){
//             cout<<"stack empty";
//             return 0;
//         }
//         else{
//             node *temp=head;
//             T a=head->data;
//             head=head->next;
//             size--;
//             delete temp;
//             return a;
//         }
        
//     }

//     int getSize(){
//         return size;

//     }

//     bool isEmpty(){
//         if(size==0){
//             return 1;
//         }
//         else{
//             return 0;
//         }

//     }

//     T top(){
//         if (head!=NULL){
//             return head->data;
//         }
//         else{
//             cout<<"stack empty";
//             return 0;
//         }
        
//     }
// };

// class Stack{
//     Node *head;
//     int size;
//     public:
//     Stack(){
//         head=NULL;
//         size=0;
//     }

//     void push(int a){
//         Node *h;
//         h->data=a;
        
        
//         h->next=head;
//         head=h;
//         size++;
        
//     }

//     int pop(){
//         if(head==NULL){

//             return 0;
//         }
//         else{
//             Node *temp=head;
//             int a=head->data;
//             head=head->next;
//             size--;
//             delete temp;
//             return a;
//         }
        
//     }

//     int getSize(){
//         return size;

//     }

//     bool isEmpty(){
//         if(size==0){
//             return 1;
//         }
//         else{
//             return 0;
//         }

//     }

//     int top(){
//         if (head!=NULL){
//             return head->data;
//         }
//         else{

//             return 0;
//         }
        
//     }
// };






//this:

class Stack {
	Node *head;
	int size;		// number of elements prsent in stack

	public :

	Stack() {
		head = NULL;
		size = 0;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void push(int element) {
		Node *newNode = new Node(element);
		newNode -> next = head;
		head = newNode;
		size++;
	}

	int pop() {
		if(isEmpty()) {
			return -1;		
		}
		int ans = head -> data;
		Node *temp = head;
		head = head -> next;
		delete temp;
		size--;
		return ans;
	}

	int top() {
		if(isEmpty()) {
			return -1;		
		}
		return head -> data;
		
	}



};