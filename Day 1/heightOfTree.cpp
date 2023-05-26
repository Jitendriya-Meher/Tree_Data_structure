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

// height of the tree
int height( Node* root){
    // base case 
    // if root is NULL then its height is 0
    if( root== NULL){
        return 0;
    }

    // find the the height of the left subtree and the right subtree
    int leftSubtreeHeight = height(root->left);
    int rightSubtreeHeight = height(root->right);

    // find the maximal height of the sub tree and add the current root height as 1
    int currentHeight = max( leftSubtreeHeight, rightSubtreeHeight) + 1;

    return currentHeight;
}

int main(){

    Node* root = buildTree();

    cout<<" heiht of the tree is "<<height(root)<<endl;

    return 0;

}