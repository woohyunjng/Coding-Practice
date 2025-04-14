#include <bits/stdc++.h>
#define int long long

using namespace std;

int N;
vector<string> arr;
string ans;

void dfs1(int node) {
    if (node > N)
        return;

    if (!isdigit(arr[node - 1][0]))
        cout << '(';
    dfs1(node << 1);
    cout << arr[node - 1];
    dfs1(node << 1 | 1);
    if (!isdigit(arr[node - 1][0]))
        cout << ')';
}

void dfs2(int node) {
    if (node > N)
        return;

    dfs2(node << 1), dfs2(node << 1 | 1);
    cout << arr[node - 1] << ' ';
}

int dfs3(int node) {
    if (isdigit(arr[node - 1][0]))
        return stoi(arr[node - 1]);
    else if (arr[node - 1] == "+")
        return dfs3(node << 1) + dfs3(node << 1 | 1);
    else if (arr[node - 1] == "-")
        return dfs3(node << 1) - dfs3(node << 1 | 1);
    else if (arr[node - 1] == "*")
        return dfs3(node << 1) * dfs3(node << 1 | 1);
    else
        return dfs3(node << 1) / dfs3(node << 1 | 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int ret;
    string S;

    while (cin >> S)
        arr.push_back(S);
    N = arr.size();

    dfs1(1), cout << '\n';
    dfs2(1), cout << '\n';

    ret = dfs3(1);
    cout << ret << '\n';

    return 0;
}