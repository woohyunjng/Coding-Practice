#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 101;

int C[MAX], T[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int TK, N, K, L, ans;
    vector<int> arr;

    priority_queue<pr> pq;
    pr V;

    cin >> TK;
    for (int t = 1; t <= TK; t++) {
        cin >> N >> K, arr.clear();

        arr.push_back(N), T[N] = 0;
        for (int i = 0; i < N; i++)
            cin >> C[i] >> T[i] >> S[i], arr.push_back(i);

        sort(arr.begin(), arr.end(), [&](int x, int y) { return T[x] > T[y]; });

        ans = 0;
        for (int i = 0; i < N; i++) {
            pq.push({S[arr[i]], C[arr[i]]}), L = T[arr[i]] - T[arr[i + 1]];
            while (L > 0 && !pq.empty()) {
                V = pq.top(), pq.pop();
                if (V[1] <= L)
                    ans += V[0] * V[1], L -= V[1];
                else
                    ans += V[0] * L, V[1] -= L, L = 0, pq.push(V);
            }
        }

        cout << "Case #" << t << ": " << ans << "\n";

        while (!pq.empty())
            pq.pop();
    }

    return 0;
}