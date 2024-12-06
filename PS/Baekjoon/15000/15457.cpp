#include <bits/stdc++.h>
#define int long long

#define MAX 200100

using namespace std;
typedef pair<int, int> pr;

int A[MAX], B[MAX], res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, D, X, K;
    queue<int> q;

    set<pr> st[2];
    set<pr>::iterator it;

    cin >> N >> D;
    fill(res + 1, res + N + 1, -1);

    for (int i = 1; i <= 2 * N; i++) {
        cin >> A[i] >> B[i];
        if ((B[i] == 0 && i <= N) || (A[i] == 0 && i > N))
            q.push(i), res[i] = 1;
        else if (i <= N)
            st[0].insert({B[i], i});
        else
            st[1].insert({A[i], i});
    }

    while (!q.empty()) {
        X = q.front(), q.pop();
        if (X <= N) {
            while (true) {
                it = st[1].lower_bound({A[X] - D, 0});
                if (it == st[1].end() || it->first > A[X])
                    break;
                K = it->second, st[1].erase(it);
                q.push(K), res[K] = res[X] + 1;
            }
        } else {
            while (true) {
                it = st[0].lower_bound({B[X] - D, 0});
                if (it == st[0].end() || it->first > B[X])
                    break;
                K = it->second, st[0].erase(it);
                q.push(K), res[K] = res[X] + 1;
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << '\n';

    return 0;
}