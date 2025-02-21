//
// Created by salma on 2/20/2025.
//
#include<bits/stdc++.h>

using namespace std;

int DP[100];
int dp(vector<int>& nums, int leftIndex, int n){
    if(leftIndex >= n) return 0;

    if(DP[leftIndex] != -1){
        return DP[leftIndex];
    }

    return DP[leftIndex] = max(nums[leftIndex] + dp(nums, leftIndex+2, n),
                               dp(nums, leftIndex+1, n));
}


int rob(vector<int>& nums) {
    memset(DP, -1, sizeof(DP));
    if(nums.size()==1){
        return nums.front();
    }
    return max(dp(nums, 1, nums.size()), dp(nums, 0, nums.size()-1));
}

int main(){
    vector<int> nums = {200,3,140,20,10};
    int res = rob(nums);
    cout << res;
}