#include<bits/stdc++.h>
using namespace std;

stack<int> copystack(stack<int> &input) {
        stack <int> temp;
        while(not input.empty()){
            temp.push(input.top());
            input.pop();
        }
        stack<int> result;
        while(not temp.empty()){
            result.push(temp.top());
            temp.pop();
        }
return result;
}

void copystackrecursive(stack<int> &input,stack<int> &result){
    if(input.empty()) return;
    int curr=input.top();
    input.pop();
    copystackrecursive(input,result);
    result.push(curr);
}

int main(){
    stack<int>input;
    input.push(1);
    input.push(2);
    input.push(3);
    input.push(4);

     stack <int> a;


    copystackrecursive(input,a);

    while (not a.empty()){
        cout<< a.top() <<endl;
        a.pop();
    }



return 0;
}