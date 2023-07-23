N = int(input())
b = list(map(int, input().split()))
mx = -1

for i in range(N):
    res = 0
    for j in range(N):
        if i == j:
            continue
        
        check = True
        if i > j:
            for k in range(j + 1, i):
                if (b[i] - b[k]) / (i - k) <= (b[i] - b[j]) / (i - j):
                    check = False
                    break
        else:
            for k in range(i + 1, j):
                if (b[k] - b[i]) / (k - i) >= (b[j] - b[i]) / (j - i):
                    check = False
                    break

        if check:
            res += 1

    mx = max(mx, res)

print(mx)