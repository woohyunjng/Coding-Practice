N, S = map(int, input().split())
arr = list(map(int, input().split()))

i, j = 0, 0
mn, sm = 1e9, 0

while j <= N:
    if sm >= S:
        mn = min(mn, j - i)

        sm -= arr[i]
        i += 1
    else:
        if j == N:
            break

        sm += arr[j]
        j += 1

print(mn if mn != 1e9 else 0)
