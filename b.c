#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int need[100][100], avai[100];
struct process{
    int pc;
    bool status;
} pno[100];
bool check(int i, int m){
    int j;
    for (j = 0; j < m; j++)
    {
        if (need[i][j] > avai[j])
            return 0;
    }
    return 1;
}
void disp(int n){
    int i;
    printf("SYSTEM IN SAFE STATE\nSAFE SEQUENCE = ");
    for (i = 0; i < n; i++)
    {
        printf("P%d ", pno[i].pc);
    }
    printf("\n");
}
void banker(int alloc[][100], int max[][100], int n, int m){
    int i, j, ck = 0, ic = 0, flag = 0;
    bool checker = 0;
    printf("NEED MATRIX :\n");
    for (i = 0; i < n; i++)    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
            pno[i].status = 0;
        }
        printf("\n");
    }
    while (ck < n)    {
        if (check(ic, m) == 1 && pno[ic].status == 0)        {
            int ac = 0;
            pno[ck].pc = ic;
            ck++;
            pno[ic].status = 1;
            checker = 1;
            for (ac = 0; ac < m; ac++)            {
                avai[ac] = avai[ac] + alloc[ic][ac];
            }
        }
        if (ic == n - 1 && checker == 0)        {
            printf("SYSTEM UNSAFE\n");
            flag = 1;
            ck = n;
        }
        if (ic == n - 1)        {
            ic = -1;
            checker = 0;
        }
        ic++;
    }
    if (flag == 0)
        disp(n);
}

int main(){
    int alloc[100][100], max[100][100], n, m, i, j;
    printf("ENTER THE NO PROCESS AND RESOURCES : ");
    scanf("%d%d", &n, &m);
    printf("\nENTER ALLOCATION MATRIX : \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    printf("ENTER MAX MATRIX : \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    printf("ENTER AVAILABLE :\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avai[i]);
    banker(alloc, max, n, m);
    return 0;
}