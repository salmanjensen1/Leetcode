#include <bits/stdc++.h>
using namespace std;

#define ll long long
const long long mod= 1e9+7;



void solve(int tc){
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    string t="orbitaxian";

    ll dp[n+1][11];
    memset(dp,0,sizeof(dp));

    dp[n][10]=1;
    ll pref[11];
    memset(pref,0,sizeof(pref));
    pref[10]=1;

    ll res=0;
    for(int i=n-1;i>=0;i--){
        if(i+k+1<n){
            for(int j=0;j<10;j++) pref[j] = (pref[j]-dp[i+k+1][j]+mod)%mod;
        }

        for(int j=0;j<10;j++){
            if(s[i] != t[j]) continue;
            if(j==9){
                dp[i][j]=1;
                continue;
            }
            dp[i][j]= pref[j+1];
        }

        for(int j=0;j<10;j++) pref[j]= (pref[j]+dp[i][j])%mod;
        res= (res+dp[i][0])%mod;
    }

    cout<<res<<"\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc=1;
    cin>>tc;

    for(int t=1;t<=tc;t++){
        // cout<<"Case "<<t<<":";
        solve(t);
    }

}