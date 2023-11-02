n = int(input())

factorial = 1
for i in range(n):
    factorial *= (n-i)
    
count = 0
t = str(factorial)
for idx in range(len(str(factorial))-1, -1, -1):
    if t[idx] == '0':
        count += 1
    else:
        break
print(count)