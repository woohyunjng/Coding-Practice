#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, S, a, U, V, W, C;
    cin >> N >> M >> K >> S;

    bool item[K + 1] = {}, rode_item[M];
    vector<int> rode[M];
    vector<pair<int, int>> arr[N + 1];

    for (int i = 0 ; i < S ; i ++) {
        cin >> a;
        item[a] = true;
    }

    for (int i = 0 ; i < M ; i ++) {
        cin >> U >> V >> W >> C;
        arr[U].push_back(make_pair(V, i));
        arr[V].push_back(make_pair(U, i));
        rode_item[i] = W;

        for (int j = 0 ; j < C ; j ++) {
            cin >> a;
            rode[i].push_back(a);
        }
    }

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        p = q.top();
        q.pop();


    }
}
