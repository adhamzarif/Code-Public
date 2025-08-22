#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    if (!(cin >> T))
    {
        return 0;
    }
    while (T--)
    {
        long long a, b;
        cin >> a >> b;
        long long ans = min({(a + b) / 3, a, b});
        cout << ans << '\n';
    }
    return 0;
}
