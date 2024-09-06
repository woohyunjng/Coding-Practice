#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

map<string, int> dic;
int dic_cnt, enc[10000], enc_cnt;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    string S, X;

    vector<string> res;

    cin >> N;
    cin >> S;

    for (char i : S) {
        X = string(1, i);
        if (dic.find(X) == dic.end()) {
            dic[X] = dic_cnt++;
            res.push_back(X);
        }
    }

    X = "";
    enc_cnt = 1;

    for (char i : S) {
        if (dic.find(X + i) == dic.end()) {
            dic[X + i] = dic_cnt++;
            res.push_back(X + i);
            enc[enc_cnt++] = dic[X];
            X = string(1, i);
        } else
            X += i;
    }

    for (int i = 0; i < dic_cnt; i++)
        cout << i + 1 << ':' << res[i] << '\n';

    return 0;
}