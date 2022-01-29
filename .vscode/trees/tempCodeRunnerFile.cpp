
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