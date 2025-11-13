#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

int V[MAX], C[MAX];

signed main() {
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, ans = 0, T, L, M = 0;
    bool flag = true;

    vector<pr> arr, st;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T >> L, flag &= T >= L, M = max(M, T);
        arr.push_back({T, T - L}), C[T]++;
    }

    sort(arr.begin(), arr.end(), [&](pr x, pr y) {
        if (x[0] == y[0])
            return x[1] > y[1];
        return x[0] < y[0];
    });

    for (pr i : arr) {
        while (!st.empty() && st.back()[1] >= i[1])
            st.pop_back();
        st.push_back(i);
    }
    reverse(st.begin(), st.end());

    for (int i = 1; i <= M; i++) {
        T = st.empty() ? MAX : st.back()[1], V[i] = min(V[i - 1] + 1, T);
        while (!st.empty() && st.back()[0] <= i)
            st.pop_back();
        ans += C[i] * V[i];
    }

    cout << (flag ? ans : -1) << '\n';

    return 0;
}