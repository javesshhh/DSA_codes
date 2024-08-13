in xor, odd no.  of 1's give 1 and even no. of 1's give zero

right shift operator
x>>k i.e. right shift x by k positions

eg. 13>>1
in binary, 1101>>1 = 0110
1101>>2 = 0011
1101>>4 = 0000
so general formula of x>>k is x/(2^k)

int is 32 bits long and the 31th bit is reserved for storing sign of the value

swap two number a and b
a = a xor b
b= a xor b this gives a
a= a xor b this gives b
thus swap completed without using third variable

// till 1st striver video

to remove the rightmost set bit
101000 => 100000
to do this perform n & (n-1)


check is a number is power of 2
if n & (n-1) ==0 then it is power of 2 otherwise not


assume n=         10101000
then n-1 will be  10100111
that is rightmost set bit will be zero and all bits after that will be set and all bits before will be as it is