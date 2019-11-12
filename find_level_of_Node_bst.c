#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}typedef t;
t* root = NULL;
t* creat_node(int);
t* insert_node(t*,int);
void tree_sort(t*,int,int);
int main(int argc,char const* argv[]){
    int n,i;
    FILE *r;
    r = fopen(argv[1],"r");
    int data;
	fscanf(r,"%d ",&n);
    fscanf(r,"%d ",&data);
    int a[n+1];	
	for(i=0;i<n;i++){
		fscanf(r,"%d",&a[i]);
        root=insert_node(root,a[i]);
    }
    //printf("sorted list:");
    tree_sort(root,0,data);
    fclose(r);
    return 0;
}
t* creat_node(int val){
    t* temp;
    temp = (t*)malloc(sizeof(t));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
t* insert_node(t* root,int val){

   
    if(root==NULL){
         root = creat_node(val);
    }
    else if(root->data>val){
        root->left=insert_node(root->left,val);
    }
    else if(root->data<=val){
        root->right=insert_node(root->right,val);
    }
    return root;

}

void tree_sort(t* root,int level,int val){
      
      t* temp;
      temp=root;
      if(temp!=NULL){
          
          if(temp->data==val)printf("level %d ",level);
          level++;
          tree_sort(temp->left,level,val);
          
          //printf("%d ",temp->data);
          tree_sort(temp->right,level,val);
      }
    
}