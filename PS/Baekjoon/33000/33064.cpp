#include <bits/stdc++.h>
#define int long long

#define MAX 20100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int cnt[2][30][30], pos[MAX];

int check(int A, int B, int C, int X) { return (A != X) && (B != X) && (C != X); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, F;
    string S;
    vector<string> res;

    fill(pos, pos + MAX, -1);

    cin >> N >> F >> S;

    for (int i = 0; i < N - 2; i++)
        if (S[i + 1] == S[i + 2])
            cnt[0][S[i] - 'a'][S[i + 1] - 'a']++, pos[i] = (S[i] - 'a') * 26 + S[i + 1] - 'a';

    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < 26; j++)
            if (S[i + 1] == S[i + 2] && check(i > 1 ? pos[i - 2] : -1, i > 0 ? pos[i - 1] : -1, pos[i], j * 26 + S[i + 1] - 'a'))
                cnt[1][j][S[i + 1] - 'a'] = 1;
        if (check(i > 0 ? pos[i - 1] : -1, pos[i], pos[i + 1], (S[i] - 'a') * 26 + S[i + 2] - 'a'))
            cnt[1][S[i] - 'a'][S[i + 2] - 'a'] = 1;
        if (check(pos[i], pos[i + 1], i + 2 < N - 2 ? pos[i + 2] : -1, (S[i] - 'a') * 26 + S[i + 1] - 'a'))
            cnt[1][S[i] - 'a'][S[i + 1] - 'a'] = 1;
    }

    for (char i = 'a'; i <= 'z'; i++)
        for (char j = 'a'; j <= 'z'; j++)
            if (cnt[0][i - 'a'][j - 'a'] + cnt[1][i - 'a'][j - 'a'] >= F && i != j)
                res.push_back(string(1, i) + string(2, j));

    cout << res.size() << '\n';
    for (string i : res)
        cout << i << '\n';

    return 0;
}