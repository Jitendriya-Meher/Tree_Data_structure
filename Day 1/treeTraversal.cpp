#include<iostream>
using namespace std;
#include<queue>

// structure of tree node
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
        // constructor
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree(){
    int data;
    cout<<" Enter the data : ";
    cin >> data;

    // -1 represent NULL
    if( data == -1){
        return NULL;
    }

    // if the value is not -1 (NULL) then create a new node
    Node* root = new Node(data);

    // now recursively bulid the left and right nodes of the root node
    cout<<" left node of "<<data<<endl;
    root->left = buildTree();

    cout<<"right node of "<<data<<endl;
    root->right = buildTree();

    // return the node
    return root;
}


// pre order travers
void preOrdTraversal(Node *root){
    // base case if root is NULL
    if( root == NULL ){
        return;
    }

    // NLR
    cout<<root->data<<" ";
    preOrdTraversal(root->left);
    preOrdTraversal(root->right);
}

// in order travers
void inOrdTraversal(Node *root){
    // base case if root is NULL
    if( root == NULL ){
        return;
    }

    // LNR
    inOrdTraversal(root->left);
    cout<<root->data<<" ";
    inOrdTraversal(root->right);
}

// post order travers
void postOrdTraversal(Node *root){
    // base case if root is NULL
    if( root == NULL ){
        return;
    }

    // LRN
    postOrdTraversal(root->left);
    postOrdTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){

    Node* root = buildTree();

    cout<<endl;

    // preorder traversal
    cout<<" preorder traversal : ";
    preOrdTraversal(root);
    cout<<endl;

    // inorder traversal
    cout<<" inorder traversal : ";
    inOrdTraversal(root);
    cout<<endl;

    // postorder traversal
    cout<<" postorder traversal : ";
    postOrdTraversal(root);
    cout<<endl;
}