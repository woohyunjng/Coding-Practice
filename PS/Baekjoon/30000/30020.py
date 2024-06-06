A, B = map(int, input().split())
K = A - B

if K <= 0 or K > B:
    print("NO")
else:
    print("YES")
    print(K)
    for i in range(K - 1):
        print("aba")
        A -= 2
        B -= 1
    print("ab" * B + "a")
