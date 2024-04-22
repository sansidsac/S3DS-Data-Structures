#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
}*head1=NULL,*head2=NULL,*ptr1=NULL,*ptr2=NULL,*ptr=NULL;

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

struct node* merge(struct node* root1,struct node* root2){
    ptr=root1;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=root2;
    return root1;
}

struct node* sort(struct node*root){
    ptr1=root;
    while(ptr1->link!=NULL){
        ptr2=ptr1->link;
        while(ptr2->link!=NULL){
            if(ptr1->data > ptr2->data){
                int temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
    }
    return root;
}

void main(){
    int op=0;
    while(op!=6){
        printf("\nMENU\n..........\n");
        printf("1.Enter list 1\n2.Enter list 2\n3.Display list 1\n4.Display list 2\n5.Merge and Sort lists");
        printf("\n6.Exit\nEnter your choice: ");
        scanf("%d",&op);
        if(op==1||op==2){
            printf("\n\nEnter number of elements in list %d: ",op);
            int n;
            scanf("%d",&n);
            for(int i=0;i<n;i++){
                printf("\nEnter element %d: ",i+1);
                int data;
                scanf("%d",&data);
                if(op==1)
                    head1=insert(head1,data);
                else
                    head2=insert(head2,data);
            }
        }
        else if(op==3){
            printf("\n\nList 1 is: ");
            display(head1);
        }
        else if(op==4){
            printf("\n\nList 2 is: ");
            display(head2);
        }
        else if(op==5){
            head1=merge(head1,head2);
            head1=sort(head1);
            printf("\n\nThe merged list is: ");
            display(head1);
        }
        else if(op==6)
            break;
        else{
            printf("\n\nEnter a valid choice!!!!");
            op=0;
        }
    }
}