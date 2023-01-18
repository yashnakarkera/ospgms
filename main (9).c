#include <stdio.h> 
#include <stdlib.h> 

int main() {
    // variables 
    int max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
    int np, nr;
    int process = 0, count = 0;
    
    // inputs 
    printf("Enter the number of process: ");
    scanf("%d", &np);
    for (int i = 0; i < np; i++)
        completed[i] = 0;
    printf("Enter the number of resources: ");
    scanf("%d", &nr);
    printf("Enter the max matrix for each process \n");
    for (int i = 0; i < np; i++) {
        printf("Process %d: ", i+1);
        for (int j = 0; j < nr; j++)
            scanf("%d", &max[i][j]);
    }
    printf("Enter the allocation for each process \n");
    for (int i = 0; i < np; i++) {
        printf("Process %d: ", i+1);
        for (int j = 0; j < nr; j++)
            scanf("%d", &alloc[i][j]);
    }
    printf("Enter the available resourses: ");
    for (int i = 0; i < nr; i++){
        scanf("%d", &avail[i]);
    }
    
    // print matrix
    printf("Max matrix \t allocation matrix\n");
    for (int i = 0; i < np; i++){
        for (int j = 0; j < nr; j++){
            printf("%d ", max[i][j]);
        } printf("\t\t");
        for (int j = 0; j < nr; j++){
            printf("%d ", alloc[i][j]);
        } printf("\t\n");
    }
    
    // computing
    for (int i = 0; i < np; i++)
        for (int j = 0; j < nr; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    
    while ((count < np) && (process != -1)) {
        process = -1;
        for (int i = 0; i < np; i++) {
            if (completed[i] == 0){
                process = i;
                for (int j = 0; j < nr; j++) {
                    if (avail[j] < need[i][j]) {
                        process = -1;
                        break;
                    }
                }
            }
            if (process != -1)
                break;
        }
        if (process != -1) {
            printf("process %d runs to completion!\n", process + 1);
            safeSequence[count] = process+1;
            count++;
            for (int j = 0; j < nr; j++) {
                avail[j] += alloc[process][j];
                alloc[process][j] = 0;
                max[process][j] = 0;
            }
            completed[process] = 1;
        }
    }
    
    // result
    if (count == np){
        printf("the system is in safe state\n");
        printf("safe sequence: <");
        for (int i = 0; i < np; i++)
            printf("%d ", safeSequence[i]);
        printf(">\n");
    } else {
        printf("the system is in unsafe state\n");
    }
    
    return 0;
}


OUTPUT

Enter the number of process: 3
Enter the number of resources: 2
Enter the max matrix for each process 
Process 1: 
1  2
Process 2: 3    4
Process 3: 1    4
Enter the allocation for each process 
Process 1:      3       4
Process 2: 1    3
Process 3: 1    6
Enter the available resourses:  1       2       7
Max matrix       allocation matrix
1 2             3 4 
3 4             1 3 
1 4             1 6 
process 1 runs to completion!
process 2 runs to completion!
process 3 runs to completion!
the system is in safe state
safe sequence: <1 2 3 >
