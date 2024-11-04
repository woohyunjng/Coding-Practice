#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

pr go[MAX][MAX];
int cnt[MAX][MAX];
bool vst[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, K;
    string S;
    char T;
    pr st;

    vector<pr> arr;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> S;
            T = S.back(), S.pop_back();
            K = stoi(S);

            X = i, Y = j;

            if (T == 'U')
                X -= K;
            else if (T == 'D')
                X += K;
            else if (T == 'L')
                Y -= K;
            else
                Y += K;

            go[i][j] = {X, Y}, cnt[X][Y]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!cnt[i][j])
                arr.push_back({i, j});
        }
    }

    if (arr.size() > 1)
        cout << "TOO SAFE";
    else {
        st = !arr.empty() ? arr[0] : (pr){1, 1}, X = 0;
        while (!vst[st.first][st.second] && go[st.first][st.second].first != 0)
            vst[st.first][st.second] = true, X++, st = go[st.first][st.second];

        if (X != N * N)
            cout << "TOO SAFE";
        else {
            if (arr.size() == 0)
                cout << "THIEF LOVE IT!";
            else
                cout << arr[0].first << ' ' << arr[0].second;
        }
    }

    return 0;
}