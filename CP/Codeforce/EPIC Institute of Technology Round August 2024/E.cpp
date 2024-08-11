#include <bits/stdc++.h>
#define int long long

#define MAX 300100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int res[MAX];
vector<pr> arr;

void push(int A, int B) {
    int X = 0;
    pr K;

    while (!arr.empty()) {
        if (arr.back().second != B && arr.back().first <= A) {
            X = arr.back().first;
            arr.pop_back();
        } else if (arr.back().second == B) {
            K = arr.back();
            arr.pop_back();
            push(K.first + A - X, B);
            return;
        } else
            break;
    }
    arr.push_back({A, B});
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, A, B, X;
    cin >> T;

    while (T--) {
        cin >> N;
        arr.clear();
    
        for (int i = 1; i <= N; i++) {
            cin >> A >> B;
            push(A, B);

            res[i] = arr[0].first;
        }

        for (int i = 1; i <= N; i++)
            cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}