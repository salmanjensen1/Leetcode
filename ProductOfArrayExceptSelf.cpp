//
// Created by salma on 7/27/2024.
//

#include<bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> v;
    int totalProduct=0; int numberOfZeroes= 0; bool isDigit=true;
    for(auto num: nums){
        if(!num){
            numberOfZeroes++;
            continue;
        }
        if(isDigit){
            totalProduct=1;
            isDigit=false;
        }
        totalProduct*=num;
    }

    for(auto num: nums){

        if(numberOfZeroes>1){
            v.push_back(0);
            continue;
        }
        if(numberOfZeroes){
            if(num!=0){
                v.push_back(0);
                continue;
            }
            if(num==0){
                v.push_back(totalProduct);
                continue;
            }
        }
        v.push_back(totalProduct/num);
    }
    return v;
}

int main(){
    vector<int> v, nums={4, 0, 4};
    v = productExceptSelf(nums);

    for(auto x: v){
        cout << x << " ";
    }
}