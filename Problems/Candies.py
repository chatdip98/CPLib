#!/bin/python3

import sys

def f(dp, i):
    if(dp[i]==1):
        return 1
    dp[i] = 1 + f(dp, i+1)
    return dp[i]

def candies(n, arr):
    # Complete this function
    dp = [0]*n
    if(arr[0]<arr[1]):
        dp[0] = 1
    for i in range(1, n):
        if((i!=n-1 and arr[i]<=arr[i-1] and arr[i]<=arr[i+1]) or (i==n-1 and arr[i]<=arr[i-1])):
            dp[i]=1
    i = 0
    while(i<n):
        if(dp[i]!=1):
            if(arr[i]>arr[i-1] and i!=0):
                dp[i]=dp[i-1]+1
                i+=1
            elif(arr[i]<arr[i-1] or i==0):
                dp[i] = f(dp, i)
                i+=dp[i]
        else:
            i+=1
    return sum(dp)

if __name__ == "__main__":
    n = int(input().strip())
    arr = []
    arr_i = 0
    for arr_i in range(n):
        arr_t = int(input().strip())
        arr.append(arr_t)
    result = candies(n, arr)
    print(result)
