// #include<stdio.h>

int main()
{
    int ara[5], i, j, k;

    j = 13;
    k = j-12;
    println(k);
    // printf("%d\n",k);
    ara[j - 12] = 10;
    i = 5;
    k = j*2 - 5*i;
    println(k);
    //printf("%d\n",k);
    i = ara[j * 2 - 5 * i];
    println(i);
    //printf("%d\n",i);
}