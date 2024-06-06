#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, L, X, Y;
    cin >> N >> M >> L;

    vector<int> arr[N + 1];
    for (int i = 1 ; i <= N ; i ++) {
        arr[i].push_back(i);
    }

    for (int i = 0 ; i < M ; i ++) {
        cin >> X >> Y;
        vector<int> arr2(arr[Y]);
        for (int j : arr2){
            arr[X].push_back(j);
        }
    }


    int K, U, farr[N + 1] = {0};
    long long int V, res;

    for (int i : arr[1]) {
        farr[i] ++;
    }

    for (int i = 0 ; i < L ; i ++) {
        int varr[N + 1] = {1};
        res = 0;

        cin >> K;
        for (int j = 0 ; j < K ; j ++) {
            cin >> U >> V;
            res += V * farr[U] % 1000000007;
        }

        cout << res % 1000000007;
    }
}
