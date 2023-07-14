from collections import defaultdict

N = int(input())
sorted_arr = defaultdict(list)

for i in range(N):
    S = input()
    sorted_arr[len(S)].append(S)

sorted_arr = dict(map(lambda i: (i[0], list(set(i[1]))), sorted(sorted_arr.items(), key=lambda i: i[0])))
for i in sorted_arr.values():
    for j in sorted(i):
        print(j)
