//
// Created by salma on 8/10/2024.
//
#include<bits/stdc++.h>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for (auto& ch : tokens) {
        // Check if token is an operator
        if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
            int n2 = st.top(); st.pop();
            int n1 = st.top(); st.pop();

            if (ch == "+") st.push(n1 + n2);
            else if (ch == "-") st.push(n1 - n2);
            else if (ch == "*") st.push(n1 * n2);
            else if (ch == "/") st.push(n1 / n2);  // Assumes valid input (no division by zero)
        }
        else {
            // Convert string to integer and push onto the stack
            st.push(stoi(ch));
        }
    }

    return st.top();
}

int main(){
    vector<string> tokens = {"2","1","+","3","*"}
    int ans;
    ans = evalRPN(tokens);
}