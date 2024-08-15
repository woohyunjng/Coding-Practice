#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int child[MAX][2], cnt[MAX];

void preorder(int root) {
    if (!root)
        return;
    cout << root << ' ';
    preorder(child[root][0]);
    preorder(child[root][1]);
}

void inorder(int root) {
    if (!root)
        return;
    inorder(child[root][0]);
    cout << root << ' ';
    inorder(child[root][1]);
}

void postorder(int root) {
    if (!root)
        return;
    postorder(child[root][0]);
    postorder(child[root][1]);
    cout << root << ' ';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, root;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> child[i][0] >> child[i][1];
        cnt[child[i][0]]++;
        cnt[child[i][1]]++;
    }

    for (int i = 1; i <= N; i++)
        if (!cnt[i])
            root = i;

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    return 0;
}