S = input()
for i in S:
    print(i.lower() if i.isupper() else i.upper(), end="")
