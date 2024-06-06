from string import ascii_lowercase

S = input()
for i in ascii_lowercase:
    print(S.find(i), end=" ")
