from re import sub

N = int(input())
res = 0

for i in range(N):
    S = input()
    arr, bf = [S[0]], S[0]

    for i in S[1:]:
        if bf == i:
            continue
        if i in arr:
            break
        arr.append(i)
        bf = i
    else:
        res += 1

print(res)
