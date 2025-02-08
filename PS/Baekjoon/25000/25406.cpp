#include <bits/stdc++.h>
#define int long long

#define MAX 400000
using namespace std;

typedef array<int, 2> pr;

int A[MAX];
vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0, V;
    priority_queue<pr> pq_cnt, pq_idx;
    pr K, T;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = N; i >= 1; i--)
        arr[A[i]].push_back(i);

    for (int i = 1; i <= N; i++) {
        if (arr[i].size() == 0)
            continue;
        pq_cnt.push({(int)arr[i].size(), i});
        pq_idx.push({-arr[i].back(), i});
    }

    if (pq_cnt.top()[0] > (N + 1) / 2) {
        cout << -1 << '\n';
        return 0;
    }

    for (; N; N--) {
        while (!pq_cnt.empty() && (int)arr[pq_cnt.top()[1]].size() != pq_cnt.top()[0]) {
            K = pq_cnt.top(), pq_cnt.pop();
            if (!arr[K[1]].empty())
                pq_cnt.push({(int)arr[K[1]].size(), K[1]});
        }

        while (!pq_idx.empty() && (arr[pq_idx.top()[1]].empty() || -arr[pq_idx.top()[1]].back() != pq_idx.top()[0])) {
            K = pq_idx.top(), pq_idx.pop();
            if (!arr[K[1]].empty())
                pq_idx.push({-arr[K[1]].back(), K[1]});
        }

        if ((N & 1) && pq_cnt.top()[0] == (N + 1) / 2) {
            K = pq_cnt.top(), pq_cnt.pop();
            V = arr[K[1]].back(), arr[K[1]].pop_back();
            cout << V << ' ', X = K[1];
            if (!arr[K[1]].empty())
                pq_cnt.push({(int)arr[K[1]].size(), K[1]});
        } else {
            K = pq_idx.top(), pq_idx.pop();
            if (K[1] == X)
                T = pq_idx.top(), pq_idx.pop(), pq_idx.push(K), K = T;
            V = arr[K[1]].back(), arr[K[1]].pop_back();
            cout << V << ' ', X = K[1];
            if (!arr[K[1]].empty())
                pq_idx.push({-arr[K[1]].back(), K[1]});
        }
    }
    cout << '\n';

    return 0;
}