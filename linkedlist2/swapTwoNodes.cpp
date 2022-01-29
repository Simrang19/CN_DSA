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

Node *swapNodes(Node *head, int i, int j)
{
    int i1=0;
    int j1=0;
    Node *h=head;
    Node *t1=head;
    Node *t2=head;
    Node *t3=head;
    Node *t4=head;
    Node *t5=head;
    if(i==0 || j==0){
        while(j1<j-1){
            j1++;
            t2=t2->next;
        }
        t3=t2->next;
        t5=t3->next;
        while(i1<i-1){
            i1++;
            t1=t1->next;
        }
        t4=t1->next;
        
        t2->next=t1;
        t3->next=t4;
        t1->next=t5;
        h=t3;
        
    }
    else{
        while(j1<j-1){
            j1++;
            t2=t2->next;
        }
        t3=t2->next;
        t5=t3->next;
        while(i1<i-1){
            i1++;
            t1=t1->next;
        }
        t4=t1->next;
        t1->next=t3;
        t2->next=t4;
        t3->next=t4->next;
        t4->next=t5;
    }
    return h;

    
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
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}