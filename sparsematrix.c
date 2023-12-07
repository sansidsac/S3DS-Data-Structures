#include<stdio.h>
void main()
{
	int op=1,m;
	while(op==1)
	{
		int m1[50][50],m2[50][50],r1,c1,r2,c2;
		int sp1[50][50],sp2[50][50],l1,l2;
		int spt1[50][50],spt2[50][50];
		int result[50][50];
		int i,j,k;
		printf("Menu\n1.Input matrix 1\n2.Input matrix 2\n3.Display sparse matrix 1\n4.Display sparse matrix 2\n5.Display tuple matrix 1\n6.Display tuple matrix 2\n7.Display transpose of tuple matrix 1\n8.Display transpose of tuple matrix 2\n9.Display sum of tuple matrices\n10.Exit\nChoose the option to perform : ");
		scanf("%d",&m);
		switch(m)
		{
			case 1: 
				printf("\nEnter no.of rows and columns of matrix 1 : ");
				scanf("%d %d",&r1,&c1);
				printf("\nEnter the elements of matrix 1 : ");
				for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
						scanf("%d",&m1[i][j]);
				}
				sp1[0][0]=r1;
				sp1[0][1]=c1;
				k=1;
				for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
					{
						if(m1[i][j]!=0)
						{
							sp1[k][0]=i;
							sp1[k][1]=j;
							sp1[k][2]=m1[i][j];
							k++;
						}
					}
				}
				l1=k;
				sp1[0][2]=k-1;
				break;
			case 2:
				printf("\nEnter no.of rows and columns of matrix 2 : ");
				scanf("%d %d",&r2,&c2);
				printf("\nEnter the elements of matrix 2 : ");
				for(i=0;i<r2;i++)
				{
					for(j=0;j<c2;j++)
						scanf("%d",&m2[i][j]);
				}
				sp2[0][0]=r2;
				sp2[0][1]=c2;
				k=1;
				for(i=0;i<r2;i++)
				{
					for(j=0;j<c2;j++)
					{
						if(m2[i][j]!=0)
						{
							sp2[k][0]=i;
							sp2[k][1]=j;
							sp2[k][2]=m2[i][j];
							k++;
						}
					}
				}
				l2=k;
				sp2[0][2]=k-1;
				break;
			case 3:
				printf("\n\n");
				for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
						printf("%d\t",m1[i][j]);
					printf("\n");
				}
				printf("\n\n");
				break;
			case 4:
				printf("\n\n");
				for(i=0;i<r2;i++)
				{
					for(j=0;j<c2;j++)
						printf("%d\t",m2[i][j]);
					printf("\n");
				}
				printf("\n\n");
				break;
			case 5:
				printf("\n\n");
				for(i=0;i<l1;i++)
				{
					for(j=0;j<3;j++)
						printf("%d\t",sp1[i][j]);
					printf("\n");
				}
				printf("\n\n");
				break;
			case 6:
				printf("\n\n");
				for(i=0;i<l2;i++)
				{
					for(j=0;j<3;j++)
						printf("%d\t",sp2[i][j]);
					printf("\n");
				}
				printf("\n\n");
				break;
			case 7:
				spt1[0][0]=sp1[0][1];
				spt1[0][1]=sp1[0][0];
				spt1[0][2]=sp1[0][2];
				k=1;
				for(i=0;i<c1;i++)
				{
					for(j=1;j<=spt1[0][2];j++)
					{
						if(sp1[j][1]==i)
						{
							spt1[k][0]=sp1[j][1];
							spt1[k][1]=sp1[j][0];
							spt1[k][2]=sp1[j][2];
							k++;
						}
					}
				}
				printf("\n");
				for(i=0;i<k;i++)
				{
					for(j=0;j<3;j++)
						printf("%d\t",spt1[i][j]);
					printf("\n");
				}
				printf("\n");
				break;
			case 8:
				spt2[0][0]=sp2[0][1];
				spt2[0][1]=sp2[0][0];
				spt2[0][2]=sp2[0][2];
				k=1;
				for(i=0;i<c2;i++)
				{
					for(j=1;j<=spt2[0][2];j++)
					{
						if(sp2[j][1]==i)
						{
							spt2[k][0]=sp2[j][1];
							spt2[k][1]=sp2[j][0];
							spt2[k][2]=sp2[j][2];
							k++;
						}
					}
				}
				printf("\n");
				for(i=0;i<k;i++)
				{
					for(j=0;j<3;j++)
						printf("%d\t",spt2[i][j]);
					printf("\n");
				}
				printf("\n");
				break;
			case 9:
				if(r1==r2 && c1==c2)
				{
					result[0][0]=sp1[0][0];
					result[0][1]=sp1[0][1];
					i=1;
					j=1;
					k=1;
					while(i<l1 && j<l2)
					{
						if(sp1[i][0]==sp2[j][0])
						{
							if (sp1[i][1]==sp2[j][1])
							{
								result[k][0]=sp1[i][0];
								result[k][1]=sp1[i][1];
								result[k][2]=sp1[i][2]+sp2[j][2];
								i++;
								j++;
								k++;
							}
							else if (sp1[i][1]<sp2[j][1])
							{
								result[k][0]=sp1[i][0];
								result[k][1]=sp1[i][1];
								result[k][2]=sp1[i][2];
								i++;
								k++;
							}
							else
							{
								result[k][0]=sp2[j][0];
								result[k][1]=sp2[j][1];
								result[k][2]=sp2[j][2];
								j++;
								k++;
							}
						}
						else if(sp1[i][0]<sp2[j][0])
						{
							result[k][0]=sp1[i][0];
							result[k][1]=sp1[i][1];
							result[k][2]=sp1[i][2];
							i++;
							k++;
						}
						else
						{
							result[k][0]=sp2[j][0];
							result[k][1]=sp2[j][1];
							result[k][2]=sp2[j][2];
							j++;
							k++;
						}
					}
					while(i<l1)
					{
						result[k][0]=sp1[i][0];
						result[k][1]=sp1[i][1];
						result[k][2]=sp1[i][2];
						i++;
						k++;
					}
					while(j<l2)
					{
						result[k][0]=sp2[j][0];
						result[k][1]=sp2[j][1];
						result[k][2]=sp2[j][2];
						j++;
						k++;
					}
					result[0][2]=k-1;
					for(i=0;i<k;i++)
					{
						if(result[i][2]==0)
						{
							for(j=i;j<k-1;j++)
							{
								result[j][0]=result[j+1][0];
								result[j][1]=result[j+1][1];
								result[j][2]=result[j+1][2];
							}
							k--;
						}
					}
					result[0][2]=k-1;
					printf("\n\n");
					for(i=0;i<k;i++)
					{
						for(j=0;j<3;j++)
							printf("%d\t",result[i][j]);
						printf("\n");
					}
					printf("\n\n");
				}
				else
					printf("\nAddition not possible\n");
				break;
			case 10:
				op=0;
				break;
			default:
				printf("\nInvalid entry\n");
				break;
		}
	}
}
