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
"""
def get_next_palindrome(s):
    l = len(s)

    i = 0
    j = l - 1 
    m = (l -1)/2
    while i < j:
        if s[i] < s[j]:
           s[m] = str(int(s[m]) + 1)
           break;
        i+=1
        j-=1
    """
    i = 0
    j = l - 1

    while i < j:
        s[j] = s[i]
        i+=1
        j-=1
    """
    s1 = "".join(s[0:m])
    #s2 = "".join(s[m+2:])
    if l%2 == 0:
        return s1+"".join(s[m:m+2])+s1[::-1]
    else:
        return s1+"".join(s[m:m+1])+s1[::-1]
    #print s1,s2
    #return s


t = int(raw_input())
for i in range(t):
    inp = int(raw_input())
    n = inp
    n += 1
    #res = "".join(get_next_palindrome(list(str(n))))
    res = get_next_palindrome(list(str(n)))
    print int(res)

    #print int(res)
