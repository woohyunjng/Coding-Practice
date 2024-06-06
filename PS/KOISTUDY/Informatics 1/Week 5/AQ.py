N = int(input())
mx, mx_index = -1, -1
mn, mn_index = 10000000, -1

S = list(map(int, input().split()))
for i in range(N):
    if S[i] > mx:
        mx = S[i]
        mx_index = i
    if S[i] < mn:
        mn = S[i]
        mn_index = i

print(mx_index + 1, ":", mx)
print(mn_index + 1, ":", mn)
