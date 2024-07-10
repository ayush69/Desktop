#include <iostream>
using namespace std;


class Node{
  public:  
     int val;
     Node* next;

     Node(int data){
        val=data;
        next=NULL;
     }
};

void insertAtHead(Node* &head,int val){
    Node* new_node= new Node(val);
    new_node->next=head;
    head=new_node;
}

void insertatTail( Node* &head ,int val){
    Node* new_node= new Node(val);
    Node* temp=head;
    while (temp!=NULL){
       temp=temp->next;
    }
    temp->next=new_node;
}

void display(Node* head){
    Node* temp=head;
    while (temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    

}

void insertAtposition(Node* head,int val,int pos){
    if (pos==0){
        insertAtHead(head,val);
        return;
    }
    Node* new_node= new Node(val);
    Node* temp=head;
    int curr_pos=1;
    while (curr_pos!=pos-1){
        temp=temp->next;
        curr_pos++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}

void updateAtPosition(Node* head,int val,int pos){
    Node* temp=head;
    int curr_pos=0;
    while (curr_pos!=pos){
        temp=temp->next;
        curr_pos++;
    }
    temp->val=val;
}

void deleteAthead(Node* head){
    Node* temp=head;
    head=head->next;
    free(temp);
}

void deleteAttail(Node*head){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* last=temp->next;
    temp->next=NULL;
    free(last);
}

void deleteAtposition(Node* head,int pos){
    if(pos==0){
        deleteAthead(head);
        return;
    }
    Node* temp=head;
    int currpos=0;
    while(currpos!=pos-1){
        temp=temp->next;
        currpos++;
    }
    Node* next=temp->next;
    temp->next=temp->next->next;
    free(next);

}

Node* mergetwosortedll(Node* head1,Node* head2){
    Node* dummyheadnode = new Node(-1);
    Node* ptr1= head1;
    Node* ptr2=head2;
    Node* ptr3=dummyheadnode;


    while(ptr1 && ptr2){
        if(ptr1->val < ptr2->val){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    if(ptr1){
        ptr3->next=ptr1;
    }
    else{
        ptr3->next=ptr2;
    }


    return dummyheadnode->next;
}

int main(){





    return 0;
}