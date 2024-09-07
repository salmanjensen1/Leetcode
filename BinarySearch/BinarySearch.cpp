//
// Created by salma on 9/5/2024.
//
#include<bits/stdc++.h>

using namespace std;

int recurse(int i, int n, int target, vector<int>& nums){
    int centre = floor((i+n)/2);
    if(target == nums[centre]){
        return centre;
    }
    if(i>n){
        return -1;
    }

    if(target > nums[centre]){
        return recurse(centre+1, n, target, nums);
    }else if(target < nums[centre]){
        return recurse(i, centre-1, target, nums);
    }
}

int search(vector<int>& nums, int target) {
    int index = recurse(0, nums.size()-1, target, nums);
    return index;
}

int main(){
    vector<int> arr = {5};
    int index = search(arr, -5);
    cout << index;
}