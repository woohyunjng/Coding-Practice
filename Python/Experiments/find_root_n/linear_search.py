def find_root(n, decimal=10):
    under_one = 1
    if n > 1:
        under_one = n
        n = 1 / n

    root_n = 0
    for i in range(1, decimal + 1):
        for j in range(0, 10):
            if (root_n + j / 10**i) ** 2 < n < (root_n + (j + 1) / 10**i) ** 2:
                root_n += j / 10**i
                break

    return under_one * root_n
