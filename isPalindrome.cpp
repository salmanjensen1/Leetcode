#include <iostream>

using namespace std;

bool isPalindrome(int x){
    int y=0, remainder, m;
    m = x;
    while(x){
        remainder = x%10;
        y = y*10+remainder;
        x/=10;
    }
    y = abs(y);
    if(m-y == 0)
        return true;
    return false;
}

int main() {
    isPalindrome(-121);
    return 0;
}

