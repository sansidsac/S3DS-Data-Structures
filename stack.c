#include <stdio.h>
int top=-1,s[],item;
void push(int size)
{
		if(top==size-1)
			printf("\nStack Overflow\n");
		else
		{
			printf("\nEnter the element : ");
			scanf("%d",&item);
			top=top+1;
			s[top]=item;
		}
}
void pop()
{
	if(top==-1)
		printf("\nStack Underflow\n");
	else
	{
		item=s[top];
		top=top-1;
	}
}	
void display()
{
	printf("\nStack elements are :\n");
	for(int i=top;i>=0;i--)
		printf("%d\n",s[i]);
}
void main()
{
	int n;
	printf("Enter size of stack : ");
	scanf("%d",&n);
	int op=1,menu;
	while(op==1)
	{
		printf("\nMenu\n...........\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter the operation: ");
		scanf("%d",&menu);
		switch(menu)
		{
			case 1:
				push(n);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				op=0;
				break;
			default:
				break;
		}
	}
}
