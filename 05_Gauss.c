#include<stdio.h>
void main(){
int n,i,j,k,a[30][30],b=1;
int nghiem[30],nghiemGia;
int x=1;
printf("HPT co may an :\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    for(j=1;j<=n+1;j++)
    {
        printf("Nhap phan tu a[%d][%d]=",i,j);
        scanf("%d",&a[i][j]);
    }
}
printf("He phuong trinh ban nhap la:\n");
for(i=1;i<=n;i++)
{
    for(j=1;j<=n+1;j++)
    {
        if(j>1&&j<=n)
        {
            if(a[i][j]>0)
                printf("+%dX%d",a[i][j],j);
            else
                printf("%dX%d",a[i][j],j);

        }
        else if(j<=1||j>n+1)
                if(a[i][j]<0)
                    printf("%dX%d",a[i][j],j);
                else
                    printf(" %dX%d",a[i][j],j);
             else
                printf("=%d",a[i][j]);

    }
    printf("\n");
}
while(b<n)
{
    for(i=b;i<=n;i++)
    {
        if(a[i][b]!=0)
        {
            for(j=b;j<=n+1;j++)
            {
                a[i][j]=a[i][j]/a[i][b];
            }
        }
        else
        {
            for(j=b;j<=n+1;j++)
            {
                for(k=n;k>=b;k--)
                    {
                        if(a[k][j]!=0)
                            a[i][j]=a[k][j]-a[i][j];
                            break;
                    }
            }
        }
    }
for(i=b+1;i<=n;i++)
{
    for(j=b;j<=n+1;j++)
    {
        a[i][j]=a[i][j]-a[b][j];
    }
}
b++;
}
for(i=n;i>=1;i--)
{
    if(i=n)
        nghiem[i]=a[i][n+1]/a[i][i];
    else
        {
            for(j=1;j<=x;j++)
            {
                nghiemGia+=nghiem[i+j]*a[i][i+j];
            }
            nghiem[i]=a[i][n+1]-nghiemGia;
            x++;
        }
}
for(i=1;i<=n;i++)
{
    printf("Nghiem cua hpt la:\n",i,nghiem[i]);
    printf("X[%d]=%d\n",i,nghiem[i]);
}
}
