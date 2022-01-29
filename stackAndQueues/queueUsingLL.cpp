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
    	this->data = data;
    	next = NULL;
	}
};

class Queue {
    Node* head;
    Node* tail;
    int size;
	// Define the data members
   public:

    Queue() {
        head=NULL;
        tail=NULL;
        size=0;
		// Implement the Constructor
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
        return size;
		// Implement the getSize() function
	}

    bool isEmpty() {
        return size==0;
		// Implement the isEmpty() function
	}

    void enqueue(int data) {
        Node * newNode=new Node(data);
        newNode->next=NULL;
        if (head!=NULL){
            tail->next=newNode;
            tail=newNode;
        }
        else{
            head=newNode;
            tail=newNode;
        } 
        size++;
		// Implement the enqueue() function
	}

    int dequeue() {
        if(size==0){
            return -1;
        }
        else{
            Node *a=head;
            head=head->next;
            int ans=a->data;
            delete a;
            size--;
            return ans;
        }
        

        // Implement the dequeue() function
    }

    int front() {
        if(size==0){
            return -1;
        }
        else{
            return head->data;
        }
        
        // Implement the front() function
    }
};