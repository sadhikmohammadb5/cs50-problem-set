#include<stdio.h>
#include<cs50.h>
int main(void)
{
    long dollar=1;
    while(true)
    {
    char c=get_char("here $%li,double and give it to the other person ?",dollar);
    if(c=='y')
        {
             dollar*=2;
        }
    else
        {
        break;
        }
    }
    printf("here$%li\n",dollar);

}
