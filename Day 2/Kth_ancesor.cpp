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



bool LCA( Node *root, int &k, int node, int &ans){
    // if root return false
    if( root == NULL){
        return false;
    }

    // check if the root is node
    if( root->data == node){
        // ans = root->data;
        return true;
    }
    
    // traverse tree
    bool leftLCA = LCA(root->left,k,node,ans);
    bool rightLCA = LCA(root->right,k,node,ans);
    
    // check if its a LCA or not
    bool isLCA = leftLCA || rightLCA;
    
    // for finding the k'th ancestor
    if( isLCA){
        k--;
        if( k==0){
            ans = root->data;
        }
    }
    
    return isLCA;
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    bool find = LCA(root,k,node,ans);
    return ans;
}

int main(){
    Node *root = buildTree();
    int k = 1;
    int node = 20;

    cout<<" K'th ancestor is : "<<kthAncestor(root,k,node)<<endl;
}
