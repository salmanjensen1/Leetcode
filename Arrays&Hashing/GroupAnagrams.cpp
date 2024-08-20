//
// Created by salma on 7/25/2024.
//

#include<bits/stdc++.h>

using namespace std;

//returns a 2D list of anagrams grouped by ones that are similar
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;

    for(auto s: strs){
        string word = s;
        sort(word.begin(), word.end());
        m[word].push_back(s);
    }

    vector<vector<string>> groups;
    for(auto group: m){
        groups.push_back(group.second);
    }
    return groups;
}



int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> groups;
    groups = groupAnagrams(strs);
    for(auto group: groups){
        for(auto g: group){
            cout << g << " ";
        }
        cout << endl;
    }
}