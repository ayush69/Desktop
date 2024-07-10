#include <bits/stdc++.h>
using namespace std;

class Node{
    public:

    int val;
    Node* left;
    Node* right;

    Node(int v){
        val=v;
        left=right=NULL;
    }
      
};

void preOrderTraversal(Node* root){

    if(root==NULL) return;

    cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){

    if(root==NULL) return;

    inOrderTraversal(root->left);
    cout<<root->val<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root==NULL) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->val<<" ";
    
}

void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();

        while(n--){
            Node* currNode=q.front();
            q.pop();
            cout<<currNode->val<<" ";

            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        cout<<endl;
    }
}

int maxDepth(Node* root){


    if(root==NULL) return 0;

    return 1+max(maxDepth(root->left),maxDepth(root->right));
}

int leafnodenumber(Node* root){


    if(root==NULL) return 0;    
    if(root->left==NULL && root->right==NULL) return 1;

    return leafnodenumber(root->left)+leafnodenumber(root->right);
}

void printRIghtmostNode(Node* root){
    if(root==NULL) return;

    cout<<root->val<<" ";
    printRIghtmostNode(root->right);


}

int main(){

Node* root= new Node(2);
root->left=new Node(4);
root->right=new Node(10);
root->left->left=new Node(6);
root->left->right=new Node(5);
root->right->right= new Node(11);
root->right->left=new Node(9);


printRIghtmostNode(root);

}