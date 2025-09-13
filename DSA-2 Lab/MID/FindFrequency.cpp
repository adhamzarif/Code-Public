#include<iostream>
#include<vector>

int countFrequency(vector<int> a, int low, int high, int target){
    if(low == high){
        if(a[low] == target) return 1;
        return 0;
    }
    int mid = (low+high)/2;
    int l = countFrequency(a, low, mid);
    int r = countFrequency(a, mid+1, high);

    return l+r;
}
int main(){
    vector<int> v = {12, 8, 16, 9, 8, 8};
    int n = v.size();
    int t = 8;
    int c = countFrequency(v, 0, n-1, t);
    cout << c << endl;
}
