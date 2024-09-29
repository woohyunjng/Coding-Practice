#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], B[MAX], C[MAX];

map<int, int> cnt;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    vector<int> arr, arr_A;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        arr_A.push_back(A[i]);
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        cnt[B[i]]++;
        arr.push_back(B[i]);
    }

    for (int i = 1; i <= K; i++) {
        cin >> C[i];
        cnt[C[i]]--;
    }

    sort(arr.begin(), arr.end(), greater<int>());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    sort(arr_A.begin(), arr_A.end());

    for (int i : arr) {
        if (cnt[i] > 0) {
            auto it = lower_bound(arr_A.begin(), arr_A.end(), i);
            if (it != arr_A.end() && *it == i)
                cout << i;
            else
                cout << *prev(it);
            break;
        }
    }

    return 0;
}