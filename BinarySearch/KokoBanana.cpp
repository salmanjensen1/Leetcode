//
// Created by salma on 9/11/2024.
//

#include<bits/stdc++.h>

using namespace std;

long long  M=0;

long long  recurse(long long  left, long long  right, long long  h, vector<long long >& piles){
    long long  centre = floor((left+right)/2); long long  time=0;
    long long  temp;

    for(long long  i=0; i<=piles.size()-1; i++){
        temp = ceil(float(piles[i])/float(centre));
        time += temp;
    }
    if(left > right){
        return M;
    }

    if(time <= h){
        M = centre;
    }

    if(time > h){
        return recurse(centre+1, right, h, piles);
    }else{
        return recurse(left, centre-1, h, piles);
    }

}

long long  minEatingSpeed(vector<long long >& piles, long long  h) {
    long long  y=0;
    for(auto x: piles){
        y = max(y, x);
    }
    cout << "y: " <<y<<endl;
    long long  min = recurse(1, y, h, piles);
    return min;
}

int main(){
    vector<long long > piles = {1000000000} ;
    long long  h = 2;
    long long  min = minEatingSpeed(piles, h);
    cout << min;
}