from collections import defaultdict

N = int(input())
arr, man = [], defaultdict(int)
mx, mx_num = -1, []

for i in range(N):
    j = int(input())
    arr.append(j)
    man[str(j)] += 1

    if mx < man[str(j)]:
        mx = man[str(j)]
        mx_num = [j]
    elif mx == man[str(j)]:
        mx_num.append(j)

arr = list(sorted(arr))
mx_num = list(sorted(mx_num))

print(round(sum(arr) / N + 0.0000001))
print(arr[N // 2])
if len(mx_num) > 1:
    print(mx_num[1])
else:
    print(mx_num[0])
print(max(arr) - min(arr))
