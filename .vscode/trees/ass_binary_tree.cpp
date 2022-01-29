#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


class Node {
    	public :
    	BinaryTreeNode<int>* data;
    	Node *next;

    	Node(BinaryTreeNode<int>* data) {
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
    void enqueue(BinaryTreeNode<int>* data) {
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
        BinaryTreeNode<int>* ans = head->data;
        Node* newnode = head->next;
        delete [] head;
        head= newnode;
        size--;
        return;
        
    }
    BinaryTreeNode<int>* front() {
        if(size==0){
            return NULL;
        }
        return head->data;
    }
    int getsize(){
        return size;
    }
};


// CBT Implementation Start
class CBT {
    BinaryTreeNode<int>* root;
    private:
    BinaryTreeNode<int>* get_last_node(BinaryTreeNode<int>* cur)
    {
        Queue q;
        q.enqueue(cur);

        BinaryTreeNode<int>* last_node = NULL;
        while(!q.empty())
        {
            int cur_size = q.getsize(); 
            last_node = q.front();
            q.dequeue();

            while(cur_size--)
            {
                if (last_node->left)
                    q.enqueue(last_node->left);
                if (last_node->right)
                    q.enqueue(last_node->right);
            }
        }
        return last_node;
    } 
    void delete_last_aux(BinaryTreeNode<int>*root, BinaryTreeNode<int>* del_node){
        Queue q;
        q.enqueue(root);

        while(!q.empty())
        {
            BinaryTreeNode<int>* cur_node = q.front();
            q.dequeue();

            if (cur_node == del_node)
            {
                cur_node = NULL;
                delete del_node;
                return;
            }

            if (cur_node->left && cur_node->left == del_node)
            {
                cur_node->left = NULL;
                delete del_node;
                return;
            }

            if (cur_node->left && cur_node->left != del_node)
                q.enqueue(cur_node->left);

            if (cur_node->right && cur_node->right == del_node)
            {
                cur_node->right = NULL;
                delete del_node;
                return;
            }    

            if (cur_node->right && cur_node->right != del_node)
                q.enqueue(cur_node->right);
        }
    }
    BinaryTreeNode<int>* remove_aux(int data,BinaryTreeNode<int>* root)
    {
        BinaryTreeNode<int>* aux = root;
        Queue q2; 
        q2.enqueue(root); 
        BinaryTreeNode<int>* temp=NULL;
        BinaryTreeNode<int>* key_node = NULL; 
        BinaryTreeNode<int>* prev = NULL;
        while (!q2.empty()) 
        { 
            temp = q2.front(); 
            q2.dequeue(); 
    
            if (temp->data == data){
                key_node = temp; 
                break;
            }

            if (temp->left!=NULL) 
                q2.enqueue(temp->left); 
    
            if (temp->right != NULL) 
                q2.enqueue(temp->right); 
        } 
        if(key_node ->left==NULL && key_node->right==NULL && key_node==root){
            delete key_node;
            return NULL;
        }

        BinaryTreeNode<int>* last_node = get_last_node(aux);
        if(key_node==last_node){
            delete_last_aux(root,key_node);
            return aux;
        }else{
            key_node->data = last_node->data;
            delete_last_aux(root,last_node);
            return aux;
        }
      
    }
    bool search_aux( int data, BinaryTreeNode<int>* node)
    {
        if(node==NULL)
        {
            return false;
        }
        if(node->data == data)
        {
            return true;
        }
        else
        {
            bool small1 = search_aux(data,node->left);
            bool small2 = search_aux(data,node->right);
            return (small1|small2);
        }
    }
    BinaryTreeNode<int>* insert_aux(int data, BinaryTreeNode<int>* root){
        if (root==NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }else{
            BinaryTreeNode<int>* new_node = new BinaryTreeNode<int>(data);
            Queue q;
            q.enqueue(root);
            while (!q.empty()){
                int cur_size = q.getsize();
                while (cur_size--){
                    BinaryTreeNode<int>* cur_root = q.front();
                    q.dequeue();

                    if (cur_root->left){
                        q.enqueue(cur_root->left);
                    }else{
                        cur_root->left = new_node;
                        return root;
                    }

                    if (cur_root->right){
                        q.enqueue(cur_root->right);
                    }else 
                    {
                        cur_root->right = new_node;
                        return root;
                    }
                }
            }
            return root;
        }
    }
    int height_aux(BinaryTreeNode<int>* root) {
        if(root==NULL){
            return 0;
        }else if(root->left==NULL & root->right==NULL){
            return 1;
        }
        int h1 = height_aux(root->left),h2= height_aux(root->right);
        return (1+max(h1,h2));
    }
    void printLevelWise_aux(BinaryTreeNode<int> *root) {
        if(root==NULL){
            return;
        }
        // We have used the queue which is implemented
        // by us only above this BST class
        Queue q;
        q.enqueue(root);
        while(!q.empty()){
            BinaryTreeNode<int>* front = q.front();
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
    void preOrder_aux(BinaryTreeNode<int> *root) {
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preOrder_aux(root->left);
        preOrder_aux(root->right);
        return;
    }
    void postOrder_aux(BinaryTreeNode<int> *root) {
        if(root==NULL){
            return;
        }
        postOrder_aux(root->left);
        postOrder_aux(root->right);
        cout<<root->data<<" ";
        return;
    }
    void inorder_aux(BinaryTreeNode<int> *root){
        if (root == NULL)
            return;
        inorder_aux(root->left);
        cout << root->data << " ";
        inorder_aux(root->right);
        return;
    }


    /*----------------- Public Functions -----------------*/
   public:
    CBT() { 
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
       return;
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
    CBT complete_binary_tree;
    complete_binary_tree.insert(10);
    complete_binary_tree.insert(11);
    complete_binary_tree.insert(12);
    complete_binary_tree.insert(13);
    complete_binary_tree.insert(14);

    // Print level wise 
    cout<<"Print level order wise: ";
    complete_binary_tree.printLevelWise();
    cout<<endl;

    // PreOrder Traversal
    cout<<"Print Pre order wise: ";
    complete_binary_tree.preOrder();
    cout<<endl;

    // PostOrder Traversal
    cout<<"Print Post order wise: ";
    complete_binary_tree.postOrder();
    cout<<endl;

    // InOrder Traversal
    cout<<"Print Inorder order wise: ";
    complete_binary_tree.inorder();
    cout<<endl;

    // Height of our BST 
    cout<<"Height of our BST: ";
    cout<< complete_binary_tree.height()<<endl;

    if(complete_binary_tree.search(10)){
        cout<<"Yes, node with value 10 is present "<<endl;
    }
    else{
        cout<<"Node with value 10 is not present "<<endl;
    }

    // Delete the node with data 10 in our BST 
    complete_binary_tree.remove(10);
    cout<<"Node with value 10 is deleted from our BST"<<endl;

    if(complete_binary_tree.search(10)){
        cout<<"Yes, node with value 10 is present "<<endl;
    }
    else{
        cout<<"Node with value 10 is not present "<<endl;
    }

    // Print level wise 
    cout<<"Print level order wise: ";
    complete_binary_tree.printLevelWise();
    cout<<endl;
    return 0;
}

















// #include <iostream>
// using namespace std;

// template <typename T>
// class BinaryTreeNode {
// 	public:
// 	T data;
// 	BinaryTreeNode* left;
// 	BinaryTreeNode* right;

// 	BinaryTreeNode(T data) {
// 		this->data = data;
// 		left = NULL;
// 		right = NULL;
// 	}

// 	~BinaryTreeNode() {
// 		delete left;
// 		delete right;
// 	}
// };

// template <typename T>
// class Node {
//     public :
// 	T data;
// 	Node *next;
// 	Node(T data) {
//     	this->data = data;
//     	next = NULL;
// 	}
// };

// template <typename T>
// class queue {
//     Node<T>* head;
//     Node<T>* tail;
//     int size;
// 	// Define the data members
//     public:

//     queue() {
//         head=NULL;
//         tail=NULL;
//         size=0;
// 		// Implement the Constructor
// 	}
	
// 	/*----------------- Public Functions of Stack -----------------*/

// 	int fsize() {
//         return size;
// 		// Implement the getSize() function
// 	}

//     bool isEmpty() {
//         return size==0;
// 		// Implement the isEmpty() function
// 	}

//     void push(T data) {
//         Node<T> * newNode=new Node<T>(data);
//         newNode->next=NULL;
//         if (head!=NULL){
//             tail->next=newNode;
//             tail=newNode;
//         }
//         else{
//             head=newNode;
//             tail=newNode;
//         } 
//         size++;
// 		// Implement the enqueue() function
// 	}

//     void pop() {
//         if(size==0){
//             return ;
//         }
//         else{
//             Node<T> *a=head;
//             head=head->next;
//             T ans=a->data;
//             delete a;
//             size--;
//             return;
//         }
        

//         // Implement the dequeue() function
//     }

//     T front() {
//         if(size==0){
//             return NULL;
//         }
//         else{
//             return head->data;
//         }
        
//         // Implement the front() function
//     }
// };


// BinaryTreeNode<int>* takeInputLevelWise() {
// 	int rootData;
// 	cout << "Enter root data" << endl;
// 	cin >> rootData;
// 	if (rootData == -1) {
// 		return NULL;
// 	}

// 	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

// 	queue<BinaryTreeNode<int>*> pendingNodes;
// 	pendingNodes.push(root);
// 	while (!pendingNodes.isEmpty()) {
// 		BinaryTreeNode<int>* front = pendingNodes.front();
// 		pendingNodes.pop();
// 		cout << "Enter left child of " << front->data << endl;
// 		int leftChildData;
// 		cin >> leftChildData;
// 		if (leftChildData != -1) {
// 			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
// 			front->left = child;
// 			pendingNodes.push(child);
// 		}
// 		cout << "Enter right child of " << front->data << endl;
// 		int rightChildData;
// 		cin >> rightChildData;
// 		if (rightChildData != -1) {
// 			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
// 			front->right = child;
// 			pendingNodes.push(child);
// 		}
// 	}
// 	return root;
// }


// void printLevelWise(BinaryTreeNode<int> *root) {
//     queue <BinaryTreeNode<int>*> q;
//     if(root==NULL){
//         return;
//     }
//     q.push(root);
//     while(!q.isEmpty()){
//         BinaryTreeNode<int> *temp =q.front();
//         q.pop();
//         cout<<temp->data<<":L:";
        
        
//         if(temp->left!=NULL){
//             cout<<temp->left->data;
//             q.push(temp->left);
//         }
//         else{
//             cout<<-1;
//         }
//         if(temp->right!=NULL){
//             cout<<",R:"<<temp->right->data<<endl;
//             q.push(temp->right);
//         }
//         else{
//             cout<<",R:"<<-1<<endl;
//         }
        
//     }
// 	// Write your code here
// }


// void preOrder(BinaryTreeNode<int> *root) {
//     if(root==NULL){
//         return;
//     }
//     cout<<root->data<<" ";
//     preOrder(root->left);
//     preOrder(root->right);
    
// 	// Write your code here
// }

// void postOrder(BinaryTreeNode<int> *root) {
//     if(root==NULL){
//         return;
//     }
    
//     postOrder(root->left);
//     postOrder(root->right);
//     cout<<root->data<<" ";
// 	// Write your code here
// }


// void inOrder(BinaryTreeNode<int> *root) {
//     if(root==NULL){
//         return;
//     }
    
//     inOrder(root->left);
//     cout<<root->data<<" ";
//     inOrder(root->right);
    
// 	// Write your code here
// }



// int main() {
// 	BinaryTreeNode<int>* root = takeInputLevelWise();
// 	printLevelWise(root);
// 	inOrder(root);
// 	postOrder(root);
// 	preOrder(root);
// 	delete root;
// }