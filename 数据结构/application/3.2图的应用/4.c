#include <stdio.h>
/*
已知某图的邻接矩阵为A, 若从顶点i到顶点j有边, 则A[i, j]=1, 否则A[i, j]=0。
试编写一算法求矩阵A的传递包C：使得若从顶点i到顶点j有一条或多条路径,
则C[i,j]=1, 否则C[i, j]=0。
*/
void Change(int C[100][100], int n){
    int k, i, j;
    for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    C[i][j]=(C[i][j]||(C[i][k]&&C[k][j]))?1:0;
}

int main()
{
    int s[100][100]={0};
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &s[i][j]);
    Change(s, n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!j) printf("%d", s[i][j]);
            else printf(" %d", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}
