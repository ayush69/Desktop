#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node(int datainput){
        value=datainput;
        next=NULL;
    }
};

class LinkedList{
public:

Node* head=NULL;


LinkedList(){
    head=NULL;
}

void insertatTail(int x){

    Node* newnode = new Node(x);

    if(head==NULL){
        head=newnode;
        return;
    }

    Node* temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
} 

void display(){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->value<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


};


bool equalornot(Node* &head1,Node* &head2){
    
    Node* temp1=head1;
    Node* temp2=head2;
    
    while(temp1 && temp2 ){
        if(temp1->value!=temp2->value){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
return (!temp1 && !temp2);

}

int getlength(Node* head){
    Node* ptr=head;
    int length=0;
    while(ptr){
        length+=1;
        ptr=ptr->next;
    }
    return length;
}

Node* moveheadbyk(Node* head,int k){
    Node* ptr=head;
    while(k--){
        ptr-ptr->next;
    }
    return ptr;
}

Node* getintersection(Node* head1,Node* head2){
    int l1 = getlength(head1);
    int l2 = getlength(head2);

    Node* ptr1, *ptr2;

    if(l1>l2){
        ptr1=moveheadbyk(head1,l1-l2);
        ptr2=head2;
    }
    else{
        ptr2=moveheadbyk(head2,l2-l1);
        ptr1=head1;
    }

    while(ptr1){
        if(ptr1 == ptr2){
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return NULL;

}


int main(){

    LinkedList list1;
    list1.insertatTail(5);
    list1.insertatTail(68);
    list1.insertatTail(87);

    LinkedList list2;
    list2.insertatTail(1);
    list2.head->next=list1.head->next;


   cout<<(getintersection(list1.head,list2.head))->value;
    

}