//
// Created by salma on 8/10/2024.
//
//
// Created by salma on 8/10/2024.
//
#include<bits/stdc++.h>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st; int ans=0;
    for(auto c: tokens){
        if(c != "+" && c != "-" && c != "/" &&   c != "*"){
            st.push(stoi(c));  //convert string to equivalent integer
        }else{
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            if(c == "+"){
                ans = x+y;
            }
            else if(c == "-"){
                ans = y-x;
            }
            else if(c == "*"){
                ans = x*y;
            }
            else if(c == "/"){
                ans = y/x;
            }
            st.push(ans);
        }
    }
    return st.top();
}

int main(){
    vector<string> tokens = {"18"};
    int ans;
    ans = evalRPN(tokens);
    cout << ans << endl;
}