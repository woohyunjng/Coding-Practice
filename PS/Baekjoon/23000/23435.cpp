#include <bits/stdc++.h>

using namespace std;

bool compare(int A, int B) {
    char C;
    cout << "? " << A << ' ' << B << '\n', cout.flush();
    cin >> C;
    return C == '>';
}

int main() {
    int N, res;
    vector<int> arr, temp;
    vector<vector<int>> fail(N);

    cin >> N;
    for (int i = 0; i < N; i++)
        arr.push_back(i);

    while (arr.size() > 1) {
        temp.clear();
        for (int i = 1; i < arr.size(); i += 2) {
            if (compare(arr[i - 1], arr[i]))
                temp.push_back(arr[i - 1]), fail[arr[i - 1]].push_back(arr[i]);
            else
                temp.push_back(arr[i]), fail[arr[i]].push_back(arr[i - 1]);
        }
        if (arr.size() % 2 == 1)
            temp.push_back(arr.back());
        swap(arr, temp);
    }
    res = arr[0], arr = fail[res];

    while (arr.size() > 1) {
        temp.clear();
        for (int i = 1; i < arr.size(); i += 2) {
            if (compare(arr[i - 1], arr[i]))
                temp.push_back(arr[i - 1]);
            else
                temp.push_back(arr[i]);
        }
        if (arr.size() % 2 == 1)
            temp.push_back(arr.back());
        swap(arr, temp);
    }

    res = arr[0];
    cout << "! " << res << '\n', cout.flush();
}
