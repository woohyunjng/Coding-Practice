#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, K;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    vector<int> vec;
    vec.push_back(1);

    for (int i = 2; i <= N; i++) {
        if (arr[i] == arr[i - 1])
            vec.push_back(1);
        else {
            K = vec.back();
            vec.pop_back();
            vec.push_back(K + 1);
        }
    }

    if (vec.size() < 3) {
        for (int i : vec)
            res += i;
    } else {
        for (int i = 0; i < vec.size() - 2; i++)
            res = max(res, vec[i] + vec[i + 1] + vec[i + 2]);
    }

    cout << res;

    return 0;
}