#include<iostream>
#include<vector>
using namespace std;

struct Subarray{
    int sum, low, high;
};
Subarray Max_Crossing_sum(vector<int> a, int low, int mid, int high){
    //returns the maximum cross subarray
    int sum = 0;
    int left_sum = INT_MIN;
    int l_idx = -1;
    for(int i = mid ; i >= low ; i--){
        sum += a[i];
        if( sum >= left_sum ){
            left_sum = sum;
            l_idx = i;
        }
    }
    int right_sum = INT_MIN;
    int r_idx = -1;
    sum = 0;
    for(int j = mid+1; j <= high; j++){
        sum += a[j];
        if(sum >= right_sum){
            right_sum = sum;
            r_idx = j;
        }
    }
    Subarray m;
    m.sum = left_sum + right_sum;
    m.low = l_idx;
    m.high = r_idx;
    return m;
}

Subarray Find_Maximum_Subarray(vector<int> a, int low, int high){
    //return the maximum subarray
    if( low == high ){
        Subarray m;
        m.low = low; m.high = high; m.sum = a[low];
        return m;
    }
    int mid = (low + high)/2;
    //conquer
    Subarray left = Find_Maximum_Subarray(a, low, mid);
    Subarray right = Find_Maximum_Subarray(a, mid+1, high);

    //combine
    Subarray cross = Max_Crossing_sum(a, low, mid, high);
    if(left.sum >= right.sum && left.sum >= cross.sum) return left;
    else if(right.sum >= left.sum && right.sum >= cross.sum) return right;
    else return cross;
}

int main(){
    vector<int> v = {-2, 4, -1, 3, 5, -7, 6};
    int n = v.size();
    Subarray sub = Find_Maximum_Subarray(v, 0, n-1);
    int sum = sub.sum;
    int low = sub.low;
    int high = sub.high;
    cout << "maximum subarray sum:" << sum << endl;
    cout<< "maximum subarray:";
    for(int i = low; i <= high ; i++)
        cout << v[i] << ", ";

}
