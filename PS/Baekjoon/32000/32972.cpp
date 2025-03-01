#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 3> tp;

const int MAX = 5000;

int N, cnt[MAX][3], A[MAX][MAX];
bool vst[MAX];

int chk(int X) {
    if (cnt[X][1] == 0 && cnt[X][2] == 0)
        return 0;
    else if (cnt[X][1] == 0)
        return 2;
    else if (cnt[X][2] == 0)
        return 1;
    return -1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, K;
    bool flag;

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j], cnt[i][A[i][j]]++, cnt[j + N][A[i][j]]++;
            if (!A[i][j])
                vst[i] = true, vst[j + N] = true;
        }

    vector<tp> ans, res;
    queue<int> q;

    for (int i = 1; i <= N * 2; i++) {
        K = chk(i);
        if (vst[i] || K == -1)
            continue;
        q.push(i), vst[i] = true;
        res.push_back({(i > N) + 1, i - (i > N) * N, K});
    }

    while (!q.empty()) {
        X = q.front(), q.pop();

        if (X > N) {
            for (int i = 1; i <= N; i++)
                cnt[i][A[i][X - N]]--, A[i][X - N] = 0;
        } else {
            for (int i = 1; i <= N; i++)
                cnt[i + N][A[X][i]]--, A[X][i] = 0;
        }

        for (int i = 1; i <= N * 2; i++) {
            K = chk(i);
            if (vst[i] || K == -1)
                continue;
            q.push(i), vst[i] = true;
            res.push_back({(i > N) + 1, i - (i > N) * N, K});
        }
    }

    flag = true;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            flag &= A[i][j] == 0;

    if (!flag)
        cout << -1 << '\n';
    else {
        reverse(res.begin(), res.end());
        for (tp i : res) {
            if (i[2] == 0)
                continue;
            ans.push_back(i);
        }

        cout << ans.size() << '\n';
        for (tp i : ans)
            cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
    }

    return 0;
}