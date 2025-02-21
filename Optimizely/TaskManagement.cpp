//
// Created by salma on 9/16/2024.
//
#include<bits/stdc++.h>

using namespace std;

struct reviewers {
    string name;
    int efforts;

    //operator overloading
    bool operator<(const reviewers& other) const {
        return efforts > other.efforts; // min-heap comparison (smaller efforts come first)
    }
};

struct tasks{
    int taskId;
    string assigneeName;
    string reviewerName;
    string status;
    int estimateInHours;
};

priority_queue<reviewers> pq;
unordered_map<string, int> m;

void assignReviewers(vector<tasks>& taskList){
    for(auto& task: taskList){
        if(task.reviewerName=="null" && task.status=="in-review"){
            task.reviewerName = pq.top().name;
            int effort = pq.top().efforts + ((task.estimateInHours)/3);
//            printf("Current effort of %s: %d\n", task.reviewerName.c_str(), effort);
            printf("Task Id: %d is assiged to %s\n", task.taskId, task.reviewerName.c_str());
            printf("Total Effort of %s: %d\n", task.reviewerName.c_str(), effort);
            pq.pop();
            pq.push({task.reviewerName, effort});

            }else{
                cout << "Task Id: " << task.taskId << " doesn't need an additional reviewer" << endl;
            }
    }

//    for(auto& t: taskList){
//        cout << t.taskId << " "<<t.assigneeName<< " "<<t.reviewerName<< " "<<t.estimateInHours
//             << " "<<t.status<< endl;
//    }


}

void populatePriorityQueue(){


    //initially everyone gives MAXIMUM EFFORT (get it? ;))
    pq.push({"Logan", 0});
//    pq.push({"Xavier", 0});
//    pq.push({"Jean", 0});
//    pq.push({"Scott", 0});
//    pq.push({"Hank", 0});
//    pq.push({"Gambit", 0});
}

int main(){
    vector<tasks> v;

    int n;
    cin >> n;
    while(n--){
        tasks t;

        cout << "Task ID: ";
        cin >> t.taskId;

        cout << "Assignee Name: ";
        cin>> t.assigneeName;

        cout << "Reviewer Name: ";
        cin>>t.reviewerName;

        cout << "Status";
        cin >> t.status;

        cout << "Estimate in Hours: ";
        cin >> t.estimateInHours;



        if(t.reviewerName!="null"){
            int effort = t.estimateInHours/3;
            m[t.reviewerName]+=effort;
//            pq.push({t.reviewerName, t.estimateInHours});
        }

//        cout << pq.top().name << " " << pq.top().efforts<<endl;

        v.push_back(t);
    }

    for(auto mapElement: m){
        pq.push({mapElement.first, mapElement.second});
    }


//    populatePriorityQueue();
    assignReviewers(v);

}