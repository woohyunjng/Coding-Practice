#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;

int N, K,
    A[MAX], B[MAX], ans[MAX];
bool used[MAX];

bool chk(int P) {
    set<pr> st;
    set<pr>::iterator iter;

    vector<int> arr;

    int D = 0, V = 0;
    pr X;

    for (int i = 1; i <= N; i++) {
        if (!used[i])
            D += B[i], V += A[i] - B[i], st.insert({A[i] - B[i], i}), ans[i] = 0;
        else
            D += A[i], ans[i] = 1;

        while (D + V > P) {
            if (st.empty())
                return false;
            iter = prev(st.end()), V -= (*iter)[0], st.erase(iter);
        }

        while (D < 0) {
            if (st.empty()) {
                D = 0;
                break;
            }

            X = *st.begin(), st.erase(st.begin()), V -= X[0];
            if (D + X[0] < 0)
                D += X[0], arr.push_back(X[1]);
            else
                st.insert({D + X[0], X[1]}), V += D + X[0], D = 0;
        }
    }

    for (pr i : st)
        arr.push_back(i[1]);

    if (arr.size() < K)
        return false;

    for (int i = 0; i < K; i++)
        ans[arr[i]] = 1;
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int C = 0, T = 0, ans_val;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i], C += A[i] <= B[i];

    if (C > K) {
        T = 1, K = N - K;
        for (int i = 1; i <= N; i++)
            swap(A[i], B[i]);
    }

    for (int i = 1; i <= N; i++)
        if (A[i] < B[i])
            used[i] = true, K--;

    for (int st = 0, en = 200'000'000'000'000, md; st <= en;) {
        md = st + en >> 1;
        if (chk(md))
            ans_val = md, en = md - 1;
        else
            st = md + 1;
    }

    chk(ans_val);
    cout << ans_val << '\n';

    for (int i = 1; i <= N; i++)
        cout << ((ans[i] ^ T) ? 'A' : 'B');
    cout << '\n';

    return 0;
}