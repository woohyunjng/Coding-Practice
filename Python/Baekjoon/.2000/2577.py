from collections import Counter

A = int(input())
B = int(input())
C = int(input())
N = [int(i) for i in str(A * B * C)]

num_list = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0}
num_list.update(Counter(N))

for i in num_list.values():
    print(i)
