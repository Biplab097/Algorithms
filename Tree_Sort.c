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
void tree_sort(t*);
int main(int argc,char const* argv[]){
    int n,i;
    FILE *r;
    r = fopen(argv[1],"r");
	fscanf(r,"%d",&n);
    int a[n+1];	
	for(i=0;i<n;i++){
		fscanf(r,"%d",&a[i]);
        root=insert_node(root,a[i]);
    }
    printf("sorted list:");
    tree_sort(root);
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

void tree_sort(t* root){
      
      t* temp;
      temp=root;
      if(temp!=NULL){
          tree_sort(temp->left);
          
          printf("%d ",temp->data);
          tree_sort(temp->right);
      }
    
}