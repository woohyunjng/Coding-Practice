#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 70001;
const int BUCKET = 260;

int X[MAX], Y[MAX];
bool chk[MAX];

vector<int> arr[MAX];
unordered_map<int, int> mp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, SX, SY, S;
    vector<int> compX, compY;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        compX.push_back(X[i]), compY.push_back(Y[i]);
    }

    sort(compX.begin(), compX.end()), compX.erase(unique(compX.begin(), compX.end()), compX.end()), SX = compX.size();
    sort(compY.begin(), compY.end()), compY.erase(unique(compY.begin(), compY.end()), compY.end()), SY = compY.size();

    for (int i = 0; i < N; i++) {
        X[i] = lower_bound(compX.begin(), compX.end(), X[i]) - compX.begin() + 1;
        Y[i] = lower_bound(compY.begin(), compY.end(), Y[i]) - compY.begin() + 1;
        arr[X[i]].push_back(Y[i]);
    }

    for (int i = 1; i <= SX; i++) {
        sort(arr[i].begin(), arr[i].end());

        if (arr[i].size() <= BUCKET) {
            for (int j = 0; j < arr[i].size(); j++)
                for (int k = j + 1; k < arr[i].size(); k++)
                    ans += mp[arr[i][j] * SY + arr[i][k]]++;
        } else {
            for (int j : arr[i])
                chk[j] = true;
            for (int j = 1; j <= SX; j++) {
                if (i == j || (j > i && arr[j].size() > BUCKET))
                    continue;
                S = 0;
                for (int k : arr[j])
                    if (chk[k])
                        S++;
                ans += S * (S - 1) / 2;
            }
            for (int j : arr[i])
                chk[j] = false;
        }
    }

    cout << ans << '\n';

    return 0;
}