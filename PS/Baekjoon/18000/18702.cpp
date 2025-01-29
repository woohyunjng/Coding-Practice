#include <bits/stdc++.h>
#define int long long

#define MAX 200000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

constexpr int SZ = 1 << 20;

class INPUT {
  private:
    char read_buf[SZ];
    int read_idx, next_idx;
    bool __END_FLAG__, __GETLINE_FLAG__;

  public:
    explicit operator bool() { return !__END_FLAG__; }
    bool IsBlank(char c) { return c == ' ' || c == '\n'; }
    bool IsEnd(char c) { return c == '\0'; }
    char _ReadChar() {
        if (read_idx == next_idx) {
            next_idx = fread(read_buf, sizeof(char), SZ, stdin);
            if (next_idx == 0)
                return 0;
            read_idx = 0;
        }
        return read_buf[read_idx++];
    }
    char ReadChar() {
        char ret = _ReadChar();
        for (; IsBlank(ret); ret = _ReadChar())
            ;
        return ret;
    }
    template <typename T>
    T ReadInt() {
        T ret = 0;
        char cur = _ReadChar();
        bool flag = 0;
        for (; IsBlank(cur); cur = _ReadChar())
            ;
        if (cur == '-')
            flag = 1, cur = _ReadChar();
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar())
            ret = 10 * ret + (cur & 15);
        if (IsEnd(cur))
            __END_FLAG__ = 1;
        return flag ? -ret : ret;
    }
    string ReadString() {
        string ret;
        char cur = _ReadChar();
        for (; IsBlank(cur); cur = _ReadChar())
            ;
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar())
            ret.push_back(cur);
        if (IsEnd(cur))
            __END_FLAG__ = 1;
        return ret;
    }
    double ReadDouble() {
        string ret = ReadString();
        return stod(ret);
    }
    string getline() {
        string ret;
        char cur = _ReadChar();
        for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar())
            ret.push_back(cur);
        if (__GETLINE_FLAG__)
            __END_FLAG__ = 1;
        if (IsEnd(cur))
            __GETLINE_FLAG__ = 1;
        return ret;
    }
    friend INPUT &getline(INPUT &in, string &s) {
        s = in.getline();
        return in;
    }
} _in;

class OUTPUT {
  private:
    char write_buf[SZ];
    int write_idx;

  public:
    ~OUTPUT() { Flush(); }
    explicit operator bool() { return 1; }
    void Flush() {
        fwrite(write_buf, sizeof(char), write_idx, stdout);
        write_idx = 0;
    }
    void WriteChar(char c) {
        if (write_idx == SZ)
            Flush();
        write_buf[write_idx++] = c;
    }
    template <typename T>
    int GetSize(T n) {
        int ret = 1;
        for (n = n >= 0 ? n : -n; n >= 10; n /= 10)
            ret++;
        return ret;
    }
    template <typename T>
    void WriteInt(T n) {
        int sz = GetSize(n);
        if (write_idx + sz >= SZ)
            Flush();
        if (n < 0)
            write_buf[write_idx++] = '-', n = -n;
        for (int i = sz; i-- > 0; n /= 10)
            write_buf[write_idx + i] = n % 10 | 48;
        write_idx += sz;
    }
    void WriteString(string s) {
        for (auto &c : s)
            WriteChar(c);
    }
    void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT &operator>>(INPUT &in, char &i) {
    i = in.ReadChar();
    return in;
}
INPUT &operator>>(INPUT &in, string &i) {
    i = in.ReadString();
    return in;
}
template <typename T, typename std::enable_if_t<is_arithmetic_v<T>> * = nullptr>
INPUT &operator>>(INPUT &in, T &i) {
    if constexpr (is_floating_point_v<T>)
        i = in.ReadDouble();
    else if constexpr (is_integral_v<T>)
        i = in.ReadInt<T>();
    return in;
}

OUTPUT &operator<<(OUTPUT &out, char i) {
    out.WriteChar(i);
    return out;
}
OUTPUT &operator<<(OUTPUT &out, string i) {
    out.WriteString(i);
    return out;
}
template <typename T, typename std::enable_if_t<is_arithmetic_v<T>> * = nullptr>
OUTPUT &operator<<(OUTPUT &out, T i) {
    if constexpr (is_floating_point_v<T>)
        out.WriteDouble(i);
    else if constexpr (is_integral_v<T>)
        out.WriteInt<T>(i);
    return out;
}

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT

struct Node {
    int sum = 0, mx = 0, mn = 0;
};

int A[MAX], lazy[MAX * 4][2];
Node tree[MAX * 4];

Node merge(Node X, Node Y) { return {X.sum + Y.sum, max(X.mx, Y.mx), min(X.mn, Y.mn)}; }

void lazy_propagate(int n, int s, int e) {
    if (lazy[n][1] != 0) {
        tree[n].sum = (lazy[n][0] + lazy[n][1]) * (e - s + 1), tree[n].mn = tree[n].mx = lazy[n][0] + lazy[n][1];
        if (s != e) {
            lazy[n << 1][0] = lazy[n][0], lazy[n << 1 | 1][0] = lazy[n][0];
            lazy[n << 1][1] = lazy[n][1], lazy[n << 1 | 1][1] = lazy[n][1];
        }
    } else {
        tree[n].sum += lazy[n][0] * (e - s + 1), tree[n].mn += lazy[n][0], tree[n].mx += lazy[n][0];
        if (s != e)
            lazy[n << 1][0] += lazy[n][0], lazy[n << 1 | 1][0] += lazy[n][0];
    }
    lazy[n][0] = lazy[n][1] = 0;
}

void init(int n, int s, int e) {
    lazy[n][0] = lazy[n][1] = 0;
    if (s == e)
        tree[n] = {A[s], A[s], A[s]};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int l, int r, int x) {
    bool flag = false;
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        if (x != -1)
            lazy[n][0] += x, flag = true;
        else {
            if (floor(sqrt(tree[n].mn)) == floor(sqrt(tree[n].mx)))
                lazy[n][1] = floor(sqrt(tree[n].mn)), flag = true;
            else if (tree[n].mn + 1 == tree[n].mx)
                lazy[n][0] += floor(sqrt(tree[n].mn)) - tree[n].mn, flag = true;
        }
        lazy_propagate(n, s, e);
        if (flag)
            return;
    }

    int m = s + e >> 1;
    update(n << 1, s, m, l, r, x), update(n << 1 | 1, m + 1, e, l, r, x);
    tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
}

int query(int n, int s, int e, int l, int r) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n].sum;
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

signed main() {
    int tc, N, Q, T, L, R, X;
    cin >> tc;

    while (tc--) {
        cin >> N >> Q;

        for (int i = 1; i <= N; i++)
            cin >> A[i];
        init(1, 1, N);

        while (Q--) {
            cin >> T >> L >> R;
            if (T == 1)
                update(1, 1, N, L, R, -1);
            else if (T == 2)
                cout << query(1, 1, N, L, R) << '\n';
            else
                cin >> X, update(1, 1, N, L, R, X);
        }
    }

    return 0;
}