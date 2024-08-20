//
// Created by salma on 8/20/2024.
//

#include<bits/stdc++.h>

using namespace std;

int global_n;
vector<string> res;

void recursive_gen(int leftPar, int rightPar, string s){
    //sucess
    if(leftPar == rightPar && leftPar == global_n){
        res.push_back(s);
        return;
    }

    //base case
    if(leftPar>global_n || rightPar>leftPar){
        return;
    }

    recursive_gen(leftPar+1, rightPar, s+"(");
    recursive_gen(leftPar, rightPar+1, s+")");
}

vector<string> generateParenthesis(int n) {
    vector<string> v;
    global_n = n;
    recursive_gen(1, 0, "(");
    return res;
}

int main(){
    int n;
    cin >> n;
    generateParenthesis(n);
    for(auto c: res){
        cout << c << " ";
    }
    cout << endl;
    cout << "length " << res.size();
}