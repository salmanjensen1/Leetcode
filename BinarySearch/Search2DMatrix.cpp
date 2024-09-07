//
// Created by salma on 9/5/2024.
//
#include<bits/stdc++.h>

using namespace std;

bool recurse(int i, int n, int target, vector<int>& nums){
    int centre = floor((i+n)/2);
    if(target == nums[centre]){
        return true;
    }
    if(i>n){
        return false;
    }

    if(target > nums[centre]){
        return recurse(centre+1, n, target, nums);
    }else if(target < nums[centre]){
        return recurse(i, centre-1, target, nums);
    }
}

int searchMatrix(vector<vector<int>>& nums, int target) {
    vector<int> targetRow;
    //vector of size m*n
    int m=nums.size(), n=nums[0].size()-1;
    for(int i=0; i<m; i++){
        if(target<=nums[i][n]){
            targetRow = nums[i];
            break;
        }
    }

    if(targetRow.empty()){
        targetRow=nums[0];
    }

    for(auto i:targetRow){
        cout << i << " ";
    }
    bool exist = recurse(0, targetRow.size()-1, target, targetRow);
    return exist;
}

int main(){
    vector<vector<int>> arr = {{1}};
    bool index = searchMatrix(arr, 2);
    cout << index;
}