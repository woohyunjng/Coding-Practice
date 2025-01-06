#include <bits/stdc++.h>
#define int long long

#define MAX 101000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    for (int i = 1; i <= N; i++) {
        cin >> A;

        if (i == 1)
            maxHeap.push(A);
        else if (i == 2) {
            if (maxHeap.top() > A)
                minHeap.push(maxHeap.top()), maxHeap.pop(), maxHeap.push(A);
            else
                minHeap.push(A);
        } else {
            if (maxHeap.size() == minHeap.size()) {
                if (minHeap.top() < A)
                    maxHeap.push(minHeap.top()), minHeap.pop(), minHeap.push(A);
                else
                    maxHeap.push(A);
            } else {
                if (maxHeap.top() > A)
                    minHeap.push(maxHeap.top()), maxHeap.pop(), maxHeap.push(A);
                else
                    minHeap.push(A);
            }
        }

        if (i & 1)
            cout << maxHeap.top() << '\n';
    }

    return 0;
}