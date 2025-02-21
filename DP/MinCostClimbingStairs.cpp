//
// Created by salma on 2/17/2025.
//
#include<bits/stdc++.h>

using namespace std;

int DP[1000];

int recurse(vector<int>& cost, int index){
    if(index > cost.size()-1){ //if index points outside of array
        return 0;
    }

    if(DP[index]!= -1){
        return DP[index];
    }

    int oneStep = cost[index] + recurse(cost, index+1);
    int twoStep = cost[index] + recurse(cost, index+2);

    return DP[index] = min(oneStep, twoStep);
}

int minCostClimbingStairs(vector<int>& cost) {
    memset(DP, -1, sizeof(DP));
    int res = min( recurse(cost, 0), recurse(cost, 1));
    return res;
}

int main(){
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int res = minCostClimbingStairs(cost);
    cout << res;
}
