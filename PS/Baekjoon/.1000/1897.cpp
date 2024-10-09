#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX];
bool vst[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int D, val = 0, X;
    string S, res;

    vector<string> A;

    cin >> D >> S;
    A.push_back(S);

    for (int i = 1; i <= D; i++) {
        cin >> S;
        A.push_back(S);
    }

    for (int i = 0; i <= D; i++) {
        for (int j = 0; j <= D; j++) {
            if (A[j].size() != A[i].size() + 1)
                continue;
            val = 0;
            for (int k = 0; k < A[j].size() && val < A[i].size(); k++)
                if (A[j][k] == A[i][val])
                    val++;
            if (val == A[i].size())
                arr[i].push_back(j);
        }
    }

    queue<int> q;
    q.push(0);
    vst[0] = true;

    while (!q.empty()) {
        X = q.front(), q.pop();
        res = A[X];

        for (int i : arr[X]) {
            if (vst[i])
                continue;
            vst[i] = true;
            q.push(i);
        }
    }

    cout << res;

    return 0;
}