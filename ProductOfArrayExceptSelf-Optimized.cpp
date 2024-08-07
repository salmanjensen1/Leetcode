//
// Created by salma on 7/28/2024.
//


#include<bits/stdc++.h>

using namespace std;


vector<int> productExceptSelf(vector<int>& nums){
    int i, n=nums.size();
    vector<int> v, pref, suff;
    pref[0]=1;suff[n-1]=1;

    //at any point i, prefix array has the value of the product of all the values "before" i-th value
    for(i=1; i<n; i++){
        pref[i] = pref[i-1]*nums[i-1];
    }

    //at any point i, prefix array has the value of the product of all the values "after" i-th value
    for(i=n-2; i>=0; i--){
        suff[i] = nums[i+1]*suff[i+1];
    }

    //multiplying i-th index of each array would give the product of all the values of i-th index and after i-th index except the
    //i-th index itself
    for(i=0; i<n;i++){
        v[i] = pref[i]*suff[i];
    }

    return v;
}

vector<int> productExceptSelfSpace1(vector<int>& nums){
    int i, n = nums.size();
    vector<int> v(n, 1);
    int curr =  1;

    //prefix array
    for(i=1; i<n; i++) {
        v[i] = curr * nums[i - 1];
        curr = v[i];
    }
    curr = 1;
    //suffix array
    for(i=n-2;i>=0; i--){
        curr = nums[i+1]*curr;
        v[i] = v[i]*curr;
    }

    return v;
}

int main()
{
    vector<int> ans, nums={1,2,3,4,5};
    ans = productExceptSelfSpace1(nums);
    for(auto a: ans){
        cout << a <<" ";
    }

}