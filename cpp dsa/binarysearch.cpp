#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> &v,int target){
    int lo=0;
    int hi=v.size()-1;

    while(lo<=hi){
        int mid= lo + (hi-lo)/2;

        if(v[mid]==target) return mid;

        else if (v[mid]<target) lo=mid+1;
        
        else hi=mid-1; 
    }
   
   return -10;    
    
}

int main(){
  int n;
  cin>>n;  
  vector<int> input;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    input.push_back(x);

  }
  int target;
  cin>>target;
  cout<<BinarySearch(input,target)<<endl;

}