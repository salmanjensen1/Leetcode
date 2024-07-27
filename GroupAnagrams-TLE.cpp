//
// Created by salma on 7/25/2024.
//

#include<bits/stdc++.h>

using namespace std;



//checks if two Anagrams are valid by taking the initially construsted
//map of a string against all iterated string 't'
bool validAnagrams(unordered_map<char, int> countingMap, string t){

    for(auto c: t){ //eliminating map elements in contrast to string 't'
        countingMap[c]--;
    }
    //if all characters are eliminated (i.e. becomes 0), they are anagrams
    for(auto i: countingMap){
        if(i.second){
            return false;
        }
    }
    return true;

}

//returns a 2D list of anagrams grouped by ones that are similar
vector<vector<string>> groupAnagrams(vector<string>& strs) {
//    unordered_map<char, int> m;
    vector<vector<string>> groups;
    int i, j, group_count=0;    //inititaing group_count to serve to the vector of vector of strings
    for(i=0; i<strs.size(); i++)
    {
        unordered_map<char, int> countingMap; //used for comparing two anagram with storing the count of each character

        if(!strs[i].compare("X")) continue; //anagrams that are already grouped are replaced by capital X, means they aren't checked
        groups.push_back({strs[i]}); //anagrams that aren't checked yet, that is not X, are initiated in a separate group at top

        for(auto c: strs[i]){
            countingMap[c]++;
        }

        for(j=i+1; j<strs.size(); j++){
            if (strs[i].size()!=strs[j].size()) continue;
            bool valid = validAnagrams(countingMap, strs[j]);
            if(valid){
                groups[group_count].push_back(strs[j]);
                strs[j]="X";
            }
        }
        group_count++;
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