#include <stdio.h>

 int min = 0, count = 0, array[100] = {0}, array1[100] = {0};

void main()
 {  int k, i, j, temp, t, n;
     printf("Digite o tamanho do vetor:");
     scanf("%d", &count);
     printf("Digite os elementos do vetor:");
     for (i = 0; i < count; i++)
     { scanf("%d", &array[i]);
         array1[i] = array[i];
     }
     for (k = 0; k < 3; k++)
     { for (i = 0; i < count; i++)
         { min = array[i] % 10;        
             t = i;
             for (j = i + 1; j < count; j++)
             { if (min > (array[j] % 10))
                 {  min = array[j] % 10;
                     t = j;
    }
             }
             temp = array1[t];
             array1[t] = array1[i];
             array1[i] = temp;
             temp = array[t];
             array[t] = array[i];
             array[i] = temp;
         }
         for (j = 0; j < count; j++)       
             array[j] = array[j] / 10;
     }
     printf("Array ordenado: ");
     for (i = 0; i < count; i++)
         printf("%d ", array1[i]);
 }

