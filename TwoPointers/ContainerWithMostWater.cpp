//
// Created by salma on 8/7/2024.
//
#include<bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int p1, p2, len=height.size(), area=0, maxHeight, maxArea=0;
    p1=0;
    p2 = len-1;
    while(p1<p2){
        maxHeight = min(height[p1],height[p2]);
        area = (p2-p1) * maxHeight;
        maxArea = max(maxArea, area);
        if(height[p1]>height[p2]){
            p2--;
        }else{
            p1++;
        }
    }
    return maxArea;
}

int main(){
    int area;
    vector<int> h = {1,8,99,99,5,4,8,3,7};
    area = maxArea(h);
    cout << area;
}