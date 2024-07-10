#include<bits/stdc++.h>
using namespace std;


bool checkAnagrams(string s1,string s2){
    if(s1.length()!=s2.length()){
        return false;
    }

    unordered_map<char,int> m;
    for(auto ch1:s1){
        m[ch1]++;
    }
    for(auto ch2:s2){
        if(m.find(ch2)==m.end()){
            return false;
        }
        else{
            m[ch2]--;
        }
    }
    for(auto pair:m){
        if(pair.second!=0){
            return false;
        }
    }
    return true;
}


bool checkNoOnetoManyOneMapping(string s1,string s2){

    unordered_map<char,char> m;
    for(int i=0;i<s1.length();i++){
        if(m.find(s1[i])!=m.end()){
            if(m[s1[i]]!=s2[i]){
                return false;
            }
        }
        else{
            m[s1[i]]=s2[i];
        }
        
    }
  return true;
}

bool isIsomorphic(string s1,string s2){

    if(s1.length()!=s2.length()){
        return false;
    }

    bool s1s2=checkNoOnetoManyOneMapping(s1,s2);
    bool s2s1=checkNoOnetoManyOneMapping(s2,s1);


    

    return s1s2 && s2s1;


}


vector<int> targetSum(vector<int> &v,int target){

    unordered_map<int,int> m;

    vector<int> ans(2,-1);

    for(int i=0;i<v.size();i++){
        int req=target-v[i];
        if(m.find(req)!=m.end()){
            ans[0]=m[req];
            ans[1]=i;
            return ans;
           
        }
        else{
            m[v[i]]=i;
        }
    }
    return ans;

}


int main(){
vector<int> v={1,4,5,11,13,10,2};
cout<<targetSum(v,13)[0]<<"  "<<targetSum(v,13)[1];

}