#include <bits/stdc++.h>
using namespace std;

unordered_set<int> visited;

vector<vector<int>> allPaths;

vector<list<int>> graph;
int v;  //no. of vertices


void add_edge(int src, int dest, bool bi_directional=true){

    graph[src].push_back(dest);
    if(bi_directional){
        graph[dest].push_back(src);
    }
    
}


void display(){

    for(int i=0 ;i<graph.size();i++){

        cout<<i<<"-->";
        for(auto ele:graph[i]){
            cout<<ele<<" ";
        }

        cout<<endl;
    }



}

bool dfs(int curr,int dest){

    if(curr==dest) return true;
    visited.insert(curr);

    for(auto nr:graph[curr]){
        if(not visited.count(nr)){
            bool result=dfs(nr,dest);
            if(result) return true;
        }
        return false;
    }
}

bool anyPath(int src, int dest){
    return dfs(src,dest);
}

void dfsAllpath(int curr, int dest, vector<int>&path){
    if(curr==dest){
        path.push_back(curr);
        allPaths.push_back(path);
        path.pop_back();
        return;
    }

    visited.insert(curr);
    path.push_back(curr);

    for(auto nr:graph[curr]){
        if(not visited.count(nr)){
            dfsAllpath(nr,dest,path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}

void allPath(int src, int dest){

    vector<int> v;
    dfsAllpath(src,dest,v);
    //all the paths will be in the allPaths vector

}


int main(){

cin>>v;
graph.resize(v,list<int> ());


add_edge(0,1);
add_edge(0,4);
add_edge(0,7);
add_edge(1,3);
add_edge(3,4);
add_edge(1,5);
add_edge(5,6);
add_edge(2,6);
add_edge(2,5);

display();



}