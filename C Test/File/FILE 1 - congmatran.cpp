#include <stdio.h>
#include <conio.h>
int kq[100][100];
int nhapmatran(int a[100][100],int m,int n)
{   
    for(int i=0;i<m;++i)
    {
            for(int j=0;j<n;++j)
            {       printf("\na[%d][%d]= ",i+1,j+1);
                    scanf("%d",&a[i][j]);
            }
    }   
}
int congmatran(int a[100][100],int b[100][100],int m,int n)
{
    for(int i=0;i<m;++i)
    {
            for(int j=0;j<n;++j)
            {
                    kq[i][j]=a[i][j]+b[i][j];
            }
    }
}
int main()
{
    int a[100][100],b[100][100];
    int m,n,x,y;
    FILE *f;
    do
    {          
               printf("nhap hang cot ma tran 1\n");
               scanf("%d %d",&m,&n);
               printf("nhap hang cot ma tran 2\n");
               scanf("%d %d",&x,&y);
               if(n!=x||m!=y)
               printf("2 ma tran nay khong nhan duoc,moi nhap lai\n");
    }
    while(n!=x||m!=y);
    printf("nhap du lieu ma tran 1\n");
    nhapmatran(a,m,n);
    printf("nhap du lieu ma tran 2\n");
    nhapmatran(b,x,y);
    congmatran(a,b,m,n);
    f=fopen("CONG_MT.C","w");
    for(int i=0;i<m;++i)
    {
            for(int j=0;j<n;++j)
                    fprintf(f,"%d ",a[i][j]);
            fprintf(f,"\t");
            for(int j=0;j<n;++j)
                    fprintf(f,"%d ",b[i][j]);
            fprintf(f,"\t");
            for(int j=0;j<n;++j)
                    fprintf(f,"%d ",kq[i][j]);
            fprintf(f,"\n");
    }
    fclose(f);
    getch();   
}
