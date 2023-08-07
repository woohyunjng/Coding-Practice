from collections import defaultdict

a = defaultdict(int)
for i in range(5):
    a[int(input())] += 1

for i in a.keys():
    if a[i] % 2:
        print(i)
        break
