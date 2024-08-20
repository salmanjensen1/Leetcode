//
// Created by salma on 8/7/2024.
//
#include<bits/stdc++.h>

using namespace std;

int trap(vector<int>& height) {
    int len = height.size();
    int i=0, j=len-1, sum=0;
    int left_max = height[i];
    int right_max = height[j];

    while(i<j){
        if(height[i]<=height[j]){
            sum+= left_max - height[i];
            i++;
            left_max=max(left_max, height[i]);
        }
        else{
            sum+=right_max - height[j];
            j--;
            right_max=max(right_max, height[j]);
        }
    }
    return sum;
}

int main(){
    int area;
    vector<int> h = {4,2,3,0,5};
    area = trap(h);
    cout << area;
}