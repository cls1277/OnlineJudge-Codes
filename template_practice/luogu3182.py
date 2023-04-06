n = int(input())
f = [0, 0, 1]
for i in range(3, n+1):
    f.append((i-1)*(f[i-1]+f[i-2]))
print(f[n])