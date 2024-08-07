//
// Created by salma on 8/6/2024.
//
#include<bits/stdc++.h>

using namespace std;

string convertToAlpha(string s){
    string result;
    for(auto c: s)
    {
        if(isalnum(c)){
            result+= tolower(c);
        }
    }
    return result;
}


bool isPalindrome(string s) {
    s = convertToAlpha(s);
    int pointer1, pointer2;
    int len = s.size();
    if(len%2==0){
        pointer1=len/2;
        pointer2 = len/2-1;
    }else{
        pointer1 = len/2-1;
        pointer2 = len/2+1;
    }

    while(pointer1>=0 && pointer2<s.size()){
        if(s[pointer1]!=s[pointer2]){
            return false;
        }
        pointer1--;pointer2++;
    }

    return true;
}

int main(){

    bool b = isPalindrome("0P");
    cout << b << endl;

}