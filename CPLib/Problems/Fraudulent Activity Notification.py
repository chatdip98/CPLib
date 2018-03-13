#!/bin/python3

import sys

def median(arr, d):    
    if(d%2==0):
        x = d/2
        i = 0
        while(1):
            if(arr[i]!=0):
                if(arr[i]<x):                    
                     x-=arr[i]                     
                     i+=1
                elif(arr[i]>x):
                    return i
                else:
                    ans = i
                    i+=1
                    while(arr[i]==0):
                        i+=1                    
                    return((ans+i)/2)
                    
            else:
                i+=1
    else:
        x = d//2+1
        i = 0
        while(1):
            if(arr[i]!=0):
                if(arr[i]<x):
                     x-=arr[i]                     
                     i+=1
                elif(arr[i]>=x):
                    return i
            else:
                i+=1
                    

def activityNotifications(ex, n, d):
    # Complete this function
    count = 0
    k = max(ex)
    arr = [0]*(k+1)
    for i in range(0, d):
        arr[ex[i]]+=1
    m = median(arr, d)
    if(ex[d]>=(2*m)):
        count=1
    for i in range(d+1, n):
        arr[ex[i-1]]+=1
        arr[ex[i-1-d]]-=1
        m = median(arr, d)
        #print(arr, m)
        if(ex[i]>=(2*m)):
            count+=1
    return count

if __name__ == "__main__":
    n, d = input().strip().split(' ')
    n, d = [int(n), int(d)]
    expenditure = list(map(int, input().strip().split(' ')))
    result = activityNotifications(expenditure, n, d)
    print(result)
