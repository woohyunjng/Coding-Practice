#include <bits/stdc++.h>

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200001;

string S[MAX];
int V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, ans = 0, X, Y;
    vector<pr> st;

    cin >> H >> W;
    for (int i = 0; i < H; i++)
        cin >> S[i];

    for (int i = W - 1; i >= 0; i--) {
        st.clear(), X = 0;
        for (int j = 0; j < H; j++) {
            V[j] = (S[j][i] == '1') ? V[j] + 1 : 0, Y = 1;
            while (!st.empty() && st.back()[0] > V[j])
                X -= st.back()[0] * st.back()[1], Y += st.back()[1], st.pop_back();
            st.push_back({V[j], Y}), X += V[j] * Y, ans = max(ans, X);
        }
    }

    cout << ans << '\n';

    return 0;
}