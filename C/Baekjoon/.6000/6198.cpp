#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N, h;
    long long int res = 0;
    cin >> N;

    stack<int> s;
    for (int i = 0 ; i < N ; i ++) {
        cin >> h;

        while (!s.empty() && s.top() <= h)
            s.pop();
        s.push(h);

        res += s.size() - 1;
    }

    cout << res;
}
