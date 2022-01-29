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


Node *evenAfterOdd(Node *head)
{
    Node *oddh=NULL;
    Node *oddt=NULL;
    Node *evenh=NULL;
    Node *event=NULL;
    while(head!=NULL){
        if((head->data)%2==0){
            if(evenh==NULL){
                evenh=head;
                event=head;
                
                head=head->next;
            }
            else{
                event->next=head;
                head=head->next;
                event=event->next;
            }

        }
        else{
            if(oddh==NULL){
                
                oddh=head;
                oddt=head;
                head=head->next;
            }
            else{
                oddt->next=head;
                head=head->next;
                oddt=oddt->next;
            }
        }
    }
    if (oddh!=NULL){
        oddt->next=evenh;
    }
    else{
        return evenh;
    }
    if (event!=NULL){
        event->next=NULL;
    }
    
    


    return oddh;
	//write your code here
}

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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}