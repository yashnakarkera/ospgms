#include<stdio.h>
#include<string.h>

int main()

    {
        int nf=0,i=0,j=0,ch=1,count=0;
        char mdname[10],fname[10][10],name[10];
        printf("\nEnter the directory name:");
        scanf("%s",mdname);
        printf("\nEnter the number of files:");
        scanf("%d",&nf);
        while(ch==1 && count <nf)
        {
            printf("\nEnter file name to be created:");
            scanf("%s",name);
            for(i=0;i<nf;i++)
            {
                if(!strcmp(name,fname[i])){
                        printf("\nThere is already %s\n",name);
                        break;
                }
        
            }
            if(i==nf)
            {
                strcpy(fname[j++],name);
                count++;
                printf("%d", count);
                printf("\nDo you want to enter another file(yes - 1 or no - 0):");
                scanf("%d",&ch);
                
            }
            
        }
        printf("\n\nDirectory name is:%s\n",mdname);
        printf("\nFiles names are:");
        for(i=0;i<j;i++)
        printf("\n%s",fname[i]);
        return 0;

    }

