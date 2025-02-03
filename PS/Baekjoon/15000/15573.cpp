#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans = 0, V = 0;
    vector<pr> arr;
    priority_queue<int> pq;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> X >> Y, arr.push_back({X + Y, Y});

    sort(arr.begin(), arr.end());

    for (pr i : arr) {
        V += i[1], ans++, pq.push(i[1]);
        if (V > i[0])
            ans--, V -= pq.top(), pq.pop();
    }

    cout << ans << '\n';

    return 0;
}