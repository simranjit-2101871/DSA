#include<iostream>
using namespace std;

//LINEAR SEARCH

/*int linearSearch(int arr[],int size,int elememt){
    for(int i=0; i<size; i++){
        if(arr[i]==elememt){
            return 1;
        }
        else{
            cout<<"Element not found";
        }
    }
    return 0;
}*/
//you know how to print the location code 


//BINARY SEARCH

int binary(int arr[], int size, int element){
    int low, high,mid;
    low=0;
    high=size-1;
    //keep searching untill low<=high
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==element){
            rerturn mid;
        }
        if(arr[mid]<element){
            low=mid=+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    // Unsorted array for linear search
    // int arr[] = {1,3,5,56,4,3,23,5,4,54634,56,34};
    // int size = sizeof(arr)/sizeof(int);



    //Sorted array for binary dearch
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int element=8;
    int searchindex=binsry(arr,size,element);
    cout<<"The element"<<element<<"was found at index"<<seearchindex;
    return 0;
    

}