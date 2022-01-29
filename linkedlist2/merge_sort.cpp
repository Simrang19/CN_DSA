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



Node *merge(Node *h1,Node *h2){
    Node *t=NULL;
    Node *h=NULL;
    if(h1==NULL){
        return h2;
    }
    if(h2==NULL){
        return h1;
    }
    while(h1!=NULL and h2!=NULL){
        if(h1->data<h2->data){
            if(t==NULL){
                t=h1;
                h=h1;
                h1=h1->next;
            }
            else{
                t->next=h1;
                t=t->next;
                h1=h1->next;
                
            }
        }
        else{
            if(t==NULL){
                t=h2;
                h=h2;
                h2=h2->next;
     
            }
            else{
                t->next=h2;
                h2=h2->next;
                t=t->next;
            }
        }
        
    }
    if(h1!=NULL){
        t->next=h1;
    }
    if(h2!=NULL){
        t->next=h2;
    }
    return h;

}

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


Node *breaking(Node*head){
    Node* slow=head;
    Node* fast=head;
    if(head==NULL ){
        return NULL;
    }
    while(fast->next->next!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node *mergeSort(Node *head)
{
    if ( head==NULL) {
        return NULL;
    }
    else if(head->next == NULL){
        return head;
    }
    
    Node *mid=breaking(head);
    Node *head2=mid->next;
    mid->next=NULL;
    Node *h1=mergeSort(head);
    Node * h2=mergeSort(head2);
    Node * newhead=mergeTwoSortedLinkedLists(h1,h2);
    // Node *finalhead=merge(mergeSort(head),mergeSort(head2));
    return newhead;
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
		head = mergeSort(head);
		print(head);
	}

	return 0;
}