#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 2000;

int A[MAX], B[MAX], state[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, V = 0, X, ans = 0;
    bool flag = true;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        pq.push({B[i], i});
    }

    while (true) {
        flag = false;
        while (!pq.empty() && V >= pq.top()[0])
            K = pq.top(), pq.pop(), V += 2 - state[K[1]], ans++, state[K[1]] = 2, flag = true;
        X = 0;
        for (int i = 1; i <= N; i++) {
            if (state[i] != 0 || A[i] > V)
                continue;
            if (B[X] <= B[i])
                X = i;
        }
        if (X != 0)
            flag = true, V++, ans++, state[X] = 1;
        if (!flag)
            break;
    }

    flag = true;
    for (int i = 1; i <= N; i++)
        flag &= state[i] == 2;

    if (flag)
        cout << ans << '\n';
    else
        cout << "Too Bad" << '\n';

    return 0;
}