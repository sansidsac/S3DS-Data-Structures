#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree *left,*right;
};

struct tree* newNode(){
    struct tree* temp=malloc(sizeof(struct tree));
    temp->data='\0';
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct tree* insert(struct tree* root){
    int choice;
    char data[2];
    printf("\nEnter data: ");
    scanf("%s",&data);
    root->data=(char)data[0];
    printf("\nDoes %c have a left child (1/0): ",root->data);
    scanf("%d",&choice);
    if(choice==1){
        root->left=newNode();
        insert(root->left);
    }
    printf("\nDoes %c have a right child (1/0): ",root->data);
    scanf("%d",&choice);
    if(choice==1){
        root->right=newNode();
        insert(root->right);
    }
    return root;
}

void inorder(struct tree* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
    return;
}

void preorder(struct tree* root){
    if(root!=NULL){
        printf("%c ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

void postorder(struct tree* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c ",root->data);
    }
    return;
}

int main(){
    struct tree* root=newNode();
    printf("Enter the expression: ");
    root=insert(root);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}