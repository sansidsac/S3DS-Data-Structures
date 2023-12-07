#include <stdio.h>
#include <stdlib.h>

struct snode {
	int data;
	struct snode*link;
}*top=NULL, *ptr=NULL, *s=NULL;

struct qnode {
	int data;
	struct qnode*link;
}*front=NULL, *rear=NULL, *ptrq=NULL, *p=NULL;

int item;

int push (){
	struct snode*newNode=(struct node*) malloc(4);
	newNode->data=item;
	newNode->link=NULL;
	if (top==NULL)
		top=newNode;
	else {
		newNode->link=top;
		top=newNode;
	}
	return 0;
}

int pop (){
	if (top==NULL)
		printf("\nStack empty\n");
	else if (top->link==NULL) {
		ptr=top;
		item=top->data;
		top=NULL;
		free(ptr);
		printf("\nPopped element is %d\n",item);
	}
	else {
		ptr=top;
		item=top->data;
		top=ptr->link;
		free(ptr);
		printf("\nPopped element is %d\n",item);
	}
	return 0;
}

int stackDisplay (){
	if (top==NULL)
		printf("\nStack empty\n");
	else {
		printf("\nStack elements:\n");
		ptr=top;
		s=top;
		printf("%d\n",s->data);
		while (ptr->link!=NULL) {
			s=ptr->link;
			printf("%d\n",s->data);
			ptr=ptr->link;
		}
	}
	return 0;
}

int insertion() {
	struct qnode*newNode=(struct node*) malloc(4);
	newNode->data=item;
	newNode->link=NULL;
	if (front==NULL) {
		front=newNode;
		rear=newNode;
	}
	else {
		rear->link=newNode;
		rear=rear->link;
	}
	return 0;
}

int deletion() {
	if (front==NULL)
		printf("\nQueue empty\n");
	else if (front->link==NULL) {
		ptrq=front;
		item=front->data;
		front=NULL;
		rear=NULL;
		free(ptrq);
		printf("\nDeleted element is %d\n",item);
	}
	else {
		ptrq=front;
		item=front->data;
		front=ptrq->link;
		free(ptrq);
		printf("\nDeleted element is %d\n",item);
	}
	return 0;
}

int queueDisplay() {
	if (front==NULL)
		printf("\nQueue empty\n");
	else {
		printf("\nQueue elements:\n");
		ptrq=front;
		p=front;
		printf("%d\t",p->data);
		while (ptrq->link!=NULL) {
			p=ptrq->link;
			printf("%d\t",p->data);
			ptrq=ptrq->link;
		}
	}
	return 0;
}

void main() {
	int op,smenu=0,qmenu=0,promenu=0,prop;
	while (promenu==0) {
		smenu=qmenu=0;
		printf("\nData Structures \n1.Stack 2.Queue 3.Exit \nEnter the action : ");
		scanf("%d",&prop);
		switch(prop) {
			case 1:
				while (smenu==0) {
					printf("\n\nStack Menu \n1.Push, 2.Pop, 3.Display, 4.Exit\nEnter the action : ");
					scanf("%d",&op);
					switch(op) {
						case 1: 
							printf("\nEnter item : ");
							scanf("%d",&item);
							push();
							break;
						case 2:
							pop();
							break;
						case 3:
							stackDisplay();
							break;
						case 4:
							smenu=1;
							break;
						default:
							break;
					}
				}
				break;
			case 2:
				while (qmenu==0) {
					printf("\n\nQueue Menu \n1.Insertion, 2.Deletion, 3.Display, 4.Exit\nEnter the action : ");
					scanf("%d",&op);
					switch(op) {
						case 1: 
							printf("\nEnter item : ");
							scanf("%d",&item);
							insertion();
							break;
						case 2:
							deletion();
							break;
						case 3:
							queueDisplay();
							break;
						case 4:
							qmenu=1;
							break;
						default:
							break;
					}
				}
				break;
			case 3: 
				promenu=1;
				break;
			default:
				break;
		}
	}
}
