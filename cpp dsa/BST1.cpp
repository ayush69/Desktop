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

Node* insertBst(Node* root,int val){

    if(root==NULL){
        Node* newnode= new Node(val);
        return newnode;
    }


    if(root->value>val) root->left=insertBst(root->left,val);
    if(root->value<val) root->right=insertBst(root->right,val);

}

bool searchBst(Node* root,int key){

    if(root==NULL) return false;
    if(root->value==key) return true;
    if(root->value>key) return searchBst(root->left,key);
    if(root->value<key) return searchBst(root->right,key);

}


void deleteBst(Node* root,int val){

}

int main(){




}