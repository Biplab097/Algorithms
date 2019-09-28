#include<stdio.h>

void create(int []);
void down_adjust(int [],int);

int main(int argc[],char const *argv[])
{
	int n,i,last,temp;
        FILE *r,*w;
        r = fopen(argv[1],"r");
        w = fopen(argv[2],"w");
	//printf("Enter no. of elements:");
	fscanf(r,"%d",&n);
        int heap[n];
	for(i=1;i<=n;i++)
		fscanf(r,"%d",&heap[i]);

	//create a heap
	heap[0]=n;
	create(heap);

	//sorting
	while(heap[0] > 1)
	{
		//swap heap[1] and heap[last]
		last=heap[0];
		temp=heap[1];
		heap[1]=heap[last];
		heap[last]=temp;
		heap[0]--;
		down_adjust(heap,1);
	}

	//print sorted data
	fprintf(w,"\nArray after sorting:\n");
	for(i=1;i<=n;i++)
		fprintf(w,"%d ",heap[i]);

	return 0;
}

void create(int heap[])
{
	int i,n;
	n=heap[0]; //no. of elements

	for(i=n/2;i>=1;i--)
		down_adjust(heap,i);
}

void down_adjust(int heap[],int i)
{
	int j,temp,n,flag=1;
	n=heap[0];

	while(2*i<=n && flag==1)
	{
		j=2*i;    //j points to left child
		if(j+1<=n && heap[j+1] > heap[j])
			j=j+1;
		if(heap[i] > heap[j])
			flag=0;
		else
		{
			temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
			i=j;
		}
	}
}