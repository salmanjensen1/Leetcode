//
// Created by salma on 9/11/2024.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct cars {
    int pos;
    int speed;

    bool operator<(const cars& obj) const {
        return pos < obj.pos;
    }
};

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<cars> v(position.size());
    for (int i = 0; i < position.size(); i++) {
        v[i].pos = position[i];
        v[i].speed = speed[i];
    }

    // Sort cars by their position in descending order
    sort(v.rbegin(), v.rend());

    stack<float> time;  // Monotonic decreasing stack for arrival times

    // Calculate the time taken for each car to reach the target
    for (int i = 0; i < v.size(); i++) {
        float t = float(target - v[i].pos) / v[i].speed;  // Floating-point division

        // Maintain a monotonic decreasing stack
        if (!time.empty() && t <= time.top()) {
            continue;  // Current car joins the fleet of the one in front
        }

        // Otherwise, the car starts a new fleet
        time.push(t);
    }

    // The size of the stack represents the number of car fleets
    return time.size();
}

int main() {
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    int target = 12;

    int fleetCount = carFleet(target, position, speed);
    cout << "Number of car fleets: " << fleetCount << endl;

    return 0;
}
