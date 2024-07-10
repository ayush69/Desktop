#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;

    node(int input){
        data=input;
        left=right=NULL;
    }

};

void insertMaxheap(vector <int> v, int &size, int input){
    size++;
    v[size]=input;
    int curr=size;
    while(curr/2>0 && v[curr/2]<v[curr]){
        swap(v[curr/2],v[curr]);
        curr=curr/2;
    }


}

void insertMinHeap(vector<int> v, int &size, int input){
    size++;
    v[size]=input;
    int curr=size;

    while(curr/2 > 0 && v[curr/2]>v[curr]){
        swap(v[curr/2],v[curr]);
        curr=curr/2;
    }

}

void deleteMaxHeap(vector<int> v, int &size){
    v[1]=v[size];
    size--;
    int curr=1;

    while(2*curr <= size){

        int leftchild=2*curr;
        int rightchild=2*curr+1;
        int maxchild=leftchild;

        if(rightchild<=size && v[rightchild]>v[leftchild]) maxchild=rightchild;

        if(v[maxchild] <= v[curr]) return;

        swap(v[curr],v[maxchild]);
        curr=maxchild;
    }   
}

void deleteMinHeap(vector<int> v, int &size){
    
    v[1]=v[size];
    size--;
    int curr=1;

    while(2*curr <= size){
        int leftchild=2*curr;
        int rightchild=2*curr+1;
        int minchild=leftchild;

        if(rightchild<=size && v[rightchild]<v[leftchild]) minchild=rightchild;

        if(v[curr] <= v[minchild]) return;

        swap(v[curr],v[minchild]);
        curr=minchild;
    }
}


void heapifyToMaxHeap(int arr[], int &size, int curr){

   while(2*curr <= size){
    int leftchild=2*curr;
    int rightchild=2*curr+1;
    int maxchild=leftchild;

    if(rightchild<=size && arr[maxchild]<arr[rightchild]) maxchild=rightchild;

    if(arr[maxchild]<arr[curr]) return;

    swap(arr[maxchild],arr[curr]);
    curr=maxchild;
   }
}



void heapifyToMinHeap(int arr[], int &size, int curr){
    while(2*curr <= size){
        int leftchild=2*curr;
        int rightchild=2*curr+1;
        int minchild=leftchild;

        if(rightchild<=size && arr[minchild]>arr[rightchild]) minchild=rightchild;

        if(arr[minchild]>arr[curr]) return;

        swap(arr[minchild],arr[curr]);
        curr=minchild;
    }
}

void remove(int arr[], int &size){
    swap(arr[1],arr[size]);
    size--;
    heapifyToMaxHeap(arr,size,1);
}

void heapSort(int arr[], int size){
    for(int i=size/2; i<=0; i--){
        heapifyToMaxHeap(arr,size,i);
    }

    while(size>0){
        remove(arr,size);
    }
}

int main(){




}