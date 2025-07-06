bool isPowerOf2(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

bool isPowerOf3(int n)
{
    if (n <= 0)
        return false;
    while (n % 3 == 0)
        n /= 3;
    return n == 1;
}

bool isPowerOf4(int n)
{
    return isPowerOf2(n) && (n % 3 == 1);
}
