#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 400001;

int L[MAX], R[MAX], D[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X = 0, Y = 0, C = 0, V;
    bool flag = true;

    pr K;

    vector<int> arr;

    priority_queue<pr, vector<pr>, greater<pr>> pq;

    cin >> N >> M, flag &= M <= N, V = N - M;
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return L[x] < L[y]; });

    for (int i = 1; i <= N; i++) {
        while (X < N && L[arr[X]] <= C)
            pq.push({R[arr[X]], arr[X]}), X++;
        if (pq.empty()) {
            C = L[arr[X]];
            while (X < N && L[arr[X]] <= C)
                pq.push({R[arr[X]], arr[X]}), X++;
        }

        K = pq.top(), pq.pop();
        if (K[0] + 1 < C)
            flag = false;
        else if (K[0] >= C)
            D[K[1]] = C++, S[K[1]] = min(M, ++Y);
        else if (K[0] + 1 == C)
            --V, flag &= V >= 0, D[K[1]] = C - 1, S[K[1]] = min(M, Y);
    }

    if (!flag) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 1; i <= N; i++)
        cout << D[i] << ' ' << S[i] << '\n';

    return 0;
}