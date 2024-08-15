#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

tp arr[MAX];
bool checked[MAX], checkedX[MAX], checkedY[MAX];
vector<int> arrX[MAX], arrY[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, xS, yS, xE, yE, X, Y, res;
    tp A;
    cin >> N >> xS >> yS >> xE >> yE;

    vector<int> compX, compY;
    compX.push_back(xS), compX.push_back(xE);
    compY.push_back(yS), compY.push_back(yE);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
        compX.push_back(arr[i][0]);
        compY.push_back(arr[i][1]);
        arr[i][2] = i;
    }
    sort(compX.begin(), compX.end());
    sort(compY.begin(), compY.end());
    compX.erase(unique(compX.begin(), compX.end()), compX.end());
    compY.erase(unique(compY.begin(), compY.end()), compY.end());

    for (int i = 1; i <= N; i++) {
        arr[i][0] = lower_bound(compX.begin(), compX.end(), arr[i][0]) - compX.begin();
        arr[i][1] = lower_bound(compY.begin(), compY.end(), arr[i][1]) - compY.begin();
        arrX[arr[i][0]].push_back(i);
        arrY[arr[i][1]].push_back(i);
    }
    xS = lower_bound(compX.begin(), compX.end(), xS) - compX.begin();
    yS = lower_bound(compY.begin(), compY.end(), yS) - compY.begin();
    xE = lower_bound(compX.begin(), compX.end(), xE) - compX.begin();
    yE = lower_bound(compY.begin(), compY.end(), yE) - compY.begin();

    arrX[xE].push_back(N + 1), arrY[yE].push_back(N + 1);
    arr[N + 1][0] = xE, arr[N + 1][1] = yE, arr[N + 1][2] = N + 1;

    queue<tp> q;
    q.push(tp{xS, yS, 0});

    while (!q.empty()) {
        A = q.front(), q.pop();
        if (A[0] == xE && A[1] == yE) {
            cout << A[2] - 1 << endl;
            return 0;
        }

        if (!checkedX[A[0]]) {
            checkedX[A[0]] = true;
            for (int i : arrX[A[0]]) {
                if (!checked[i]) {
                    checked[i] = true;
                    q.push(tp{A[0], arr[i][1], A[2] + 1});
                }
            }
        }
        if (!checkedY[A[1]]) {
            checkedY[A[1]] = true;
            for (int i : arrY[A[1]]) {
                if (!checked[i]) {
                    checked[i] = true;
                    q.push(tp{arr[i][0], A[1], A[2] + 1});
                }
            }
        }
    }

    cout << -1;

    return 0;
}