//
// Created by salma on 7/26/2024.
//

#include<bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    vector<int> v;

    for(auto num: nums){
        m[num]++;
    }
    for(auto x: m){

        if(x.second>=k){
            v.push_back(x.first);
        }
    }

    return v;

}

int main(){
    vector<int> v, in = {1,1,1,2,2,3,4};
    v = topKFrequent(in, 3 );
    for(auto i: v){
        cout << i << " ";
    }
}