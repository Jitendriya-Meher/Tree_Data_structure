#include<iostream>
using namespace std;
#include<queue>
#include<vector>

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

    void tree( Node* root, int tar, int &sum ,vector<int> &path, vector<vector<int>> &ans) 
    {
        if( root==NULL)
            return;
        
        sum += root->data;
        path.push_back( root->data);
        
        if( root->left==NULL && root->right==NULL && sum== tar)
        {
            ans.push_back(path);
        }
        
        tree( root->left,tar,sum,path,ans);
        tree( root->right,tar,sum,path,ans);

        sum -= root->data;
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(Node* root, int targetSum) {
        
        vector<vector<int>> ans;
        vector<int> path;
        int sum=0;

        tree( root, targetSum,sum,path,ans);
        
        return ans;       
    }

int main(){
    Node* root = buildTree();
    vector<vector<int>> ans = pathSum(root,40);

    cout<<endl<<" path sum : "<<endl;
    for( auto it: ans){
        for( auto it2: it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}