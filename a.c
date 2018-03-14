/*
print pattern



*/

#include<stdio.h>

void main()
{
    int n,d=1,temp;
    int z;
    scanf("%d",&n);

    for(int i=1;i<=n+1;i++)
    {
        if(i%2!=0)
        {
            if(d==1){
                printf("%d\n",d);
                d++;
                }
            else
            {
                temp=i+d;
                for(int j=d+1;j<=temp;j++)
                {
                        d=j;
                        if(j<temp)
                        printf("%d*",j);
                        else
                            printf("%d",j);
                }
                    printf("\n");
                    d++;
                    z=i;
            }
        }
        else
        {
            temp=d+z;

            for(int j=temp;j>=d;j--)
                {
                        if(j>d)
                        printf("%d*",j);
                        else
                            printf("%d",j);
                }
                    printf("\n");
            d=temp;
        }
        z=i;
    }

}
