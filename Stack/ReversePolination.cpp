//
// Created by salma on 8/10/2024.
//
#include<bits/stdc++.h>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<char> st;
    for(auto ch: tokens){
        if(ch != '+' || ch != '-' || ch!='/' || ch!='*'){
            st.push(ch);
        }else{

        }
    }
}

int main(){
    vector<string> tokens = {"2","1","+","3","*"}
    int ans;
    ans = evalRPN(tokens);
}