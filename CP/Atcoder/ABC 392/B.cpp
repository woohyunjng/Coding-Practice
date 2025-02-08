#include <bits/stdc++.h>
#define int long long

#define MAX 2000
using namespace std;

int A[MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    vector<int> ans;
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
        cin >> A[i], chk[A[i]] = true;

    for (int i = 1; i <= N; i++)
        if (!chk[i])
            ans.push_back(i);

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}