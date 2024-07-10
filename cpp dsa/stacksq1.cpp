#include<bits/stdc++.h>
using namespace std;


bool isBalanced(string brackets){
    stack<char> st;
    for (int i = 0; i < brackets.size() ; i++){
        char ch=brackets[i];

        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else if(!st.empty() && ch==')' && st.top()=='('){
            st.pop();
        }
        else if(!st.empty() && ch=='}' && st.top()=='{'){
            st.pop();
        }
        else if(!st.empty() && ch==']' && st.top()=='['){
            st.pop();
        }
        else return false;
    }
    
    return st.empty();
}

int main(){
    string str="()(){}[][{}]";
    cout<<isBalanced(str)<<endl;

}