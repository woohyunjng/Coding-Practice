#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int A[MAX], tree[MAX];

int query(int idx) {
    int res = 0;
    while (idx > 0)
        res += tree[idx], idx -= (idx & -idx);
    return res;
}

void update(int idx, int val) {
    while (idx < MAX)
        tree[idx] += val, idx += (idx & -idx);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X;
    vector<int> comp, arr, ans;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back(A[i]);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 1; i <= N; i++)
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;

    for (int i = 1; i <= N; i++) {
        update(A[i], 1), X = i - query(A[i]);

        if (X > 0 && X + 1 >= K) {
            sort(arr.begin(), arr.end());
            for (int j = 0; j < i - K; j++)
                ans.push_back(arr[j]);
            ans.push_back((X + 1 == K) ? A[i] : arr[i - K - 1]);
            for (int j = i - K; j < arr.size(); j++)
                ans.push_back(arr[j]);
            for (int j = i + 1; j <= N; j++)
                ans.push_back(A[j]);
            break;
        } else
            K -= X > 0 ? X + 1 : 0, arr.push_back(A[i]);
    }

    if (ans.empty()) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i : ans)
        cout << comp[i - 1] << ' ';
    cout << '\n';

    return 0;
}