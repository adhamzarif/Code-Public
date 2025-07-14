#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> dq; // using STL
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30); // 10 20 30
    dq.push_front(4); // 4 10 20 30
    cout << dq.front() << " " << dq.back() << endl;
    dq.pop_back(); // 4 10 20
    cout << dq.front() << " " << dq.back() << endl;
    return 0;
}