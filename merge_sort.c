#include<stdio.h>
void merge_sort(int[],int,int);
void merge(int[],int,int,int);


int main(int argc[],char const *argv[])
{
    FILE *r;
    int n;
    r = fopen(argv[1],"r");
    fscanf(r,"%d",&n);
    int arr[n+1];
    for(int i=0;i<n;i++)
        fscanf(r,"%d",&arr[i]);
    merge_sort(arr,0,n-1);  
    printf("Sorted array is: \n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
      
    return 0;
}
void merge_sort(int arr[],int l,int h)
{
   if (l < h) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(h-l)/2; 
        // Sort first and second halves 
        merge_sort(arr, l, m); 
        merge_sort(arr, m+1, h); 
  
        merge(arr, l, m, h); 
    } 
}
void merge(int arr[],int l,int m,int h)
{
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  h - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 

}