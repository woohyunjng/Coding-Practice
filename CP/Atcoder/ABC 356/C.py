from sys import stdin

N, M, K = map(int, stdin.readline().rstrip().split())

true_test, false_test = [], []
for i in range(M):
    line = stdin.readline().rstrip().split()
    if line[-1] == "o":
        true_test.append(list(map(lambda x: int(x) - 1, line[1:-1])))
    else:
        false_test.append(list(map(lambda x: int(x) - 1, line[1:-1])))

res = 0
for mask in range(1 << N):
    check = True
    for test in true_test:
        val = 0
        for i in test:
            if mask & (1 << i):
                val += 1
        if val < K:
            check = False
            break
    for test in false_test:
        val = 0
        for i in test:
            if mask & (1 << i):
                val += 1
        if val >= K:
            check = False
            break

    if check:
        res += 1

print(res)
