#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 500001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans = 0;
    deque<pr> mn, mx;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i < K; i++) {
        while (!mn.empty() && mn.back()[0] > A[i])
            mn.pop_back();
        mn.push_back({A[i], i});

        while (!mx.empty() && mx.back()[0] < A[i])
            mx.pop_back();
        mx.push_back({A[i], i});
    }

    for (int i = K; i <= N; i++) {
        while (!mn.empty() && mn.back()[0] > A[i])
            mn.pop_back();
        while (!mn.empty() && mn.front()[1] <= i - K)
            mn.pop_front();
        mn.push_back({A[i], i});

        while (!mx.empty() && mx.back()[0] < A[i])
            mx.pop_back();
        while (!mx.empty() && mx.front()[1] <= i - K)
            mx.pop_front();
        mx.push_back({A[i], i});

        if (mx.front()[0] - mn.front()[0] == K - 1)
            ans = i;
    }

    if (ans == 0)
        cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        for (int i = ans - K + 1; i <= ans; i++)
            cout << A[i] << ' ';
        cout << '\n';
    }

    return 0;
}