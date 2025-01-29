#include <bits/stdc++.h>
#define int long long

#define MAX 200000
using namespace std;

int A[MAX], cnt[MAX], cur[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int C, N, ans_sm = 0;
    vector<int> ans;
    cin >> C >> N;

    for (int i = 1; i <= C; i++)
        cur[i] = i;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 2; i <= N; i++)
        cnt[cur[A[i]]]++, cur[A[i - 1]] = cur[A[i]];

    for (int i = 1; i <= C; i++)
        if (i != A[1])
            ans.push_back(i);
    sort(ans.begin(), ans.end(), [&](int x, int y) { return cnt[x] > cnt[y]; });

    for (int i = 0; i < C - 1; i++)
        ans_sm += (i + 1) * cnt[ans[i]];

    cout << ans_sm << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}