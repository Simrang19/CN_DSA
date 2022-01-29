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

Node *skipMdeleteN(Node *head, int M, int N)
{
    int c1=1;
    int c2=1;
    Node* temp=head;
    Node* temp2=head;
    if(M==0){
        return NULL;
    }
    
    while(temp!=NULL and temp2!=NULL){
        c1=1;
        c2=1;
        while(c1!=M and temp!=NULL){
            c1++;
            // head=head->next;
            temp=temp->next;
        }
        
        if(temp!=NULL){
            int g=0;
        }
        else{
            break;
        }
        temp2=temp->next;
        while(c2!=N and temp2 !=NULL){
            c2++;
            // head=head->next;
            Node* a=temp2;
            temp2=temp2->next;
            delete a;
        }
        if(temp2!=NULL){
            temp2=temp2->next;
        }
        else{
            temp->next=NULL;
            break;
        }
        
        temp->next=temp2;
        c1=1;
        c2=1;

    }
    return head;
	// Write your code here
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}
