def find_root(n, decimal=10):
    under_one = 1
    if n > 1:
        under_one = n
        n = 1 / n

    root_n = 0
    for i in range(1, decimal + 1):
        lo = 0
        hi = 10
        md = 5

        while lo + 1 < hi:
            md = (lo + hi) // 2
            if (root_n + md / 10**i) ** 2 > n:
                hi = md - 1
            else:
                lo = md + 1

        root_n += md / 10**i

    return under_one * root_n
