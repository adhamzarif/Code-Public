#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Activity{
public:
    int start_time, finish_time;
    Activity(int s, int f): start_time(s), finish_time(f){}
    void display(){
        cout<<" start time: "<<start_time<<", finish time: "<< finish_time<<endl;
    }
};
bool Compare(Activity a1, Activity a2){
    return a1.finish_time  < a2.finish_time;
}

void ActivitySelection(vector<Activity> activityList){
    //find the maximum number of activities
    //sort according to earliest time
    sort(activityList.begin(), activityList.end(), Compare);
    for(Activity a : activityList ) a.display();

    vector<Activity> selected; //to store selected activities
    int l = 0; //last chosen activity
    selected.push_back(activityList[0]);//choose the 1st activity

    int cnt = 1;
    for(int m = 1; m < activityList.size() ; m++ ){
            //+2 --> 2 consecutive activities must have at least 2 hr time gap
        if(activityList[m].start_time >= activityList[l].finish_time + 2){
            selected.push_back(activityList[m]);
            l = m;
            cnt++;
        }
    }

    cout<< "\nMaximum no of activities: " << cnt << endl;
    cout << "Selected activity list: " << endl;
    for(Activity a : selected)
        a.display();

}

int main(){
    vector<Activity> activities = {Activity(9, 12), Activity(8, 10),
                Activity(9, 10), Activity(13, 15), Activity(11, 13),
                Activity(10, 12)
    };
    ActivitySelection(activities);
}
