#!/usr/bin/py
# Head ends here
def red(s, n, d):
    c_a = s.count('a')
    c_b = s.count('b')
    c_c = s.count('c')
    if(n==1):
        return s
    elif(c_a==n or c_b==n or c_c==n):
        return s
    elif(n==2):
        if(d.get(s)==None):
            return s
        else:
            return d[s]
    x = red(s[0:n-2], n-2, d)
    y = red(s[n-2:n], 2, d)
    t =  x+ y
    m = len(t)
    #print(s, x, y, t, m)
    if(m==1):
        return t
    elif(m==2 and t==s):
        return t
    else:
        if(t==s):
            #print("Equal", end=' ')
            t = red(s[0:m-1], m-1, d)+s[m-1]
            #print(t)
            m = len(t)
            return red(t, m, d)
        else:
            #print("Unequal")
            return red(t, m, d)
    
# Tail starts here
if __name__ == '__main__':
    t = int(input())
    for i in range(0,t):
        a=input()
        n = len(a)
        print(n)
        c_a = a.count('a')
        c_b = a.count('b')
        c_c = a.count('c')
        if(c_a==n or c_b==n or c_c==n):
            print(n)
        else:
            d = {'ab' : 'c', 'ba' : 'c', 'ac' : 'b', 'ca' : 'b', 'bc' : 'a', 'cb' : 'a',}
            s = red(a, n, d)
            m = len(s)
            if(m==1):
                print('1')
            elif(m==2):
                if(d.get(s)==None):
                    print(s, m)
                else:
                    print(d[s], '1')
            elif(m>2):
                if(m%2==0):
                    print('2')
                else:
                    print('1')
