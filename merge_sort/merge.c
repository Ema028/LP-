#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int size)
{
    int right, left;
    
    if(size % 2 == 0)
    {
        right = size / 2;
        left = right;
    }
    else
    {
        left = (size + 1) / 2;
        right = size - left;
    }
    
    
    int* L = (int*) malloc(left * sizeof(int));
    int* R = (int*) malloc(right * sizeof(int));

    // copiar dados para os arrays temporários e ir juntando metades ordenadas
    for (int i = 0; i < left; i++)
    {
        L[i] = arr[i];
    }
        
    for (int j = 0; j < right; j++)
    {
        R[j] = arr[left + j];
    }
        
    if(right > 1)
    {
        sort(R, right);
    }
    if(left > 1)
    {
        sort(L, left);
    }

    int i = 0, j = 0, k = 0;
    while (i < left && j < right) 
    {
        k++;
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }

    free(L);
    free(R);
}