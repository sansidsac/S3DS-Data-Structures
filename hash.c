#include <stdio.h>
#include <stdlib.h>

struct hashnode{
	int data;
	struct hashnode*link;
}*ar[10], *ptr=NULL;

int hashfunction(int item){
	struct hashnode* new = (struct hashnode*)malloc(sizeof(int));
	new->data=item;
	new->link=NULL;
	int hvalue;
	hvalue=item%10;
	if(ar[hvalue]==NULL)
		ar[hvalue]=new;
	else{
		new->link=ar[hvalue];
		ar[hvalue]=new;
	}
	return 0;
}

void main(){
	for(int i=0;i<10;i++)
		ar[i]=NULL;
	int item,size;
	printf("Enter total number of items: ");
	scanf("%d",&size);
	for(int i=1;i<=size;i++){
		printf("\nEnter item %d : ",i);
		scanf("%d",&item);
		hashfunction(item);
	}
	printf("\nHash Table\n.........");
	for(int i=0;i<10;i++){
		printf("\nItems at index %d : ",i);
		if(ar[i]==NULL)
			printf("---");
		else{
			ptr=ar[i];
			printf("%d\t",ptr->data);
			while(ptr->link!=NULL){
				ptr=ptr->link;
				printf("%d\t",ptr->data);
			}
		}
		printf("\n");
	}
}
