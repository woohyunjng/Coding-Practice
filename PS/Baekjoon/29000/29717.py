T = int(input())
for i in range(T):
    N = int(input())
    res = (N + 1) * N // 2

    level = int(res**0.5) - 1
    while (level + 1) * level <= res:
        level += 1
    print(level)
