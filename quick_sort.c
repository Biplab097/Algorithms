#include <stdio.h>
void quick_sort(int[],int,int);
int partition(int[],int,int);
 
int main(int argc[],char const *argv[])
{
	int n,i;
    FILE *r;
    r = fopen(argv[1],"r");
	fscanf(r,"%d",&n);
    int a[n+1];	
	for(i=0;i<n;i++)
		fscanf(r,"%d",&a[i]);
		
	quick_sort(a,0,n-1);
	printf("\nArray after sorting:");
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	return 0;		
}
 
void quick_sort(int a[],int first,int last)
{
	int j;
	if(first<last)
	{
		j=partition(a,first,last);
		quick_sort(a,first,j-1);
		quick_sort(a,j+1,last);
	}
}
 
int partition(int a[],int first,int last)
{
	int pivot,i,j,temp;
	pivot=a[first];
	i=first;
	j=last+1;
	
	do
	{
		do
			i++;
			
		while(a[i]<pivot&&i<=last);
		
		do
			j--;
		while(pivot<a[j]);
		
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);
	
	a[first]=a[j];
	a[j]=pivot;
	
	return(j);
}