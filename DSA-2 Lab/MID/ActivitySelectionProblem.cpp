#include <bits/stdc++.h>
using namespace std;

// Function to perform activity selection
void activitySelection(vector<pair<int,int>> &activities) {
    // Sort activities by finish time
    sort(activities.begin(), activities.end(), [](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    });

    cout << "Sorted activities (by finish time):\n";
    for(auto a : activities)
        cout << "(" << a.first << ", " << a.second << ")\n";

    cout << "\nSelected activities:\n";
    cout << "(" << activities[0].first << ", " << activities[0].second << ")\n";

    int last = 0; // last selected activity index
    int count = 1;

    for(int i = 1; i < activities.size(); i++) {
        if(activities[i].first >= activities[last].second) {
            cout << "(" << activities[i].first << ", " << activities[i].second << ")\n";
            last = i;
            count++;
        }
    }

    cout << "\nMaximum number of activities: " << count << endl;
}

int main() {
    vector<pair<int,int>> activities = {
        {8,12}, {9,10}, {14,16}, {11,13}, {9,11}, {10,12}
    };

    activitySelection(activities); // function call

    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

// Function to perform activity selection
void activitySelection(vector<Activity> &activities) {
    // Sort activities by finish time
    sort(activities.begin(), activities.end(), [](Activity a, Activity b){
        return a.finish < b.finish;
    });

    cout << "Sorted activities (by finish time):\n";
    for(auto a : activities)
        cout << "(" << a.start << ", " << a.finish << ")\n";

    cout << "\nSelected activities:\n";
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")\n";

    int last = 0; // last selected activity index
    int count = 1;

    for(int i = 1; i < activities.size(); i++) {
        if(activities[i].start >= activities[last].finish) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";
            last = i;
            count++;
        }
    }

    cout << "\nMaximum number of activities: " << count << endl;
}

int main() {
    vector<Activity> activities = {
        {8,12}, {9,10}, {14,16}, {11,13}, {9,11}, {10,12}
    };

    activitySelection(activities); // function call

    return 0;
}
*/

