//
// Created by salma on 9/7/2024.
//

#include<bits/stdc++.h>

using namespace std;

vector<int> DP(45, -1);
int climbStairs(int n) {
    if(n==1 || n==0){
        return 1;
    }

    if(DP[n] != -1){
        return DP[n];
    }

    DP[n] = climbStairs(n-1) + climbStairs(n-2);

    return DP[n];
}

int main(){
    int ways = climbStairs(3);
    cout << ways;
}
