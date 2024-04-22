#include<stdio.h>
#include<stdlib.h>

int top=-1;
int ar[50];

void push(int data){
    top++;
    ar[top]=data;
}

int pop(){
    int data=ar[top];
    top--;
    return data;
}

struct node{
    int data;
    struct node* link;
}*head=NULL, *ptr=NULL;

struct node* insert(struct node* root,int data){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->link=NULL;
    if(root==NULL){
        root=newNode;
    }
    else{
        ptr=root;
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=newNode;
        ptr=NULL;
        return root;
    }
}

void display(struct node* root){
    ptr=root;
    printf("%d ",ptr->data);
    while(ptr->link!=NULL){
        ptr=ptr->link;
        printf("%d ",ptr->data);
    }
}

void palindrome(struct node*root){
    ptr=head;
    while(ptr->link!=NULL){
        push(ptr->data);
        ptr=ptr->link;
    }
    push(ptr->data);
    int flag=0;
    ptr=head;
    while(ptr->link!=NULL){
        if(ptr->data!=pop()){
            flag++;
        }
        ptr=ptr->link;
    }
    if(flag==0){
        printf("\n\nIt is a palindrome");
    }
    else{
        printf("\n\nNot a palindrome");
    }
}

void main(){
    int num, dig;
    printf("Enter number of digits in the number : ");
    scanf("%d",&dig);
    printf("\nEnter the digits : ");
    for(int i=0;i<dig;i++){
        scanf("%d",&num);
        head=insert(head,num);
    }
    printf("\nThe linked list containing number is :");
    display(head);
    palindrome(head);
}