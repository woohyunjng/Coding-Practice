struct FastInput {
    static const int SZ = 1 << 20;
    int idx, size;
    char buf[SZ];

    FastInput() : idx(0), size(0) {}

    inline char readChar() {
        if (idx >= size) {
            size = (int)fread(buf, 1, SZ, stdin);
            idx = 0;
            if (size == 0)
                return 0;
        }
        return buf[idx++];
    }

    template <typename T>
    inline bool readInt(T &out) {
        char c = readChar();
        if (!c)
            return false;
        while (c <= ' ') {
            c = readChar();
            if (!c)
                return false;
        }
        T sign = 1;
        if (c == '-') {
            sign = -1;
            c = readChar();
        }
        T val = 0;
        while (c > ' ') {
            val = val * 10 + (c - '0');
            c = readChar();
        }
        out = val * sign;
        return true;
    }
} In;

struct FastOutput {
    static const int SZ = 1 << 20;
    int idx;
    char buf[SZ];

    FastOutput() : idx(0) {}

    inline void flush() {
        if (idx) {
            fwrite(buf, 1, idx, stdout);
            idx = 0;
        }
    }

    inline void pushChar(char c) {
        if (idx >= SZ)
            flush();
        buf[idx++] = c;
    }

    template <typename T>
    inline void writeInt(T x, char endc) {
        if (x == 0) {
            pushChar('0');
            pushChar(endc);
            return;
        }
        if (x < 0) {
            pushChar('-');
            x = -x;
        }
        char s[24];
        int n = 0;
        while (x) {
            s[n++] = char('0' + (x % 10));
            x /= 10;
        }
        for (int i = n - 1; i >= 0; i--)
            pushChar(s[i]);
        pushChar(endc);
    }

    ~FastOutput() {
        flush();
    }
} Out;

// In.readInt(N)
// Out.writeInt(X, '\n');