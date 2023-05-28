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
 Node *bulidTreeFromPreOrderAndInOrder( int preOrder[], int inOrder[], int &preIndex, int inOrderStart, int inOrderEnd, int size){
    // base case
    // if preindex is out of bounds
    // inorderstart exceeds inorderend
    if( preIndex >= size || inOrderStart > inOrderEnd){
        return NULL;
    }

    // constuct the node for the element of preIndex
    int nodeVal = preOrder[preIndex];
    Node *root = new Node(nodeVal);

    // find the position of the preIndex element in inOrder array
    int pos = findIndex(inOrder, nodeVal, size);

    // update the index
    preIndex = preIndex + 1;

    // construct the left and right sub tree by bounding the inOder indices
    // left then right
    root -> left = bulidTreeFromPreOrderAndInOrder(preOrder, inOrder, preIndex, inOrderStart, pos-1, size);

    root -> right = bulidTreeFromPreOrderAndInOrder(preOrder, inOrder, preIndex, pos+1, inOrderEnd, size);

    // return the node
    return root;
 }


int main(){
    int preOrder[] = {10,20,40,50,30,60,70};
    int inOrder[] = {40,20,50,10,60,30,70};

    int size = sizeof(inOrder)/sizeof(int);

    int preIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = size -1;

    Node *root = bulidTreeFromPreOrderAndInOrder(preOrder, inOrder, preIndex, inOrderStart, inOrderEnd, size);

    cout<<endl<<" preOrder: ";
    preOrdTraversal(root);

    cout<<endl<<" inOrder: ";
    inOrdTraversal(root);

    return 0;
}