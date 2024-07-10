#include <bits/stdc++.h>
using namespace std;

int sumOfNdigits(int n){
    if(n>=0 && n<=9) return n;

    return (n%10)+sumOfNdigits(n/10);
}

int pTothePOWERq(int p,int q){
    if(q==0)  return 1;
    return p*pTothePOWERq(p,q-1);
}

int sumOfarray(int *arr,int idx,int n){
    if(idx==n-1) return arr[idx];

    return arr[idx]+sumOfarray(arr,idx+1,n);
}

string removeOccurence(string s,char ch){
    string result="";

}

void sequence(int n){
    if(n<1) return;
    
    sequence(n-1);
    cout<<n<<" ";
}

void kMultiples(int n,int k){
    if(k<1) return;

    kMultiples(n,k-1);
    cout<<n*k<<" ";
}

int alternateSignSum(int n){
    if(n==0) return 0; 
    return alternateSignSum(n-1)+((n%2==0) ? (-n):n);
}

int isArmstrong(int n,int d){
    if(n==0) return 0;
    int ans=pow(n%10,d)+isArmstrong(n/10,d);
    return ans;

}

bool presentOrNot(int *arr,int x,int idx,int n){

    if(idx==n) return false;
    return (arr[idx]==x) || presentOrNot(arr,x,idx+1,n);  
}

void printSumOfAllSubseq(int *arr,int idx,int n,int sum,vector<int>&result){
    if(idx==n){
     result.push_back(sum);
     return;
    }
    printSumOfAllSubseq(arr,idx+1,n,sum+arr[idx],result);
    printSumOfAllSubseq(arr,idx+1,n,sum,result);

}


int gridPath(int i,int j,int m,int n){
    if(i>=m || j>=n) return 0;
    if(i==m-1 && j==n-1) return 1;

    return gridPath(i,j+1,m,n) + gridPath(i+1,j,m,n);
}

void stringSubseq(string s,int i,string seq,vector<string> &v){
    if(i==s.length()) {
        v.push_back(seq);
        return;
    }
    stringSubseq(s,i+1,seq+s[i],v);
    stringSubseq(s,i+1,seq,v);


}

bool canWeGo(int i,int j,vector<vector<int>> &v){
    int n=v.size();
    return i>=0 && j>=0 && i<n && j<n && v[i][j]==1;
    
}

int ratInAMaze(int i,int j,vector<vector<int>> &v){

    int n=v.size();

    if(i==n-1 && j==n-1) return 1;

    int ans=0;

    v[i][j]=2;

    if(canWeGo(i,j+1,v)) ans+=ratInAMaze(i,j+1,v);
    if(canWeGo(i+1,j,v)) ans+=ratInAMaze(i+1,j,v);
    if(canWeGo(i,j-1,v)) ans+=ratInAMaze(i,j-1,v);
    if(canWeGo(i-1,j,v)) ans+=ratInAMaze(i-1,j,v);

    v[i][j]=1;

    return ans;


}




int main(){
vector<vector<int>> v={
    {1,1,1,1,0,1},
    {1,1,0,1,1,1},
    {0,1,1,1},
    {0,1,1,1}
};

cout<<ratInAMaze(0,0,v);


}