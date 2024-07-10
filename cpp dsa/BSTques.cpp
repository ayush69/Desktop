#include <bits/stdc++.h>
using namespace std;

class Node{
    public:

    int value;
    Node* left;
    Node* right;

    Node(int val){
        value=val;
        left=right=NULL;
    }
};

class bst{
    public: 

    Node* root;

    bst(){
        root=NULL;
    }
};

Node* sortedArrayToBst(vector<int> v,int start,int end){

    if(start>end) return NULL;

    int mid= (start+end)/2;

    Node* newnode = new Node(v[mid]);

    newnode->left= sortedArrayToBst(v,start,mid-1);
   
    newnode->right=sortedArrayToBst(v,mid+1,end);

    return newnode;
}


bool bstOrNot(Node* root){

    bool ans=false;

    if(root->left && root->right ){
        if(((root->value) > (root->left->value)) && ((root->value) < (root->right->value))){
            ans=true;
        }
    }

    else if(root->left){
        if(root->value > root->left->value){
            ans=true;
        }
    }

    else if(root->right){
        if(root->value > root->right->value){
            ans=true;
        }
    }

    
    ans = bstOrNot(root->left) && bstOrNot(root->right);

    return ans;

     
}

Node* removeAllLeafNodesBst(Node* root){

    if(root==NULL) return NULL; 

    if(root->left==NULL && root->right==NULL) return NULL;

    root->left=removeAllLeafNodesBst(root->left);
    root->right=removeAllLeafNodesBst(root->right);

    return root;

}

int main(){



}