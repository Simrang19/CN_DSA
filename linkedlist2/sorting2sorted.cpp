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


Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    Node *hp=NULL;
    
    if(head1==NULL){
        hp=head2;
        return hp;
    }
    if(head2==NULL){
        hp=head1;
        return hp;
    }
    
    Node *tp=NULL;
    // int count=1; and count==1
    while(head1!=NULL and head2!=NULL){
        
        if(head1->data<head2->data){
            if(tp==NULL ){
            
                tp=head1;
                hp=head1;
                head1=head1->next;
                // count=0;
            }
            
            else{
                tp->next=head1;
                tp=tp->next;
                head1=head1->next;
                
                
            }
            
        
            
        }
        else{
            if(tp==NULL){
            
                tp=head2;
                hp=head2;
                head2=head2->next;
                // count=0;
                
            }
            else{
                tp->next=head2;
                tp=tp->next;
                head2=head2->next;
                
            }
            
            
        }

    }
   
    if(head1!=NULL){
        tp->next=head1;
        
    }
    if(head2!=NULL){
        tp->next=head2;
    }
    return hp;
    //Write your code here
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}