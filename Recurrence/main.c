#include <stdio.h>
#include <stdlib.h>

int func1(int i)
{
    if(i > 100)
    {
        return 0;
    }
    int  total = i + func1(i+1);
    printf("total = %d\n", total);
    return total;
}

int func2(int i, int total)
{
    if(i > 100)
    {
        return total;
    }
    total = total + i;
    printf("total = %d\n", total);
    return func2(i+1, total);
}

int main()
{
    printf("total = %d\n", func1(1));
//    printf("total = %d\n", func2(1, 0));
}
