#include<stdio.h>

int bt[10],temp[10],ct[10];
int nop, count, quant, t=0, avg_wt=0, avg_tat=0;

void inputs()
{
    printf("Enter the number of processes\n");
    scanf("%d",&nop);
    count = nop;
    printf("Enter time quantum:\n");
    scanf("%d",&quant);
    for(int i = 0;i<nop;i++)
    {
        printf("Enter burst time of process %d:\n",i+1);
        scanf("%d",&bt[i]);
        temp[i] = bt[i];
        ct[i] = 0;
    }
    
}

int main()
{
    inputs();
    while(count>0){
        for(int i=0;i<nop;i++){
            if(ct[i] == 0){
                if(temp[i] > quant){
                    temp[i] = temp[i] - quant;
                    t = t + quant;
                }
                else{
                    t= t+temp[i];
                    ct[i] = t;
                    count --;
                }
            }
        }
    }
    
    for (int i = 0; i < nop; i++){
        avg_tat += ct[i];
        avg_wt += ct[i] - bt[i];
    }
    avg_tat /= nop;
    avg_wt /= nop;
    printf("Average turn around time = %d\n", avg_tat);
    printf("Average waiting time = %d\n", avg_wt);
    return 0;
}

