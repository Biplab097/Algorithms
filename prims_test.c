#include<stdio.h>
#include <limits.h> 
#include <stdbool.h> 

FILE *r,*w;
 
int minKey(int key[], bool mstSet[],int V) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
            
  
    return min_index; 
} 
int printMST(int V,int parent[V], int graph[V][V]) 
{ 
    fprintf(w,"\nEdge \tWeight\n");
    
    for (int i = 1; i < V; i++) 
        fprintf(w,"%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 
void primMST(int V,int graph[V][V]) 
{ 
    
    int parent[V]; 
    int key[V]; 
    bool mstSet[V]; 
  
    // Initialize all keys as INFINITE 
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX; mstSet[i] = false;} 
    key[0] = 1; 
    parent[0] = -1; // First node is always root of MST 
  
    // The MST will have V vertices 
    for (int count = 0; count < V - 1; count++) { 
        int u = minKey(key, mstSet,V); 
  
        // Add the picked vertex to the MST Set 
        mstSet[u] = true;  
        for (int v = 0; v < V; v++){ 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v];} 
    } 
  
    // print the constructed MST 
    printMST(V,parent,graph); 
} 

 int main(int argc,const char *argv[]) 
 { 
     //FILE *r,*w;
     
     int v,e;
     r = fopen(argv[1],"r");
     w = fopen(argv[2],"w");
     fscanf(r,"%d",&v);
     fscanf(r,"%d",&e);
     //printf("%d\n",v);
     //printf("%d\n",e);

     
     int graph[v][v];
     for(int i=0;i<=v;i++){
        for(int j=0;j<=v;j++){
            graph[i][j]=0;
        }
     } 
     
     int test[e][3];
     int i,j,k;
     for(int l=0;l<e;l++)
     { 
      for(int d=0;d<3;d++){
       fscanf(r,"%d ",&test[l][d]);
       }
     }
     fprintf(w,"\n");
     /*for(int l=0;l<e;l++)
     { 
      for(int d=0;d<3;d++){
        
        fprintf(w,"%d ",test[l][d]);
        }
     printf("\n");
     }*/
     int d;
     //printf("%d \n",test[6][2]);
     for(int l=0;l<e;l++)
     {   d=0;
         i=test[l][d];
         j=test[l][d+1];
         k=test[l][d+2];
         graph[i][j]=k;
         graph[j][i]=k;     
     }
     int graph1[v][v];
     for(int l=1;l<=v;l++)
     { 
      for(int d=1;d<=v;d++){
        
        graph1[l][d]=graph[l][d];
        }
     }
     //fprintf(w,"\n");
      /*for(int l=1;l<=v;l++)
     { 
      for(int d=1;d<=v;d++){
        
        fprintf(w,"%d ",graph1[l][d]);
        }
     fprintf(w,"\n");
     }*/
   primMST(v,graph1); 
  return 0;
}








