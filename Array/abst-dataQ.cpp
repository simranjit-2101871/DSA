#include<iostream>
using anmespace std;
struct mmyarray{
    int total_size;
    int used_size;
    int *ptr;
};

void createarray(struct mmyarray *a, int tsize, int usize){
    //(*a).total_size=tsize;
    //(*a).used_size=usize;
    //(*a).ptr=(int *)malloc(isize*sizeof(int));

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}


void setvalue(struct mmyarray *a){
    int n;
    for(int i=0;i<a->used_size;i++){
        cout<<"Enter element "<<i;
        cin>>
    }
}
int main(){
    struct mmyarray marks;

    return 0;
}

//DO IT AGAIN CODE NOT UNDERSTOOD AND NOT IN A MOOD TO DO IT AGAIN RIGHT NOW//