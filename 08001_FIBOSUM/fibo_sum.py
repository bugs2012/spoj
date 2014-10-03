#!/usr/bin/python

def fibo(i):
    
    if i == 0:
        return 0
    if i == 1:
        return 1

    return (fibo(i-1) + fibo(i-2))

def fibo_sum(n ,m):
    sum = 0
    for i in range(n, m+1):
        sum += fibo(i)
    return sum

tries = int(raw_input())
for i in range(tries):
    n = int(raw_input())
    m = int(raw_input())
    print fibo_sum(n, m)%1000000007
