# 100 (0:05)

T = int(input())
for i in range(T):
    N = int(input())
    for j in range(N):
        for k in range(2):
            for l in range(N):
                print("##" if (l + j) % 2 == 0 else "..", end="")
            print()
