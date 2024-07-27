//
// Created by salma on 8/27/2023.
//
#include<bits/stdc++.h>

using namespace std;

int main(){
    int j,k, size;
    vector<string> input={"reflower","flow","flight"};
    string firstString, secondString, longestPrefix;

    if(input.size()==1)
    {
        cout << input[0] << endl;
    }

    for(int i=0; i<input.size()-1; i++){
        string prefix;
        firstString = input[i];
        secondString=input[i+1];

//        size = min(firstString.size(), secondString.size());
//        cout << size << endl;

        for(j=0; j<size; j++){
            if(firstString[j]==secondString[j]){
                prefix += firstString[j];
            }else{
                break;
            }
        }
//        cout << prefix << endl;
        if(prefix.size()<longestPrefix.size() || i==0){
            longestPrefix=prefix;
        }
    }

    cout << longestPrefix << endl;
}