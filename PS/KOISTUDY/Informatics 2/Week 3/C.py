S = input()
N = len(S)

res = 0

for i in range(0, 1 << (N - 1)):
    before = 0
    for j in range(1, N):
        if i & (1 << (j - 1)) == 0:
            continue
        res += int(S[before:j])
        before = j
    res += int(S[before:])

print(res)
