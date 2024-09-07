//
// Created by salma on 8/5/2024.
//
#include<bits/stdc++.h>

using namespace std;

unordered_map<int, int> m;

int longestConsecutive(vector<int>& nums) {

    if(nums.size()==0){
        return 0;
    }

    int smaller, longer, longest=0;

    for(auto num: nums){
        m[num]++;
    }
    for(int num : nums){
        smaller = num - 1;
        if(!m[smaller]){
            longer=0;
            while(m[smaller+1]){
                longer++; smaller++;
            }
            longest = max(longer, longest);
        }

    }

    return longest;
}

int main(){
    vector<int> v = {0,3,7,2,5,8,4,6,0,1};
    int lcs = longestConsecutive(v);
    cout << lcs << endl;
}