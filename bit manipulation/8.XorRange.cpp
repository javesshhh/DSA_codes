// https://www.youtube.com/watch?v=WqGb7159h7Q&ab_channel=takeUforward
// https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-xor-of-numbers-from-l-to-r

int fun1(int n)
{
    if (n % 4 == 1)
        return 1;

    else if (n % 4 == 2)
        return n + 1;

    else if (n % 4 == 3)
        return 0;

    else
        return n;
}
int findXOR(int l, int r)
{
    // complete the function here
    return fun1(l - 1) ^ fun1(r);
}