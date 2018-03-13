import sys

n = int(input().strip())
lbd = list(map(int, input().strip().split(' ')))
m = int(input().strip(' '))
s = list(map(int, input().strip().split(' ')))
k = len(lbd)-1
rank = dict()
for i in range(n):
    if(i==0):
        rank[lbd[i]] = 1
    elif(lbd[i] != lbd[i-1]):
        rank[lbd[i]] = rank.get(lbd[i-1]) + 1
print(rank)
for i in range(m):
    if(s[i]>= lbd[0]):
        print('1')
        continue
    for j in range(k, -1, -1):
        r = rank.get(lbd[j])
       # print(s[i], lbd[j], r)
        if(lbd[j] > s[i]):
            print(r+1)
            k = j
            break
        elif(lbd[j]==s[i]):
            print(r)
            k = j
            break
