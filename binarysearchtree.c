#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree *left,*right;
};

struct tree* newNode(int data){
    struct tree* temp=malloc(sizeof(struct tree));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct tree* insert(struct tree* root,int data){
    if(root==NULL){
        return newNode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(struct tree* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
    return;
}

int leftHeight=0,rightHeight=0;
int height(struct tree* node) {
    if (node == NULL)
        return 0;
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight > rightHeight)
            return leftHeight+1;
        else
            return rightHeight+1;
    }
}


int main(){
    struct tree* root=NULL;
    printf("\nEnter number of elements: ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        printf("\nEnter element: ");
        scanf("%d",&data);
        root=insert(root,data);
    }
    int k=height(root);
    inorder(root);
    printf("\n\nHeight is %d",k);
    return 0;
}