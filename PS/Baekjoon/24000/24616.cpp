#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int parent[MAX];
pr val[11];

int find(int K) {
    if (parent[K] != K)
        parent[K] = find(parent[K]);
    return parent[K];
}

void uni(int A, int B) {
    A = find(A), B = find(B);
    if (A > B)
        swap(A, B);
    parent[B] = A;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, res = 0;
    vector<tp> arr, link;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        arr.push_back({A, B, i});
        parent[i] = i;
    }

    for (int i = 0; i <= 10; i++)
        val[i] = {-1, -1};

    sort(arr.begin(), arr.end());

    for (tp i : arr) {
        for (int j = 0; j < 11; j++) {
            if (val[j].second == -1)
                continue;
            link.push_back({(j - i[1]) * (j - i[1]) + (val[j].first - i[0]) * (val[j].first - i[0]), i[2], val[j].second});
        }
        val[i[1]] = {i[0], i[2]};
    }

    sort(link.begin(), link.end());

    for (tp i : link) {
        A = find(i[1]), B = find(i[2]);
        if (A == B)
            continue;
        uni(A, B);
        res += i[0];
    }

    cout << res;

    return 0;
}