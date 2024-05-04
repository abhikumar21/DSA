#include<stdio.h>

int digit_sum(int n){
  int sum=0;
   while(n!=0)
    {
        sum=sum+n%10;
        n=n/10;
        }
     return sum;
    }
int main()
{
    int n;
    scanf("%d",&n);
   printf("sum is :%d",digit_sum(n));
   return 0;
}