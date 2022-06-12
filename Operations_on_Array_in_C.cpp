#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Array{

    int A[10];
    int length;
    int size;

};

    void display(struct Array arr){
        cout<<"Elements are:"<<endl;
        for(int i=0;i<arr.length;i++){
            cout<<arr.A[i];
        }
    }
    void append(struct Array *arr,int x){
        if(arr->length<arr->size){
            arr->A[arr->length++]=x;
        }

    }
    void insert(struct Array *arr,int x,int index){
        if(index>0 && index<=arr->length){
            for(int i=arr->length;i>index;i--){
                arr->A[i]=arr->A[i-1];
            }
            arr->A[index]=x;
            arr->length++;

        }

    }
    int Delete(struct Array *arr,int index){

        int x=0;
        x=arr->A[index];
        if(index>0 && index<arr->length){
            for(int i=index;i<arr->length-1;i++){
                arr->A[i]=arr->A[i+1];
            }
        }

        return x;

    }
    void swap(int *x,int *y){
        int temp;
        temp=*x;
        *x=*y;
        *y=temp;
    }
    int LinearSearch(struct Array *arr,int key){
        for(int i=0;i<arr->length;i++){
            if(arr->A[i]==key){
                swap(&arr->A[i],&arr->A[i-1]);
                return i;
            }
        }
        return -1;
    }
    int BinarySearch(struct Array *arr,int key){
        int first=0,last,mid;
        last=arr->length-1;
        while(first<=last){
            mid=(first+last)/2;
            if(arr->A[mid]==key){
                return mid;
            }
            else if(arr->A[mid]<key){
                first=mid+1;
            }
            else{
                last=mid-1;
            }
        
        }
        return -1;
    }
    int RBinarySearch(int a[],int first,int last,int key){

        int mid=0;

        if(first<=last){

            mid=(first+last)/2;
            
            if(key==a[mid]){
                return mid;
            }
            else if(key<a[mid]){
                return RBinarySearch(a,first,mid-1,key);
            }
            else{
                return RBinarySearch(a,mid+1,last,key);
            }
        }
        return -1;
    }
    int Get(struct Array arr,int index){
        if(index>=0 && index<arr.length){
            return arr.A[index];
        }
        return -1;
    }
    void Set(struct Array *arr,int index,int x){
        if(index>=0 && index<arr->length){
            arr->A[index]=x;
        }
    }
    int max(struct Array arr){
        int max1=arr.A[0];
        for(int i=1;i<arr.length;i++){
            if(max1<arr.A[i]){
                max1=arr.A[i];
            }
        }
        return max1;
    }
    int min(struct Array arr){
        int min1=arr.A[0];
        for(int i=1;i<arr.length;i++){
            if(min1>arr.A[i]){
                min1=arr.A[i];
            }
        }
        return min1;
    }
    int sum(struct Array arr){
        int sum=0;
        for(int i=0;i<arr.length;i++){
            sum+=arr.A[i];
        }
        return sum;
    }
    float avg(struct Array arr){
        return (float)sum(arr)/arr.length;
    }
    void ReverseArray1(struct Array *arr){
        int *B;
        B=new int[arr->length];
        for(int i=arr->length-1,j=0;i>=0;i--,j++){
            B[j]=arr->A[i];
        }
        for(int i=0;i<arr->length;i++){
            arr->A[i]=B[i];
        }
    }
    void ReverseArray2(struct Array *arr){
        int temp=0;
        for(int i=0,j=arr->length-1;i<j;i++,j--){
            temp=arr->A[i];
            arr->A[i]=arr->A[j];
            arr->A[j]=temp;
        }
    }
    void InsertSort(struct Array *arr,int x){
        if(arr->length==arr->size){
            cout<<"element cannot be inserted array full.";
        }
        int i=arr->length-1;
        while(i>=0 && arr->A[i]>x){
            arr->A[i+1]=arr->A[i];
            i--;
        }
        arr->A[i+1]=x;
        arr->length++;
        
    }
    int isSorted(struct Array arr){
        for(int i=0;i<arr.length-1;i++){
            if(arr.A[i]>arr.A[i+1]){
                return 0;
            }
        }
        return 1;
    }
    void ReArrange(struct Array *arr){
        int i=0;
        int j=arr->length-1;
        while(i<j){
            while(arr->A[i]<0){
                i++;
            }
            while(arr->A[j]>0){
                j--;
            }
            if(i<j){
                swap(arr->A[i],arr->A[j]);
            }
        }
    }
    struct Array* MergeArray(struct Array *arr1,struct Array *arr2){

        struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
        int i=0,j=0,k=0;

        while(i<arr1->length && j<arr2->length){
            if(arr1->A[i]<arr2->A[j]){
                arr3->A[k++]=arr1->A[i++];
            }
            else{
                arr3->A[k++]=arr2->A[j++];
            }
        }
        for(;i<arr1->length;i++){
            arr3->A[k++]=arr1->A[i];
        }
        for(;j<arr2->length;j++){
            arr3->A[k++]=arr2->A[j];
        }
        arr3->length=arr1->length+arr2->length;
        arr3->size=10;
        return arr3;
    }
    struct Array* Union(struct Array *arr1,struct Array *arr2){

        struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
        int i=0,j=0,k=0;

        while(i<arr1->length && j<arr2->length){
            if(arr1->A[i]<arr2->A[j]){
                arr3->A[k++]=arr1->A[i++];
            }
            else if(arr1->A[i]>arr2->A[j]){
                arr3->A[k++]=arr2->A[j++];
            }
            else{
                arr3->A[k++]=arr1->A[i++];
                j++;
            }
        }
        for(;i<arr1->length;i++){
            arr3->A[k++]=arr1->A[i];
        }
        for(;j<arr2->length;j++){
            arr3->A[k++]=arr2->A[j];
        }
        arr3->length=k;
        arr3->size=10;
        return arr3;
    }
    struct Array* Intersection(struct Array *arr1,struct Array *arr2){

        struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
        int i=0,j=0,k=0;

        while(i<arr1->length && j<arr2->length){
            if(arr1->A[i]<arr2->A[j]){
                i++;
            }
            else if(arr1->A[i]>arr2->A[j]){
                j++;
            }
            else{
                arr3->A[k++]=arr1->A[i++];
                j++;
            }
        }
    
        arr3->length=k;
        arr3->size=10;
        return arr3;
    }
    struct Array* Difference(struct Array *arr1,struct Array *arr2){

        struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
        int i=0,j=0,k=0;

        while(i<arr1->length && j<arr2->length){
            if(arr1->A[i]<arr2->A[j]){
                arr3->A[k++]=arr1->A[i++];
            }
            else if(arr1->A[i]>arr2->A[j]){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        for(;i<arr1->length;i++){
            arr3->A[k++]=arr1->A[i];
        }
        
        arr3->length=k;
        arr3->size=10;
        return arr3;
    }


int main(){

    int a=0;
    Array arr1={{1,2,3,4,5},5,10};
    Array arr2={{4,5,6,7,9},5,10};
    Array *arr3;
    //  append(&arr1,9);
    //  insert(&arr1,8,1);
    //  Delete(&arr1,2);
    // a=LinearSearch(&arr1,3);
    // cout<<a;
    // Set(&arr1,0,9);
    // display(arr1);
    //a=RBinarySearch(arr1.A,0,arr1.length,1);
    //cout<<a;
    //cout<<Get(arr1,3);
    //cout<<max(arr1);
    //cout<<min(arr1);
    //cout<<avg(arr1);
    // ReverseArray2(&arr1);
    // display(arr1);
    // InsertSort(&arr1,3);
    // display(arr1);
    // cout<<isSorted(arr1);
    //ReArrange(&arr1);
    // arr3=MergeArray(&arr1,&arr2);
    // display(*arr3);
    arr3=Difference(&arr1,&arr2);
    display(*arr3);

    return 0;
}

