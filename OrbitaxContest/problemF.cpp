//
// Created by salma on 9/7/2024.
//

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const long long mod= 1e9+7;
const int N= 1e5+9, K= 210;

int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
int n,m;

int isval(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m) return 0;
    return 1;
}

void solve(int tc){
    cin>>n>>m;

    ll dt[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>dt[i][j];
    }

    priority_queue<pair<ll,pair<ll,ll> >, vector<pair<ll,pair<ll,ll> > >, greater<pair<ll,pair<ll,ll> > > > pq;
    ll dis[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) dis[i][j]= 1e18;
    }

    int k;
    cin>>k;

    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;

        pq.push({0,{x,y}});
        dis[x][y]=0;
    }

    while(!pq.empty()){
        auto [d,p]= pq.top();
        pq.pop();
        auto [r,c]= p;

        if(dis[r][c]<d) continue;

        for(int dd=0;dd<4;dd++){
            int nr= r+dr[dd], nc=c+dc[dd];
            if(isval(nr,nc) && dis[nr][nc]>dis[r][c]+dt[r][c]){
                dis[nr][nc]= dis[r][c]+dt[r][c];
                pq.push({dis[nr][nc],{nr,nc}});
            }
        }
    }

    int q;
    cin>>q;

    while(q--){
        int x,y;
        cin>>x>>y;

        cout<<dis[x][y]<<"\n";
    }

}


signed main()
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