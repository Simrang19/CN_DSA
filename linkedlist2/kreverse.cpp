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

Node *reverseLinkedList(Node *head) {
    Node* pre=NULL;
    Node* cur=head;
    Node* nex=NULL;
    if(head==NULL){
        return NULL;
    }
    else{
        nex=cur->next;
    }
    while(cur!=NULL){
        nex=cur->next;
        cur->next=pre;
        pre=cur;
        
        cur=nex;
    }
    return pre;
    // Write your code here
}




Node *kReverse(Node *head, int k)
{
    Node *h=head;
    Node *t=head;
    Node *ph=head;
    Node *hu=head;
    int count=1;
    while(t!=NULL){
        while(count<k){
            count++;
            t=t->next;
        }
        h=t->next;
        t->next=NULL;
        if(hu==head){
            head=reverseLinkedList(head);
        }
        else{
            hu=reverseLinkedList(h);

        }
        
        hu->next=h;
        count=1;

    }
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
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}