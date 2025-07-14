int countTrailingZeroes(int n)
{
    int count = 0;
    for (int i = 5; n / i > 0; i *= 5)
    {
        count += n / i;
    }
    return count;
}

// REVIEW -  dry run
// Input: n = 11
// 11 /5 = 2 > 0  , count =2
// 11 /25  not > 0 ,  so end loop