#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int x){

    //if(parent[x]==x) return x;

    return parent[x]=((parent[x]==x) ? x : find(parent,parent[x]));

}


void Union(vector<int>&rank, vector<int>&parent, int a, int b){
    a=find(parent,a);
    b=find(parent,b);

    if(rank[a]<rank[b]){
        rank[b]++;
        parent[a]=b;
    }
    else{
        rank[a]++;
        parent[b]=a;
    }
}

int main(){




}