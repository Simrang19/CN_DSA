#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;

template <typename T>
class BSTTreeNode {
   public:
    T data;
    BSTTreeNode<T>* left;
    BSTTreeNode<T>* right;

    BSTTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Node {
    	public :
    	BSTTreeNode<int>* data;
    	Node *next;

    	Node(BSTTreeNode<int>* data) {
        	this->data = data;
        	next = NULL;
    	}
	};

class Queue {
    Node* head;
    Node* tail;
    int size;
	
public:
    Queue() {
        head=NULL;
        tail=NULL;
        size=0;
	}
    bool empty() {
        return (size==0);
	}
    void enqueue(BSTTreeNode<int>* data) {
        Node* newnode= new Node(data);
        if(head==NULL){
            head= newnode;tail=newnode;
        }else{
            tail->next = newnode;
        	tail=newnode;
        }
        size++;
	}
    void dequeue() {
        if(size==0){
            return ;
        }
        BSTTreeNode<int>* ans = head->data;
        Node* newnode = head->next;
        delete [] head;
        head= newnode;
        size--;
        return;
        
    }
    BSTTreeNode<int>* front() {
        if(size==0){
            return NULL;
        }
        return head->data;
    }
};


// BST Implementation Start
class BST {
    // Define the data members
    BSTTreeNode<int>* root;
    private:
    BSTTreeNode<int>* remove_aux(int data,BSTTreeNode<int>* node)
    {
        if(node==NULL)
        {
            return NULL;
        }
        if(data < node->data)
        {
            node->left = remove_aux(data,node->left);
            return node;
        }
        if(data > node->data)
        {
           node->right =  remove_aux(data,node->right);
            return node;
        }
        else
        {
            if(node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            if(node->left == NULL)
            {
                BSTTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            if(node->right == NULL)
            {
                BSTTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
               BSTTreeNode<int>* minNode = node->right;
                while(minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = remove_aux(rightMin,node->right);
                return node;
            }
        }
      
    }
    bool search_aux( int data, BSTTreeNode<int>* node)
    {
        if(node==NULL)
        {
            return false;
        }
        if(node->data == data)
        {
            return true;
        }
        else if(data<node->data)
        {
            return search_aux(data,node->left);
        }
        else
        {
            return search_aux(data,node->right);
        }
    }
    BSTTreeNode<int>* insert_aux(int data, BSTTreeNode<int>* node)
    {
        if(node == NULL)
        {
            BSTTreeNode<int>* newNode = new BSTTreeNode<int>(data);
            return newNode;
        }
        if(data <= node->data)
        {
            node->left = insert_aux(data,node->left);
        }
        else
        {
            node->right = insert_aux(data,node->right);
        }
        return node;
    }
    int height_aux(BSTTreeNode<int>* root) {
        if(root==NULL){
            return 0;
        }else if(root->left==NULL & root->right==NULL){
            return 1;
        }
        int h1 = height_aux(root->left),h2= height_aux(root->right);
        return (1+max(h1,h2));
    }
    void printLevelWise_aux(BSTTreeNode<int> *root) {
        if(root==NULL){
            return;
        }

        // We have used the queue which is implemented
        // by us only above this BST class
        Queue q;
        q.enqueue(root);
        while(!q.empty()){
            BSTTreeNode<int>* front = q.front();
            q.dequeue();
            cout<<front->data<<" ";
            if(front->left!=NULL){
                q.enqueue(front->left);
            }
            if(front->right!=NULL){
                q.enqueue(front->right);
            }
        }
        return;
    }
    
    void preOrder_aux(BSTTreeNode<int> *root) {
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preOrder_aux(root->left);
        preOrder_aux(root->right);
        return;
    }
    void postOrder_aux(BSTTreeNode<int> *root) {
        if(root==NULL){
            return;
        }
        postOrder_aux(root->left);
        postOrder_aux(root->right);
        cout<<root->data<<" ";
        return;
    }
    void inorder_aux(BSTTreeNode<int> *root){
        if (root == NULL)
            return;
        inorder_aux(root->left);
        cout << root->data << " ";
        inorder_aux(root->right);
        return;
    }


    /*----------------- Public Functions -----------------*/
   public:
    BST() { 
        root = NULL;
    }

    void remove(int data) { 
        this->root = remove_aux(data,this->root);
    }

    int height() {
        return height_aux(this->root);
    }

    void insert(int data) { 
       this->root =  insert_aux(data,this->root);
    }

    bool search(int data) {
		// Implement the search() function 
        return search_aux(data,root);
    }
    void printLevelWise() {
        printLevelWise_aux(this->root);
        return;
    
    }
    void preOrder() {
        preOrder_aux(this->root);
        return;
    }

    void postOrder() {
        postOrder_aux(this->root);
        return;
    }
    void inorder(){
        inorder_aux(this->root);
        return;
    }
};

int main() {
    BST binary_search_tree;
    binary_search_tree.insert(1);
    binary_search_tree.insert(2);
    binary_search_tree.insert(4);
    binary_search_tree.insert(3);
    binary_search_tree.insert(8);
    binary_search_tree.insert(4);
    binary_search_tree.insert(5);
    binary_search_tree.insert(6);
    binary_search_tree.insert(9);

    // Height of BST 
    cout<<"Height of BST: ";
    cout<< binary_search_tree.height()<<endl;

    // PreOrder Traversal
    cout<<"Pre order wise: ";
    binary_search_tree.preOrder();
    cout<<endl;

    // InOrder Traversal
    cout<<"Inorder order wise: ";
    binary_search_tree.inorder();
    cout<<endl;

    // PostOrder Traversal
    cout<<"Post order wise: ";
    binary_search_tree.postOrder();
    cout<<endl;

    // Print level wise 
    cout<<"Level order wise: ";
    binary_search_tree.printLevelWise();
    cout<<endl;

    

    // Search for node with data "8" in our BST 
    if(binary_search_tree.search(8)){
        cout<<"Yes, node with value 8 is present "<<endl;
    }
    else{
        cout<<"Node with value 8 is not present "<<endl;
    }
    
    // Delete the node with data 8 in our BST 
    binary_search_tree.remove(8);
    cout<<"Node with value 8 is deleted from our BST "<<endl;

    // Search for node with data "8" in our BST 
    if(binary_search_tree.search(8)){
        cout<<"Yes, node with value 8 is present "<<endl;
    }
    else{
        cout<<"Node with value 8 is not present "<<endl;
    }

    // Print level wise 
    cout<<"Print level order wise: ";
    binary_search_tree.printLevelWise();
    cout<<endl;
    return 0;
}