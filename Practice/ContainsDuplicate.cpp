//
// Created by salma on 9/9/2024.
//
#include<bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> m;
    for(auto num: nums){
        m[num]++;
    }

    for(auto num: m){
        if(num.second > 1){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> v = {1,2,3,4};
    bool cd = containsDuplicate(v);
    cout << cd;
}