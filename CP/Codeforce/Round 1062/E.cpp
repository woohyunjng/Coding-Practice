#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

int A[MAX];

void solve() {
    int N, K, X, ans = 0, V, B;
    vector<pr> arr, stk;
    vector<int> ans_val;

    cin >> N >> K >> X;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);

    for (int i = 0; i < K; i++)
        ans_val.push_back(i);

    for (int st = 1, en = X, md; st <= en;) {
        md = st + en >> 1, arr.clear(), stk.clear(), V = B = 0;
        for (int i = 0; i < N; i++)
            arr.push_back({max(0ll, A[i] - md + 1), min(X, A[i] + md - 1)});

        for (pr i : arr) {
            if (!stk.empty() && stk.back()[1] >= i[0])
                stk.back()[1] = max(stk.back()[1], i[1]);
            else
                stk.push_back(i);
        }
        arr.clear();

        for (pr i : stk) {
            V += i[1] - i[0] + 1;
            if (i[0] > B)
                arr.push_back({B, i[0] - 1}), B = i[1] + 1;
            else
                B = max(B, i[1] + 1);
        }
        if (B <= X)
            arr.push_back({B, X});

        if (V + K <= X + 1) {
            ans = md, st = md + 1, V = K, ans_val.clear();
            for (pr i : arr) {
                for (int j = i[0]; j <= i[1] && V > 0; j++, V--)
                    ans_val.push_back(j);
            }
        } else
            en = md - 1;
    }

    for (int i : ans_val)
        cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}