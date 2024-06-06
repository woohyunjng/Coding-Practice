N = int(input())
S = []

for i in range(N):
    S.append(input())

i, j = 0, N - 1
res = ""

while i <= j:
    if S[i] < S[j]:
        res += S[i]
        i += 1
    elif S[i] > S[j]:
        res += S[j]
        j -= 1
    else:
        res += S[i]
        x, y = i, j

        while x <= y:
            if S[x] < S[y]:
                i += 1
                break
            elif S[x] > S[y]:
                j -= 1
                break
            else:
                x += 1
                y -= 1
        else:
            i += 1

ln = len(res)
while ln >= 81:
    print(res[:80])
    res = res[80:]
    ln = len(res)
print(res)
