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

// LCA
Node* LCA( Node* root, Node* p, Node* q){
    // if NULL return NULL
    if( root == NULL )
         return NULL;
        
    // check if the current node is p or q
    if( root==p || root==q){
        return  root;
    }

    // traverse left and right subtrees
    Node* leftLCA = LCA(root->left, p, q);
    Node* rightLCA = LCA(root->right, p, q);

    // check for LCA
    if( leftLCA==NULL && rightLCA==NULL){
        return NULL;
    }
    else if( leftLCA!=NULL && rightLCA==NULL){
        return leftLCA;
    }
    else if( leftLCA==NULL && rightLCA!=NULL){
        return rightLCA;
    }
    else{
        return root;
    }
}

int main(){

    Node* root = buildTree();

    Node* p = root->left;
    Node* q = root->right;

    cout<<" LCA : "<<LCA(root,p,q)->data<<endl;
}