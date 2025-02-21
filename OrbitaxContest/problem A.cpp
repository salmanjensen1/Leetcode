//
// Created by salma on 9/7/2024.
//

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const long long mod= 1e9+7;
const int N= 2e5+9;

vector<pair<ll,ll> > cand;
int n;

bool can(ll x){
    ll cur=x;

    for(int i=0;i<n;i++){
        cur=min(cur,x-cand[i].first);
        cur -= cand[i].second;
    }

    return cur>=0;
}


void solve(int tc){
    cin>>n;

    cand.assign(n,{});
    for(int i=0;i<n;i++){
        cin>>cand[i].second;
    }

    for(int i=0;i<n;i++) cin>>cand[i].first;
    sort(cand.begin(),cand.end());

    ll lo=-1,hi= 1e10;

    while(hi-lo>1){
        ll mid=(hi+lo)/2;
        if(can(mid)) hi=mid;
        else lo=mid;
    }

    cout<<hi+1<<"\n";

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc=1;
    // cin>>tc;

    for(int t=1;t<=tc;t++){
        // cout<<"Case "<<t<<":";
        solve(t);
    }

}