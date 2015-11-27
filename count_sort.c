
#include<stdio.h>
 
void counting_sort(int a[],int n,int max)
{
     int count[50]={0},i,j;
     
     for(i=0;i<n;++i)
      count[a[i]]=count[a[i]]+1;
      
     printf("Array ordenado: ");
     
     for(i=0;i<=max;++i)
      for(j=1;j<=count[i];++j)
       printf("%d ",i);
}
 
int main()
{
    int a[50],n,i,max=0;
    printf("Digite o tamanho do array:");
    scanf("%d",&n);
    printf("Digite os elementos do array:");
                  
    for(i=0;i<n;++i)
    {
     scanf("%d",&a[i]);
     if(a[i]>max)
      max=a[i];
    }
     
    counting_sort(a,n,max);
    return 0;
}