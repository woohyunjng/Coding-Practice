#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class Manacher {
  public:
    string S, K;
    vector<int> rad;

    Manacher(string S) : S(S) {
        K = "#";
        for (char i : S) {
            K.push_back(i);
            K.push_back('#');
        }
        rad.resize(K.size());
    }

    void build() {
        int r = -1, c = -1;
        for (int i = 0; i < K.size(); i++) {
            if (i <= r)
                rad[i] = min(r - i, rad[2 * c - i]);
            while (i - rad[i] - 1 >= 0 && i + rad[i] + 1 < K.size() && K[i - rad[i] - 1] == K[i + rad[i] + 1])
                rad[i]++;
            if (r < i + rad[i]) {
                r = i + rad[i];
                c = i;
            }
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int res = 0;
    string S;
    cin >> S;

    Manacher manacher(S);
    manacher.build();

    for (int i : manacher.rad)
        res += (i + 1) / 2;

    cout << res;

    return 0;
}