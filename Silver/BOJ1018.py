whlist = list(map(int,input().split()))
width = whlist[1]
height = whlist[0]
bwaps = []
for _ in range(0,height):
    bwaps.append(input())
BWWB = ['BWBWBWBW', 'WBWBWBWB']
Answerlist = []

for h in range(0,height-7):
    for w in range(0,width-7):
        oddoreven = 0
        ans = 0
        for idx in range(0,8):
            for j in range(0,8):
                if bwaps[h+idx][w+j] == BWWB[oddoreven][j]:
                    ans+=1
            oddoreven = (oddoreven+1)%2
        Answerlist.append(ans)
        oddoreven = 1
        ans = 0 
        for idx in range(0,8):
            for j in range(0,8):
                if bwaps[h+idx][w+j] == BWWB[oddoreven][j]:
                    ans+=1
            oddoreven = (oddoreven+1)%2
        Answerlist.append(ans)

print(min(Answerlist))