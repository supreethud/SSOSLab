#include <stdio.h>
#include <stdlib.h>
int main()  {
    int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10],finish[10],p, r, i, j,count;
    count = 0;
    printf("Enter the no of processes : ");
    scanf("%d", &p);
    for(i = 0; i< p; i++)
        completed[i] = 0;
    printf("\nEnter the no of resources : ");
    scanf("%d", &r);
    printf("\nEnter the Max Matrix for each process : ");
    for(i = 0; i < p; i++)  {
    printf("\nFor process %d : ", i + 1);
    for(j = 0; j < r; j++)
        scanf("%d", &Max[i][j]);
    }
    printf("\nEnter the allocation for each process : ");
    for(i = 0; i < p; i++)  {
        printf("\nFor process %d : ",i + 1);
    for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    }
    printf("\nEnter the Available Resources : ");
    for(i = 0; i < r; i++)
        scanf("%d", &avail[i]);
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            need[i][j] = Max[i][j] - alloc[i][j];
    printf("Need Matrix :\n");
    for(i = 0; i < p; i++){
        for(j = 0; j < r; j++)
            printf(" %d\t",need[i][j]);
        printf("\n");
    }
    int cond=1,last=0;
    while(cond){
        last=0;
        for(i=0;i<p;i++){
            if(finish[i]==0){
                for(j=0;j<r;j++){
                    if(avail[j]<need[i][j]) break;
                }
                if(j==r){
                    last=1;
                    printf("Available Resources after Process %d is\t",i);
                    for(j=0;j<r;j++){
                        avail[j]+=alloc[i][j];
                        printf(" %d\t",avail[j]);
                    }
                    printf("\n");
                    finish[i]=1;
                    for(j=0;j<p;j++){
                        if(finish[j]==0)break;
                    }
                    if(j==p){
                        cond=0;
                        break;
                    }
                }
            }
        }
        if(!last){
            printf("Not safe\n");
            return 0;
        }
    }
    printf("Safe no deadlock\n");
    return 0;
}
