#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> compressed;

void compress(vector<int> arr)
{
    compressed = arr;
    sort(compressed.begin(), compressed.end());
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
}

int get_id(int A) { return lower_bound(compressed.begin(), compressed.end(), A) - compressed.begin(); }

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> X(N);
    for (int i = 0; i < N; i++)
        cin >> X[i];

    compress(X);

    for (int i = 0; i < N; i++)
        cout << get_id(X[i]) << ' ';
}