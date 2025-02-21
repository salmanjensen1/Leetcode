//
// Created by salma on 9/10/2024.
//

#include<bits/stdc++.h>

using namespace std;

struct cars{
    int pos;
    int speed;

    bool operator <(const cars &obj) const{
        return pos < obj.pos;
    }
};

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<cars> v(n); stack<float>time; float t; vector<int> res;
    for(int i=0; i < n; i++){
        v[i].pos = position[i];
        v[i].speed = speed[i];
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        t = (float(target - v[i].pos)) / float(v[i].speed);
        time.push(t);
        cout << t << " ";
    }


    while(!time.empty()){
        t=time.top();
        time.pop();
        res.push_back(t);

        while(!time.empty() && t>=time.top()){
            time.pop();
        }

    }

    return res.size();
}

int main(){
    vector<int> position={6,8};
    vector<int>speed={3,2};
    int res = carFleet(10, position, speed);
    cout << res;
}