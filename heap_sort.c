#include<stdio.h>

void create(int[]);
void down_adjust(int[],int);

int main(int argc[],char const *argv[])
{
    FILE *r,*w;
    r = fopen(argv[1],"r");
    w = fopen(argv[2],"w");
    int size,last,i,temp;
    fscanf(r,"%d",&size);
    int heap[size+1];
    for(int i=1;i<=size;i++)
    {
        fscanf(r,"%d",&heap[i]);
    } 
    heap[0]=size;
    create(heap);

    //sorting
    while(heap[0]>1)
    {
        last = heap[0];  
        temp=heap[1];
        heap[1]=heap[last];
        heap[last]=temp;
        heap[0]--;
        down_adjust(heap,1);    
    }
    fprintf(w,"Array after sorting\n");
    for(int i=1;i<=size;i++){
        fprintf(w,"%d ",&heap[i]);
    }
    return 0;
}
void create(int heap[])
{
    int i,n;
    n=heap[0];
    for(int i=n/2;i>0;i--)
    {
        down_adjust(heap,i);
    }
}
void down_adjust(int heap[],int i)
{
    int j,temp,n,flag=1;
    n=heap[0];
    while(2*i<=n && flag==1)
    {
        j=2*i;
        if(j+1<=n && heap[j+1]>heap[j])
            j=j+1;
        else if(heap[i]>heap[j])
            flag=0;
        else{
            temp=heap[j];
            heap[i]=temp;
            heap[j]=heap[i];
            i=j;
        }        
    }
}