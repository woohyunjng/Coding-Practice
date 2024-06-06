N, M = map(int, input().split())
arr = list(map(int, input().split()[1:]))

res = 0
truth = [False for i in range(N + 1)]
parties = []

for i in arr:
    truth[i] = True

for i in range(M):
    parties.append(list(map(int, input().split()[1:])))

for i in range(M):
    for j in parties:
        for k in j:
            if truth[k]:
                break
        else:
            continue

        for k in j:
            truth[k] = True

for i in parties:
    for j in i:
        if truth[j]:
            break
    else:
        res += 1

print(res)
