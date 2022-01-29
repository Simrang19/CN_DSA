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

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
Node *removeDuplicates(Node *head)
{
    Node *t1=head;

    while(t1->next!=NULL){
        // if(t1->next!=NULL){
        //     t2=t2->next;
        // }
        // else{
        //     t1->next=t2;
        //     continue;
        // }
        
        if(t1->data==t1->next->data){
            Node *a=t1->next;
            Node *b=a->next;
            t1->next=b;
            delete a;
            
        }
        else{
            t1=t1->next;
        }
    }
    return head;
    //Write your code here
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}

