//
// Created by salma on 8/27/2023.
//
#include<bits/stdc++.h>

using namespace std;



int lastIndex;

int main(){

    string input={"(){}}{"};
    map<char, char> endingTag;
    map<char, bool> closeBracket;
    map<char, bool> openBracket;

    stack<char> s;
    endingTag['('] = ')';
    endingTag['{'] = '}';
    endingTag['['] = ']';

    closeBracket[')'] = true;
    closeBracket['}'] = true;
    closeBracket[']'] = true;
    closeBracket['('] = false;
    closeBracket['{']=false;
    closeBracket['[']=false;

    openBracket['('] = true;
    openBracket['{']=true;
    openBracket['[']=true;
    openBracket[')'] = false;
    openBracket['}'] = false;
    openBracket[']'] = false;



    int nextTag;
    if(closeBracket[input[0]]){
        cout << "false" << endl;
    }
    s.push(input[0]);

    for(int i=0; i<input.size()-1; i++){
        nextTag=input[i+1];
        if(openBracket[nextTag]){
            s.push(nextTag);
        }else if(!s.empty() && nextTag == endingTag[s.top()]){
            s.pop();
            continue;
        }else{
            cout << "false";
            return -1;
        }
    }

    if(!s.empty()){
        cout << "false";
        return -1;
    }

    cout << "true";
}


