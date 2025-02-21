//
// Created by salma on 2/16/2025.
//
#include<iostream>
#include<cstring>
using namespace std;

int DP[45];


int recurse(int n, int steps){
    if(steps>n){
        return 0;
    }

    if(steps==n){
        return 1;
    }

    if(DP[steps]!=-1){
        return DP[steps];
    }

    return DP[steps] = recurse(n, steps+1) + recurse(n, steps+2) ;

}

int climbStairs(int n) {
    memset(DP, -1, sizeof(DP));
    int res = recurse(n, 0);
    return res;
}

int main(){
    int res = climbStairs(5);
    cout << res;
}