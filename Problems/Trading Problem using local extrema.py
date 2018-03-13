#!/bin/python3

import sys

def traderProfit(k, n, A):
    # Complete this function
    t = 0
    i = 0
    profit = 0
    while(t<k and i<n-1):
        while(i<n-1 and A[i+1] <= A[i]):
            i+=1
        key = A[i]
        if(t == k-1):
            if(i!=n-1):
                A[0:i] = []
                m = max(A)
                profit += m-key
            break
        if(i==n-1):
            return 0
        i+=1
        while(i<n and A[i] >= A[i-1]):
            i+=1
        profit += (A[i-1] - key)
        t+=1       
    return profit

if __name__ == "__main__":
    q = int(input().strip())
    for a0 in range(q):
        k = int(input().strip())
        n = int(input().strip())
        arr = list(map(int, input().strip().split(' ')))
        result = traderProfit(k, n, arr)
        print(result)
