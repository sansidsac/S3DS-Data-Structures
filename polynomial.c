#include<stdio.h>
void main()
{
	struct polynomial
	{
		int coeff;
		int degree;
	}p1[50],p2[50],p3[100],temp;
	int i=0,j=0,k=0,c=0,m,n,op=0;
	while(op==0||op==1||op==2||op==3||op==4||op==5)
	{
	printf("\n\n1.Read first polynomial\n2.Read second polynomial\n3.Display first polynomial\n4.Display second polynomial\n5.Display sum of polynomials\n6.Exit");
	printf("\nEnter your choice ");
	scanf("%d",&op);
	switch(op)
	{
	case 1: printf("\nEnter the number of terms in first polynomial ");
			scanf("%d",&m);
			printf("\nEnter coefficients and its coresponding powers of first polynomial ");
			for(i=0;i<m;i++)
			{
				scanf("%d",&p1[i].coeff);
				scanf("%d",&p1[i].degree);
			}
			for(i=0;i<m;i++)
			{
				for(j=0;j<m-i-1;j++)
				{
					if(p1[j].degree<p1[j+1].degree)
					{
						temp=p1[j];
						p1[j]=p1[j+1];
						p1[j+1]=temp;
					}
				}
			}
			i=0;
			j=0;
			break;
	case 2: printf("\nEnter the number of terms in second polynomial ");
			scanf("%d",&n);
			printf("\nEnter coefficients and its coresponding powers of second polynomial ");
			for(j=0;j<n;j++)
			{
				scanf("%d",&p2[j].coeff);
				scanf("%d",&p2[j].degree);
			}
			for(i=0;i<n;i++)
			{
				for(j=0;j<n-i-1;j++)
				{
					if(p2[j].degree<p2[j+1].degree)
					{
						temp=p2[j];
						p2[j]=p2[j+1];
						p2[j+1]=temp;
					}
				}
			}
			i=0;
			j=0;
			break;
	case 3: printf("\nFirst Polynomial : ");
			for(i=0;i<m;i++)
			{
				printf("%dx*",p1[i].coeff);
				printf("%d  ",p1[i].degree);
			}
			break;
	case 4: printf("\nSecond Polynomial : ");
			for(j=0;j<n;j++)
			{
				printf("%dx*",p2[j].coeff);
				printf("%d  ",p2[j].degree);
			}
			break;
	case 5: while(i!=m||j!=n)
			{
				if(p1[i].degree==p2[j].degree)
				{
					p3[k].degree=p1[i].degree;
					p3[k].coeff=p1[i].coeff+p2[j].coeff;
					i++;
					j++;
					k++;
					c++;
				}
				else if(p1[i].degree>p2[j].degree)
				{
					p3[k].degree=p1[i].degree;
					p3[k].coeff=p1[i].coeff;
					i++;
					k++;
					c++;
				}
				else
				{
					p3[k].degree=p2[j].degree;
					p3[k].coeff=p2[j].coeff;
					j++;
					k++;
					c++;
				}
			}
			while(i<m)
			{
				p3[k].degree=p1[i].degree;
				p3[k].coeff=p1[i].coeff;
				i++;
				k++;
				c++;
			}
			while(j<n)
			{
				p3[k].degree=p2[j].degree;
				p3[k].coeff=p2[j].coeff;
				j++;
				k++;
				c++;
			}
			printf("\nResultant Polynomial : ");
			for(k=0;k<c;k++)
			{
				printf("%dx*",p3[k].coeff);
				printf("%d  ",p3[k].degree);
			}
			printf("\n");
			break;
	case 6: break;
	default: break;
	}
	}
}
