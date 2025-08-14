#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

int A[MAX], B[MAX], L[MAX], R[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    vector<int> arr, lis;
    vector<pr> st;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    for (int i = 1; i <= N; i++) {
        while (!st.empty() && st.back()[0] >= -A[i])
            st.pop_back();
        st.push_back({-A[i], i});

        X = lower_bound(st.begin(), st.end(), (pr){-B[i], 0}) - st.begin();
        if (X < st.size() && st[X][0] == -B[i])
            L[i] = st[X][1];
    }

    st.clear();
    for (int i = N; i >= 1; i--) {
        while (!st.empty() && st.back()[0] >= -A[i])
            st.pop_back();
        st.push_back({-A[i], i});

        X = lower_bound(st.begin(), st.end(), (pr){-B[i], 0}) - st.begin();
        if (X < st.size() && st[X][0] == -B[i])
            R[i] = st[X][1];
    }

    for (int i = 1; i <= N; i++) {
        if (R[i])
            arr.push_back(R[i]);
        if (L[i] != R[i] && L[i])
            arr.push_back(L[i]);
    }

    for (int i : arr) {
        if (lis.empty() || lis.back() <= i)
            lis.push_back(i);
        else
            lis[upper_bound(lis.begin(), lis.end(), i) - lis.begin()] = i;
    }

    cout << lis.size() << '\n';
}