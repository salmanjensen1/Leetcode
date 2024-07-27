//
// Created by salma on 7/25/2024.
//

#include<bits/stdc++.h>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    vector<int> indices, ans;
    int i, compliment;
    for(i=0; i<nums.size(); i++){
        compliment = target - nums[i];

        if(m.count(nums[i])){
            indices.push_back(m[nums[i]]);
            indices.push_back(i);
            return indices;
        }
        m[compliment] = i;
    }
}

int main(){
    vector<int> v, input;
    input = {2, 7, 11, 15};
    v = twoSum(input, 22);
    for(auto i: v){
        cout << i << " ";
    }
}