"""
def is_palindrome(s):
        i = 0
        j = len(s) - 1
        while i <= j:
            if s[i] != s[j]:
                return 0
            else:
                i+=1
                j-=1
        return 1

def get_next_palindrome(s):
    l = len(s)

    i = 0
    j = l - 1 
    m = (l -1)/2
    mid = str(int(min(s[m], s[m+1])) + 1)
    while s
        if s[i] < s[j]:
           s[j-1] = str(int(s[j-1]) + 1)
        s[j] = s[i]
        i+=1
        j-=1
    if (l % 2) == 0:
        s[m]    = mid 
        s[m+1]  = mid
    
    s1 = "".join(s[0:m])
    #s2 = "".join(s[m+2:])
    if l%2 == 0:
        return s1+"".join(s[m:m+2])+s1[::-1]
    else:
        return s1+"".join(s[m:m+1])+s1[::-1]
    #print s1,s2
    #return s
    
    return s
"""
def get_next_palindrome(s):
    l = len(s)

    if l == 1:
        return str(int(s[0]) + 1)
    m = (l-1)/2
    m1 = str(int(s[m]) + 1)
    if l%2:
        p = s[0:m+1] + s[m-1::-1]
        if int("".join(p)) <= int("".join(s)):
            p[m] = m1
    else:
        #print s[0:m+1]
        #print s[m::-1]
        p = s[0:m+1] + s[m::-1]
        #if int(p) <= int(s):
        #print p
        #print s
        if int("".join(p)) <= int("".join(s)):
            p[m]   = m1 
            p[m+1] = m1 

    return p

t = int(raw_input())
for i in range(t):
    inp = raw_input()
    #n = inp
    #special processing of 9's
    if (len(inp) != len(str(int(inp) + 1))):
        inp = str(int(inp) + 1)
    res = "".join(get_next_palindrome(list(inp)))

    #res = get_next_palindrome(inp)

    print int(res)
