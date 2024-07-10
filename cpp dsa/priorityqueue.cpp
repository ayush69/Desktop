#include <bits/stdc++.h>
using namespace std;

int largestElementAfterKop(vector<int> v, int n, int k){


    priority_queue<int> pq;

    for(auto ele:v){
        pq.push(ele);
    }
    while(k--){
        int first= pq.top();
        pq.pop();
        int second= pq.top();
        pq.pop();

        pq.push(first*second);
    }

    while(pq.size()>1){
        pq.pop();
    }

return pq.top();

}


int main(){




}