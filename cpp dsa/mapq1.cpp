#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<string> v(n);

    for(int i=0; i<n ; i++){
        cin>>v[i];
    }

    map<char,int>m;

    for(int i=0; i<n;i++){
        for(auto ch : v[i] ){
            m[ch]++;
        }
    }

    int count=0;

    for(auto itr:m){
        if(itr.second % n==0){
           count+=1;
        }
    }

    if(count==n){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    }












