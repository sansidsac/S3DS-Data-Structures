#include<stdio.h>

void linearsearch()
{
	int ar[100],n,search,i,flag=0;
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	printf("\nEnter the elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	printf("\nEnter the element to be searched : ");
	scanf("%d",&search);
	for(i=0;i<n;i++)
	{
		if(search==ar[i])
		{
			printf("\nThe elements is at the position %d",i);
			flag=1;
			break;
		}
	}
	if(flag!=1)
		printf("\nThe element is not found \n");
}

void binarysearch()
{
	int ar[100],n,search,i,j,temp,left,right,mid;
	printf("Enter number of elements in array : ");
	scanf("%d",&n);
	printf("\nEnter elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++);
		{
			if(ar[j]>ar[j+1])
			{
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
		}
	}
	printf("\nEnter searchkey : ");
	scanf("%d",&search);
	left=0;
	right=n-1;
	mid=(left+right)/2;
	while(left<=right)
	{
		if(ar[mid]==search)
		{
			printf("\nThe element is at the position %d\n",mid);
			break;
		}
		else if(ar[mid]>search)
		{
			right=mid-1;
			mid=(left+right)/2;
		}
		else if(ar[mid]<search)
		{
			left=mid+1;
			mid=(left+right)/2;
		}
	}
	if(left>right)
		printf("\nThe element is not found\n\n");
}

void main()
{
	int menu;
	printf("Choose the search option \n1.Linear Search \n2.Binary Search \n3.Exit\nEnter your choice : ");
	scanf("%d",&menu);
	switch(menu)
	{
		case 1: linearsearch();
				break;
		case 2: binarysearch();
				break;
		case 3: break;
		default: printf("\nWrong Entry");
				 break;
	}
}
