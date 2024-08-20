//
// Created by salma on 7/26/2024.
//

//time complexity: O(Nlog(N))
//priority queue is used, which is max heap, with complexity Nlog(N)

#include<bits/stdc++.h>

using namespace std;

struct datas{
    int first;
    int second;
    //operator overloading
    bool operator <(const datas &obj) const
    {
        //objects with smaller second values are considered smaller
        return second < obj.second;
    }

};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    priority_queue<datas> pq;
    vector<int> v;

    //creating a map such that the frequency of each number is stored
    //[key]:value = [number]:frequency
    //for input, {1,1,1,2,2,3,4}, map-> {[1]:3, [2]:2, [3]:1, [4]:1}
    for(auto num: nums){
        m[num]++;
    }

    //smaller second values are settled at the bottom of the priority queue
    for(auto x: m){
        pq.push({x.first, x.second});
    }

    //store the K numbers with the highest frequency.
    for(int i=0; i<k; i++){
        v.push_back(pq.top().first);
        pq.pop();
    }

    return v;

}

int main(){
    vector<int> v, in = {1,1,1,2,2,3,4};
    v = topKFrequent(in, 2);
    for(auto i: v){
        cout << i << " ";
    }
}