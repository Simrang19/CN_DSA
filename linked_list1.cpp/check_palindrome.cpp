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


// bool isPalindrome(Node *head)
// {
//     if(head==NULL){
//         return 1;
//     }
//     Node*temp=head;
//     int count=0;
//     while(temp!=NULL){
//         count++;
//         temp=temp->next;
//     }
//     int n=count;
//     int mid=(n+1)/2;
//     temp=head;
//     int h=0;
//     while(h<mid){
//         temp=temp->next;
//         h++;
//     }
//     Node *pp=temp;
//     Node*temp2=head;
//     int y=0;
//     int j=mid-1;
//     int u;
//     int g;
//     if (n%2==0){
//     	g=mid;
//     }
//     else{
//     	g=mid-1;
//     }
//     while (y<g){
//         y++;
//         u=j;
//         while(u ){
//             u--;
//             temp=temp->next;
//         }
//         if(temp->data==temp2->data){
//             temp2=temp2->next;
//             j--;
//             temp=pp;
//         }
//         else{
//             return 0;
//         }
//     }
//     return 1;
//     //Write your code here
// }

//op solution ta

Node *reverseLinkedList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *fwd = NULL;
    while (curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}


bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    // Find center of list
    Node *fast = head;
    Node *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *secondHead = slow->next;
    slow->next = NULL;
    secondHead = reverseLinkedList(secondHead);
    //Compare the two sublists
    Node *firstSubList = head;
    Node *secondSubList = secondHead;
    bool ans = true;
    while (secondSubList != NULL)
    {
        if (firstSubList->data != secondSubList->data)
        {
            ans = false;
            break;
        }
        firstSubList = firstSubList->next;
        secondSubList = secondSubList->next;
    }
    // //Rejoin the two sublists
    // firstSubList = head;
    // secondSubList = reverseLinkedList(secondHead);
    // while(firstSubList->next != NULL)
    // {
    //     firstSubList = firstSubList->next;
    // }
    // firstSubList->next = secondSubList;
    return ans;
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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}