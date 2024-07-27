//
// Created by salma on 8/27/2023.
//
#include<bits/stdc++.h>

using namespace std;

int main(){
    string roman;
    int sum=0, value;
    cin>>roman;

    for(int i=0; i<roman.size(); i++)
    {
        char nextLetter = roman[i+1];
        switch(roman[i]){
            case 'I':
                value=1;
                if(nextLetter=='V'){
                    value=5-value;
                    i+=1;
                }else if(nextLetter=='X'){
                    value=10-value;
                    i+=1;
                }else if(nextLetter=='L'){
                    value=50-value;
                    i+=1;
                }else if(nextLetter=='C'){
                    value=100-value;
                    i+=1;
                }else if(nextLetter=='D'){
                    value=500-value;
                    i+=1;
                }else if(nextLetter=='M'){
                    value=1000-value;
                    i+=1;
                }
                sum+=value;
                break;
            case 'V':
                value=5;
                if(nextLetter=='X'){
                    value=10-value;
                    i+=1;
                }else if(nextLetter=='L'){
                    value=50-value;
                    i+=1;
                }else if(nextLetter=='C'){
                    value=100-value;
                    i+=1;
                }else if(nextLetter=='D'){
                    value=500-value;
                    i+=1;
                }else if(nextLetter=='M'){
                    value=1000-value;
                    i+=1;
                }

                sum+=value;
                break;
            case 'X':
                value=10;
                if(nextLetter=='L'){
                    value=50-value;
                    i+=1;
                }else if(nextLetter=='C'){
                    value=100-value;
                    i+=1;
                }else if(nextLetter=='D'){
                    value=500-value;
                    i+=1;
                }else if(nextLetter=='M'){
                    value=1000-value;
                    i+=1;
                }
                sum+=value;
                break;
            case 'L':
                value = 50;
                if(nextLetter=='D'){
                    value=500-value;
                    i+=1;
                }else if(nextLetter=='M'){
                    value=1000-value;
                    i+=1;
                }
                sum+=value;
                break;
            case 'C':
                value=100;
                if(nextLetter=='D'){
                    value=500-value;
                    i+=1;
                }else if(nextLetter=='M'){
                    value=1000-value;
                    i+=1;
                }
                sum+=value;
                break;
            case 'D':
                sum+=500;
                break;
            case 'M':
                sum+=1000;
                break;
            default:
                cout<<"Unknown case: "<<i<<endl;
                break;
        }
    }
    cout << sum << endl;
}
