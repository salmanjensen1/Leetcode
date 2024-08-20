//
// Created by salma on 7/25/2024.
//

#include<bits/stdc++.h>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    int compliment;

    for(int i=0; i<nums.size(); i++){
        compliment = target - nums[i];
        if(m.contains(compliment)){
            return{m[compliment]+1, i+1 };
        }
        m[nums[i]] = i;
    }
    return {};
}

int main(){
    vector<int> v, input;
    input = {2, 7, 11, 15};
    v = twoSum(input, 22);
    for(auto n: v){
        cout << n << " ";
    }
}