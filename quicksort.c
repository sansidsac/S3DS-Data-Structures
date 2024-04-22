#include<stdio.h>

int swap(int arr[50],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
    return arr;
}

int partition(int arr[50],int low,int high){
    int pivot=low;
    while(low<high){
        while(arr[pivot]>=arr[low]){
            low++;
        }
        while(arr[pivot]<arr[high]){
            high--;
        }
        if(low<high){
            arr[50]=swap(arr,low,high);
        }
    }
    arr[50]=swap(arr,pivot,high);
    return high;
}

int quicksort(int arr[50],int low,int high){
    if(low<high){
        int loc=partition(arr,low,high);
        quicksort(arr,low,loc-1);
        quicksort(arr,loc+1,high);
    }
    return arr;
}

void main(){
    int arr[50],n;
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
    arr[50]=quicksort(arr,0,n-1);
    printf("\nArray after sorting : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}