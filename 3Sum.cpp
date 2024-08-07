//
// Created by salma on 8/6/2024.
//

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int i, j, k, total;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for(i=0; i<nums.size(); i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        j=i+1;
        k=nums.size()-1;
        while(j<k){
            total = nums[i]+nums[j]+nums[k];
            if(total < 0){
                j++;
            }else if(total>0){
                k--;
            }else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;

                while (nums[j] == nums[j - 1] && j<k) {
                    j++;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> ans;
    vector<int> v = {0,0,0,0};
    ans = threeSum(v);
    for(auto arr: ans){
        for (auto a: arr){
            cout << a;
        }
        cout << endl;
    }
}
