//
// Created by salma on 8/10/2024.
//
#include<bits/stdc++.h>

using namespace std;

stack<char> st;

bool isValid(string s) {
    for(auto ch : s){
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else if(
                s.empty() ||
                ch == ')' && st.top()!='(' ||
                ch=='}' && st.top()!= '{' ||
                ch == ']' && st.top() != '['
                )
        {
            return false;
        }
        else{
            st.pop();
        }
    }
    if(st.empty())
        return false;
    return true;
}

int main(){
    bool ans;
    string s = "({[[]})";
    ans = isValid(s);
    if(ans){
        cout << "true"<<endl;
    }else{
        cout << "false" << endl;
    }
}