D = input()
mp = {"N": "S", "S": "N", "E": "W", "W": "E"}

res = "".join([mp[c] for c in D])
print(res)
