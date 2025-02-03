#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X, Y, ans;
    vector<pr> arr;
    priority_queue<int> pq;

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> X >> Y, arr.push_back({X + Y, Y});

        sort(arr.begin(), arr.end()), X = ans = 0;
        for (pr i : arr) {
            X += i[1], ans++, pq.push(i[1]);
            if (X > i[0])
                ans--, X -= pq.top(), pq.pop();
        }

        cout << ans << '\n';

        arr.clear();
        while (!pq.empty())
            pq.pop();
    }

    return 0;
}