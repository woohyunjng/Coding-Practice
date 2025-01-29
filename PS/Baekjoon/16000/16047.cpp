#include <bits/stdc++.h>
#define int long long

#define MAX 100
using namespace std;

int ans[MAX][MAX], RS[MAX], CS[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int R, C, Rsum = 0, Csum = 0, X = 0, Y = 0;
    vector<int> Rv, Cv;
    string rs, cs;

    cin >> rs >> cs, R = rs.size(), C = cs.size();

    for (int i = 0; i < R; i++) {
        RS[i] = rs[i] == '1', Rsum += RS[i];
        if ((RS[i] & 1) != (C & 1))
            Rv.push_back(i);
    }

    for (int i = 0; i < C; i++) {
        CS[i] = cs[i] == '1', Csum += CS[i];
        if ((CS[i] & 1) != (R & 1))
            Cv.push_back(i);
    }

    if (Rsum % 2 != Csum % 2) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            ans[i][j] = 1;

    for (; X < (int)Rv.size() - (int)Cv.size(); X++)
        ans[Rv[X]][0] = 0;
    for (; Y < (int)Cv.size() - (int)Rv.size(); Y++)
        ans[0][Cv[Y]] = 0;
    for (; X < Rv.size() && Y < Cv.size(); X++, Y++)
        ans[Rv[X]][Cv[Y]] = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << ans[i][j];
        cout << '\n';
    }

    return 0;
}