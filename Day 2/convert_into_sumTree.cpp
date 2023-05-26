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

// LOT with levels
void printLOT_2( Node* root){
    // if root is NULL then return
    if( root == NULL ){
        return;
    }

    cout<<" Level order Traversal : "<<endl;

    // in level order travers , we trevese the tree level wise in FIFO order
    // so we need a queue
    queue<Node*> q;
    q.push( root );
    // marker as NULL for endl
    q.push( NULL );

    // traverse the queue until it is empty
    while( !q.empty()){
        // pop the front node and push it children if exists
        Node *temp = q.front();
        q.pop();

        if( temp == NULL){
            // print endl
            cout<<endl;
            // check if queue is not empty then push NULL for marker
            if( !q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            // push its children if it exists
            if( temp->left){
                q.push(temp->left);
            }
            if( temp->right){
                q.push(temp->right);
            }
        }
    }
    cout<<endl;
}

// convert to sum tree
int sumTree(Node* &root){
    // if NULL return 0 as it doesn't have any subtree 
    if( root==NULL ){
        return 0;
    }

    // traverse its children
    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    // conver the current node to sum Node
    int oldSum = root->data;
    int newSum = oldSum + leftSum + rightSum;
    root->data = newSum;

    // return the new sum Node
    return newSum;
}


int main(){
    Node* root = buildTree();

    printLOT_2(root);

    int ans = sumTree(root);

    printLOT_2(root);
}