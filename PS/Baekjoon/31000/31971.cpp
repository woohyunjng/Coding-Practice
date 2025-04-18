#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200001;
const int MAX_LOG = 20;

int A[MAX], B[MAX], sparse[MAX][MAX_LOG];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, ans = MAX;

    vector<pr> arr;
    priority_queue<pr> pq;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        if (A[i] <= B[i])
            arr.push_back({A[i], -i}), arr.push_back({B[i], i});
        else
            arr.push_back({A[i], -i}), B[i] += M, arr.push_back({B[i], i}), arr.push_back({A[i] + M, -i});
    }

    sort(arr.begin(), arr.end()), chk[0] = true;
    for (pr i : arr) {
        if (i[1] < 0)
            pq.push({B[-i[1]], -i[1]}), chk[-i[1]] = false;
        else {
            chk[i[1]] = true;
            while (!pq.empty() && chk[pq.top()[1]])
                pq.pop();
            if (!pq.empty())
                sparse[i[1]][0] = pq.top()[1];
        }
    }

    for (int i = 1; i < MAX_LOG; i++)
        for (int j = 1; j <= N; j++)
            sparse[j][i] = sparse[sparse[j][i - 1]][i - 1];

    for (int i = 1; i <= N; i++) {
        K = i, X = 1;
        for (int j = MAX_LOG - 1; j >= 0; j--) {
            if (sparse[K][j] != 0 && B[sparse[K][j]] < A[i] + M)
                X += (1 << j), K = sparse[K][j];
        }
        if (B[sparse[K][0]] - M >= A[i])
            ans = min(ans, X + 1);
    }

    cout << (ans == MAX ? -1 : ans) << '\n';

    return 0;
}