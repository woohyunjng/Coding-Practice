from collections import deque

N = int(input())
res = []

for i in [2, 3, 5, 7]:
    st = deque([(i, 1)])
    while len(st):
        A, B = st.pop()
        if B == N:
            res.append(A)
            continue

        for j in range(1, 10, 2):
            K = A * 10 + j

            for k in range(2, int(K**0.5) + 1):
                if not K % k:
                    break
            else:
                st.append(K, B + 1)

for i in sorted(res):
    print(i)
