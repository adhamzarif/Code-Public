#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;

    long long ans = min({a, b, (a + b) / 3});
    cout << ans << "\n";

    return 0;
}
