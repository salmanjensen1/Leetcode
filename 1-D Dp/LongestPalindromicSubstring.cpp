//
// Created by salma on 2/21/2025.
//
#include<bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
    int i, length = 0;
    int n=s.size(); int left, right;

    int res_length=1;
    string res = s.substr(0,1);

    for(i=0; i<n; i++){
        left = i-1; right=i+1;
        while(left>=0 && right<n && s[left]==s[right]){
            length = right-left+1;
            if(length>res_length){
                res_length=length;
                res = s.substr(left, length);
            }

            left--; right++;
        }

        left = i; right=i+1;
        while(left>=0 && right < n && s[left]==s[right]){
            length = right-left+1;
            if(length > res_length){
                res_length = length;
                res = s.substr(left, length);
            }

            left--; right++;
        }
    }

    return res;
}

int main(){
    string res = longestPalindrome("babad");
    cout << res; //ans: bab or aba
}
