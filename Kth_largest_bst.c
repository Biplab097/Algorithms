#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}typedef Node;

Node* root=NULL;

void Inorder(Node*);
int position;
Node* create_Node(int val){

    Node* temp=NULL;
    temp = (Node*)malloc(sizeof(Node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;

    return temp;

}

Node* insert(Node* root,int data){

    
    if(root==NULL){

        root = create_Node(data);        
    }
    else if(data<=root->data){

        root->left=insert(root->left,data);
    }
    else if(data>root->data){

        root->right=insert(root->right,data);
    }
    return root;
}

int main(int argc,char const* argv[]){

    FILE *r;
    r = fopen(argv[1],"r");
    int n,pos;
    fscanf(r,"%d ",&n);
    fscanf(r,"%d ",&pos);
    position=pos;
    int a[n];
    for(int i=0;i<n;i++){
        fscanf(r,"%d",&a[i]);
        root = insert(root,a[i]);
    }
    Inorder(root);

}
void Inorder(Node* ptr){

    Node* temp;

    temp=ptr;
    if(temp!=NULL){
        //Inorder(temp->left);
       
        Inorder(temp->right);
        Inorder(temp->left);
        position--;
        if(position==0)
        printf("%d ",temp->data);
    }
    
}

