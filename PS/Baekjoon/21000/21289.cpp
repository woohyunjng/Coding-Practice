#include <bits/stdc++.h>
#define int long long

#define MAX 300100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> adj[MAX], pnts[MAX];
tp arr[MAX];
int res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, A, B;
    pr X;
    vector<int> x_comp;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        arr[i] = {A, B, i};
        x_comp.push_back(A);
    }

    sort(x_comp.begin(), x_comp.end());
    x_comp.erase(unique(x_comp.begin(), x_comp.end()), x_comp.end());

    for (int i = 1; i <= N; i++) {
        A = lower_bound(x_comp.begin(), x_comp.end(), arr[i][0]) - x_comp.begin() + 1;
        pnts[A].push_back({arr[i][1], arr[i][2]});
    }

    for (int i = 1; i <= x_comp.size(); i++)
        sort(pnts[i].begin(), pnts[i].end());

    for (int i = 1; i <= N; i++) {
        auto iter = lower_bound(x_comp.begin(), x_comp.end(), arr[i][0] + 1);
        if (iter == x_comp.end() || *iter != arr[i][0] + 1)
            continue;

        A = lower_bound(x_comp.begin(), x_comp.end(), arr[i][0]) - x_comp.begin() + 1;
        auto iter2 = lower_bound(pnts[A + 1].begin(), pnts[A + 1].end(), pr{arr[i][1], 0});
        if (iter2 == pnts[A + 1].end() || (iter2 != pnts[A + 1].begin() && iter2->first > arr[i][1] + 1))
            iter2 = prev(iter2);

        B = lower_bound(pnts[A].begin(), pnts[A].end(), pr{arr[i][1], 0}) - pnts[A].begin();
        if (B + 1 < pnts[A].size())
            B = pnts[A][B + 1].first;
        else
            B = INF;

        for (; iter2 != pnts[A + 1].end() && iter2->first + 1 < B; iter2++) {
            if (iter2->first >= arr[i][1]) {
                adj[i].emplace_back(iter2->first - arr[i][1], iter2->second);
                adj[iter2->second].emplace_back(iter2->first - arr[i][1], i);
            } else {
                adj[i].emplace_back(arr[i][1] - iter2->first, iter2->second);
                adj[iter2->second].emplace_back(arr[i][1] - iter2->first, i);
            }
        }
    }

    for (int i = 1; i <= N; i++)
        sort(adj[i].begin(), adj[i].end());

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({0, 1});

    fill(res, res + N + 1, INF);
    res[1] = 0;

    while (!pq.empty()) {
        X = pq.top(), pq.pop();
        A = X.first, B = X.second;

        if (res[B] < A)
            continue;

        if (B == N) {
            if (A >= K)
                cout << "NATT";
            else
                cout << A;
            return 0;
        }

        for (pr i : adj[B]) {
            if (max(A, i.first) < res[i.second]) {
                res[i.second] = max(A, i.first);
                pq.push({max(A, i.first), i.second});
            }
        }
    }

    cout << "NATT";

    return 0;
}