// https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bit-manipulation

static void bitManipulation(int num, int i) {
        int ithBit = (num >> (i-1)) & 1;
        System.out.print(ithBit);
        int setBitNum = (1 << (i-1)) | num;
        System.out.print(" " + setBitNum);
        int clearBitNum = (~(1 << (i-1))) & num;
        System.out.print(" " + clearBitNum);
}
Explaination:

For finding ith bit, we are right shifting the num by (i-1) place so that ith bit is now at the rightmost location. We then do "and" operation of num with 1. (write the bits to see the logic behind it).
For setting the ith bit, we create a value such that it is one only at the ith position. Then we do "or" operation with num. (write bits and see)
For clearing the ith bit, we create same value as before first. Then we do NOT operation to make ith bit alone 0 and rest as 1. Then we do "and" operation. (write bits and see)