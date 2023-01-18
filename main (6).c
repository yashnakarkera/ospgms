#include<stdio.h>
int main()
{
        int i,j,n,a[50],frame[10],no,k,avail,count=0;
        printf("\n ENTER THE NUMBER OF PAGES:\n");
        scanf("%d",&n);
        printf("\n ENTER THE PAGE NUMBER :\n");
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        printf("\n ENTER THE NUMBER OF FRAMES :");
        scanf("%d",&no);
        for(i=0;i<no;i++)
            frame[i]= -1;
        j=0;
        printf("\tref string\t page frames\n");
        for(i=1;i<=n;i++)
        {
                printf("%d\t\t",a[i]);
                avail=0;
                for(k=0;k<no;k++)
                if(frame[k]==a[i])
                     avail=1;
                if (avail==0)
                {
                        frame[j]=a[i];
                        j=(j+1)%no;
                        count++;
                        for(k=0;k<no;k++)
                        printf("%d\t",frame[k]);
                }
                printf("\n");
      }
    printf("Page Fault Is %d",count);
    return 0; 
}


OUTPUT


 ENTER THE NUMBER OF PAGES:
7

 ENTER THE PAGE NUMBER :
1       2       4       1       5       3       2        

 ENTER THE NUMBER OF FRAMES :1
        ref string       page frames
1               1
2               2
4               4
1               1
5               5
3               3
2               2
Page Fault Is 7
