#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 1000001;
const int INF = 1e9 + 1;

int A[MAX], B[MAX], P[MAX], ans[MAX];
bool chk[MAX];

vector<int> arr[MAX];
priority_queue<pr, vector<pr>, greater<pr>> dq[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, S, X, Y, res = 0;
    pr V;

    vector<int> comp, lst[2];
    set<int> st, tmp;
    priority_queue<pr> pq;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i] >> P[i];
        comp.push_back(P[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), K = comp.size();
    for (int i = 1; i <= N; i++) {
        P[i] = lower_bound(comp.begin(), comp.end(), P[i]) - comp.begin() + 1;
        arr[P[i]].push_back(i);
    }

    for (int i = 1; i <= K; i++) {
        sort(arr[i].begin(), arr[i].end(), [&](int x, int y) { return B[x] > B[y] || (B[x] == B[y] && A[x] > B[y]); });
        Y = 0;

        while (Y < arr[i].size()) {
            X = B[arr[i][Y]];
            while (Y < arr[i].size() && B[arr[i][Y]] == X)
                pq.push({A[arr[i][Y]], arr[i][Y]}), Y++;
            while (!pq.empty() && (Y == arr[i].size() || X > B[arr[i][Y]])) {
                V = pq.top(), pq.pop();
                B[V[1]] = X, X--;
            }
        }

        for (int j : arr[i]) {
            if (A[j] > B[j]) {
                cout << "NIE" << '\n';
                return 0;
            }
        }
    }

    for (int i = 1; i <= N; i++)
        lst[0].push_back(i), lst[1].push_back(i);

    sort(lst[0].begin(), lst[0].end(), [&](int x, int y) { return B[x] < B[y] || (B[x] == B[y] && A[x] < A[y]); });
    sort(lst[1].begin(), lst[1].end(), [&](int x, int y) { return A[x] < A[y] || (A[x] == A[y] && B[x] < B[y]); }), X = 0;

    for (int i = 0; i < N; i++) {
        if (chk[lst[0][i]])
            continue;
        while (X < N && A[lst[1][X]] <= B[lst[0][i]]) {
            if (!dq[P[lst[1][X]]].empty())
                st.erase(dq[P[lst[1][X]]].top()[1]);
            dq[P[lst[1][X]]].push({B[lst[1][X]], lst[1][X]}), st.insert(dq[P[lst[1][X++]]].top()[1]);
        }

        res++;
        while (!st.empty()) {
            Y = *st.begin(), st.erase(st.begin());
            ans[Y] = B[lst[0][i]], dq[P[Y]].pop(), chk[Y] = true;
            if (!dq[P[Y]].empty())
                tmp.insert(dq[P[Y]].top()[1]);
        }
        st = tmp, tmp.clear();
    }

    cout << res << '\n';
    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';

    return 0;
}