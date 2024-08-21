//
// Created by salma on 8/21/2024.
//
#include<bits/stdc++.h>

using namespace std;

stack<int> s;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    unsigned long long int n = temperatures.size();
    vector<int> res(n, 0); //vector of size n and initial value 0

    for(int i=0; i < n;){
        if(s.empty()){
            s.push(i);
            i++;
            continue;
        }
        int &top = s.top(); //top element of stack
        if(temperatures[i] > temperatures[top]){
            res[top] = i - top;
            s.pop();
        }else{
            s.push(i);
            i++;
        }

    }

    return res;

}

int main(){
    vector<int> v, in = {73,74,75,71,69,72,76,73};
    v = dailyTemperatures(in);
    for(auto res: v){
        cout << res;
    }
}