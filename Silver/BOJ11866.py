n, k = map (int,input().split())

anslist = []
for idx in range(1,n+1):
    anslist.append(idx)

idx = k-1
aa = []
while len(anslist)!=1:
    while idx >= len(anslist):
        idx -= len(anslist)
    aa.append(anslist.pop(idx))    
    idx += k-1
aa.append(anslist.pop())
ans = "<"
for j in range(len(aa)):
    if j == len(aa)-1:
        ans += str(aa[j])+">"
    else:
        ans += str(aa[j])+", "
print(ans)