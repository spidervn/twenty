#!/usr/bin/python

def bino(n,k):
    if n==0 and k==0:
        return 1
    elif n<k:
        return 0
    elif k<0:
        return 0
    else:
        val=1.0
        for i in range(k):
            val=val*(n-i)
            val=val/(i+1)
        return val

def test_even():
    n = 10
    k = 2

    mysum = 0
    for i in range(2*n-k):
        j = i + k+1

        mysum = mysum + bino(j, k) * bino(n, j-n)      
        print "bino({0},{1})*bino({2},{3})={4}*{5}={6}".format(j,k,n,j-n,bino(j,k),bino(n,j-n),bino(j,k)*bino(n,j-n))

    return mysum

print bino(3,2)
print test_even()


