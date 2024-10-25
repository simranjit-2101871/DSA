#include<stdio.h>

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n){
    int Min, temp;
    printf("Running Selection sort...\n");
    for (int i = 0; i < n-1; i++)
    {
        Min = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[Min]){
                Min = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[Min];
        A[Min] = temp;
    }
}

int main(){
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13


    int A[] = {3, 5, 2, 13, 12};
    int n = 5;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);

    return 0;
}



/*Time Complexity of Selection Sort:
We made 4 passes for an array of length 5. Therefore, for an array of length n we would have to make n-1 passes. And if you count the number of 
comparisons we made at each pass, there were (4+3+2+1), that is, a total of 10 comparisons. And every time we compared; we had a fair possibility 
of updating our min. So, 10 comparisons are equivalent to making 10 updates.

So, for length 5, we had 4+3+2+1 number of comparisons. Therefore, for an array of length n, we would have (n-1) + (n-2) + (n-3) + (n-4) + . . . . . + 1 comparisons.

Sum from 1 to n-1, we get , and hence the time complexity of the algorithm would be O(n2).

 

Selection sort algorithm is not a stable algorithm. Since the smallest element is replaced with the first element at each pass, it may jumble up 
positions of equal elements very easily. Hence, unstable. Refer to the example below:

It is not a recursive algorithm, since we didn’t use recursion here.
Selection sort would anyways compare every element with the min element, regardless of the fact if the array is sorted or not, hence selection 
sort is not an adaptive algorithm by default.
This algorithm offers the benefit of making the least number of swaps to sort an array. We don’t make any redundant swaps here.
 */