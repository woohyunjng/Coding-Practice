#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, H, ans = 0, VL, VR;
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<int>> R;

    cin >> N >> H;
    for (int i = 1; i <= N; i++)
        cin >> S[i];

    L.push(S[1] + H), R.push(S[1] - H);
    for (int i = 2; i <= N; i++) {
        VL = L.top() - i * H, VR = R.top() + i * H;
        if (S[i] < VL) {
            ans += VL - S[i], R.push(VL - i * H), L.pop();
            L.push(S[i] + i * H), L.push(S[i] + i * H);
        } else if (S[i] > VR) {
            ans += S[i] - VR, L.push(VR + i * H), R.pop();
            R.push(S[i] - i * H), R.push(S[i] - i * H);
        } else
            L.push(S[i] + i * H), R.push(S[i] - i * H);
    }

    cout << ans << '\n';

    return 0;
}