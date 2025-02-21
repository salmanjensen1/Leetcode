// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int minDeviation(int tshirts, int bags){
    return tshirts%bags;
}

vector<int> getListOfBags(int tshirts, int bags){
    int equalDist = tshirts/bags;
    //all bags except last one will have equally distributed tshirts
    vector<int> v(bags-1, equalDist);
    //last bag will have same value+deviation value
    v.push_back(equalDist+minDeviation(bags,tshirts));
    return v;

}

int main() {
    int orders, bags, tshirts; vector<int> v;
    cin >> orders;
    while(orders--){
        v.clear();
        cin >> tshirts >> bags;

        if(tshirts<bags){
            cout << "Need more bags" << endl;
            continue;
        }

        int res = minDeviation(tshirts, bags);
        v = getListOfBags(tshirts, bags);
        cout << "List of Bags: ";
        for(auto num: v){
            cout << num << " ";
        }
        cout << endl;
        cout << "Minimum deviation: " << res << endl;
    }

    return 0;
}