//
// Created by salma on 7/25/2024.
//

#include<bits/stdc++.h>

using namespace std;

bool validAnagrams(string s, string t){
    map<char, int> countingMap;

    for(auto c: s){
        countingMap[c]++;
    }
    for(auto c: t){
        countingMap[c]--;
    }
    for(auto i: countingMap){
        if(i.second){
            return false;
        }
    }
    return true;

}

int main(){
    bool a = validAnagrams("anagrammx", "nagaramm");
    cout << a;
}