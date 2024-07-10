#include<bits/stdc++.h>
using namespace std;

vector <int> nge(vector<int> &v){
    vector<int> res(v.size(),-1);
    stack<int> st;
    st.push(0);

    for (int i = 1; i < v.size(); i++){
        while(!st.empty() && v[i]>v[st.top()]){
            res[st.top()]=v[i];
            st.pop();
        }
        st.push(i);
    }
    

}

vector <int> nse(vector<int> &v){
    vector<int> res(v.size(),-1);
    stack<int> st;
    st.push(0);

    for (int i = 1; i < v.size(); i++){
        while(!st.empty() && v[i]<v[st.top()]){
            res[st.top()]=v[i];
            st.pop();
        }
        st.push(i);
    }

    
}

vector<int> stockspan(vector<int> &stock){
    vector<int> span(stock.size(),1);
    stack<int> st;
    st.push(0);

    for (int i = 0; i < stock.size(); i++){
        while(stock[st.top()] <= stock[i] && !st.empty()){
            span[st.top()]+=1;
            st.pop();
        }
        st.push(i);
    }
    
return span;
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

  for(int i=0;i<n;i++){
    cout<<input[i]<<" ";
  }


  vector<int> v = stockspan(input);

  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }

  
return 0;  
}