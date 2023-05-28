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


// for finding the index 
int findIndex( int *arr, int val, int size){
    // travers the array if the current index element is val then return the index
    for( int i=0; i<size; i++){
        if( arr[i] == val ){
            return i;
        }
    }
    return -1;
}

// buld tree function
 Node *bulidTreeFromPostOrderAndInOrder( int postOrder[], int inOrder[], int &postIndex, int inOrderStart, int inOrderEnd, int size){
    // base case
    // if postIndex is out of bounds
    // inorderstart exceeds inorderend
    if( postIndex < 0 || (inOrderStart > inOrderEnd)){
        return NULL;
    }

    // constuct the node for the element of postIndex
    int nodeVal = postOrder[postIndex];
    Node *root = new Node(nodeVal);

    // find the position of the preIndex element in inOrder array
    int pos = findIndex(inOrder, nodeVal, size);

    // update the index
    postIndex = postIndex - 1;

    // construct the left and right sub tree by bounding the inOder indices
    // rght then left
    root -> right = bulidTreeFromPostOrderAndInOrder(postOrder, inOrder, postIndex, pos+1, inOrderEnd, size);

    root -> left = bulidTreeFromPostOrderAndInOrder(postOrder, inOrder, postIndex, inOrderStart, pos-1, size);

    // return the node
    return root;
 }


int main(){
    int postOrder[] = {40,20,50,60,30,10};
    int inOrder[] = {40,20,10,50,30,60};

    int size = sizeof(inOrder)/sizeof(int);

    int postIndex = size -1;
    int inOrderStart = 0;
    int inOrderEnd = size -1;

    Node *root = bulidTreeFromPostOrderAndInOrder(postOrder, inOrder, postIndex, inOrderStart,inOrderEnd, size);

    cout<<endl<<" postOder: ";
    postOrdTraversal(root);

    cout<<endl<<" inOrder: ";
    inOrdTraversal(root);

    return 0;
}