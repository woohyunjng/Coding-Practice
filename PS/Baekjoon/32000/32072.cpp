#include <bits/stdc++.h>
#define int long long
#define MAX 300100

using namespace std;
typedef pair<int, int> pr;

int P[MAX], A[MAX];
vector<int> child[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    pr K;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        cin >> P[i];
        child[P[i]].push_back(i);
    }

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({A[1], 1});

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        cout << K.first << '\n';

        for (int i : child[K.second])
            pq.push({A[i], i});
    }

    return 0;
}