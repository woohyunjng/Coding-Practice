#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;

int parent[MAX], res[MAX], cnt[MAX];
set<int> S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A, cur = 0, val = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A;
        parent[i] = A;
        if (A > 0)
            cnt[A]++;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        cin >> A;
        S[i].insert(A);
        if (!cnt[i])
            q.push(i);
    }

    while (!q.empty()) {
        A = q.front();
        q.pop();

        val = 0;
        for (int i : S[A]) {
            if (i != val)
                break;
            val++;
        }

        res[A] = val;
        if (parent[A] == -1)
            break;
        if (!--cnt[parent[A]])
            q.push(parent[A]);

        if (S[A].size() > S[parent[A]].size())
            swap(S[A], S[parent[A]]);
        for (int i : S[A])
            S[parent[A]].insert(i);
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << '\n';

    return 0;
}