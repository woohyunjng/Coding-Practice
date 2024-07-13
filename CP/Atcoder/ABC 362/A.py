R, G, B = map(int, input().split())
C = input()

if C == "Blue":
    print(min(R, G))
elif C == "Green":
    print(min(R, B))
else:
    print(min(G, B))
