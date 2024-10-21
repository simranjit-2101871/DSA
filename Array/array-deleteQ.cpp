#include<iostream>
using namespace std;
void display(int arr[],int size){
    //traversal code 
    for(int i=0;i<size;i++){
        cout<<"The elememts is"<<arr[i]<<endl;
    }
}

void delet(int arr[],int size,int index){
    //code dor deletion
    for(int i=index;i<size-1;i++){
        arr[i]=arr[i+1];
    }
}

int main(){
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 0;
    display(arr, size);
    delet(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;

}

//how to create extra spaces in output//