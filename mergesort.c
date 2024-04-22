#include<stdio.h>

int arr[50],brr[50];

void merge(int low,int mid,int high){
    int i=low;
    int x=low;
    int y=mid+1;
    while(x<=mid && y<=high){
        if(arr[x]<=arr[y]){
            brr[i]=arr[x];
            i++;x++;
        }
        else{
            brr[i]=arr[y];
            i++;y++;
        }
    }
    while(x<=mid){
        brr[i]=arr[x];
        i++;x++;
    }
    while(y<=high){
        brr[i]=arr[y];
        i++;y++;
    }
    for(int j=low;j<=high;j++){
        arr[j]=brr[j];
    }
}

void mergesort(int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}

void main(){
    int n;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    printf("\nEnter the array elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nArray before sorting : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    mergesort(0,n-1);
    printf("\nArray after sorting : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}