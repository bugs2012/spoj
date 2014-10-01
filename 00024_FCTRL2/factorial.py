def fact(n):
    if n == 1 or n == 0:
        return 1
    return (n * fact(n-1))

t = int(raw_input()) 
for i in range(t):

    n = int(raw_input())
    print fact(n)


