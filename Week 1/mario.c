#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int n,i,j,k;
    do
    {
    n=get_int("height: \n");
    }
    while(n<1 || n>8);
    {
        for(i=0;i<n;i++)
        {
            for(j=n;j>(i+1);j--)
            {
                printf(" ");
            }
            for(k=0;k<(i+1);k++)
            {
                printf("#");
            }
            printf("  ");
                for(j=0;j<(i+1);j++)
                {
                    printf("#");
                }
                printf("\n");
        }
    }
}

