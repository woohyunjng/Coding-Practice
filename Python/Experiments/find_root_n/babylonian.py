def find_root(n, tries=10):
    under_one = 1
    if n > 1:
        under_one = n
        n = 1 / n

    root_n = n
    for i in range(tries):
        root_n = (root_n + n / root_n) / 2

    return under_one * root_n
