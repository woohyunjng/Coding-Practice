#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 9001;

int A[MAX][MAX], B[MAX][4], V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int W, H, N, SX, SY, ans = 0, X, Y;
    vector<int> compX, compY;
    vector<pr> st;

    cin >> W >> H >> N;

    compX.push_back(0), compX.push_back(W);
    compY.push_back(0), compY.push_back(H);

    for (int i = 1; i <= N; i++) {
        cin >> B[i][0] >> B[i][1] >> B[i][2] >> B[i][3];
        compX.push_back(B[i][0]), compX.push_back(B[i][2]);
        compY.push_back(B[i][1]), compY.push_back(B[i][3]);
    }

    sort(compX.begin(), compX.end()), compX.erase(unique(compX.begin(), compX.end()), compX.end());
    sort(compY.begin(), compY.end()), compY.erase(unique(compY.begin(), compY.end()), compY.end());
    SX = compX.size(), SY = compY.size();

    for (int i = 1; i <= N; i++) {
        B[i][0] = lower_bound(compX.begin(), compX.end(), B[i][0]) - compX.begin() + 1;
        B[i][1] = lower_bound(compY.begin(), compY.end(), B[i][1]) - compY.begin() + 1;
        B[i][2] = lower_bound(compX.begin(), compX.end(), B[i][2]) - compX.begin() + 1;
        B[i][3] = lower_bound(compY.begin(), compY.end(), B[i][3]) - compY.begin() + 1;

        A[B[i][0]][B[i][1]]++, A[B[i][2]][B[i][1]]--;
        A[B[i][0]][B[i][3]]--, A[B[i][2]][B[i][3]]++;
    }

    for (int i = 1; i <= SX; i++)
        for (int j = 1; j <= SY; j++)
            A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];

    fill(V, V + SY, 1);
    for (int i = 2; i <= SX; i++) {
        for (int j = 1; j <= SY - 1; j++)
            if (A[i - 1][j])
                V[j] = i;
        V[0] = V[SY] = i, st.clear();

        for (int j = 1; j <= SY; j++) {
            X = i - V[j], Y = j;
            while (!st.empty() && st.back()[0] > X) {
                Y = st.back()[1];
                ans = max(ans, (compY[j - 1] - compY[st.back()[1] - 1]) * (compX[i - 1] - compX[i - st.back()[0] - 1]));
                st.pop_back();
            }
            if (X)
                st.push_back({X, Y});
        }
    }

    cout << ans << '\n';

    return 0;
}