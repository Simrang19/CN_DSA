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

Node *appendLastNToFirst(Node *head, int n)
{
	if (head==NULL){
        return NULL;
    }
    Node *temp=head;
    Node *j=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
	temp=head;
	while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
	temp->next=head;
    int f=count-n-1;
    temp=head;
    while(f){
        f--;
        temp=temp->next;
    }
    head=temp->next->next;
	temp=head;
	while(count--){
		temp=temp->next;
	}
	temp->next=NULL;
    // temp=head;
    // int l=1;
    // while(l<n){
    //     temp=temp->next;
    //     l--;
    // }
    // temp->next=j;
    
    
    return head;
    //Write your code here
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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}

