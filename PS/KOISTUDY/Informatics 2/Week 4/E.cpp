#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

void divide_and_conquer(int N, string S) {
    bool same = true;
    for (int i = 1; i < N; i++)
        same = same && S[i] == S[i - 1];

    if (same) {
        cout << S[0];
        return;
    }

    cout << "-";
    divide_and_conquer(N / 2, S.substr(0, N / 2));
    divide_and_conquer(N / 2, S.substr(N / 2));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    string S;

    cin >> N >> S;
    divide_and_conquer(N, S);

    return 0;
}