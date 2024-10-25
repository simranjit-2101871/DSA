/*#include <stdio.h>
#include <stdlib.h>

int max_element(int arr[], int n)
{
    //int max=0;
    //for(int i=0;i<n;i++){

        //for(int j=0;j<n;j++){
            //if(arr[j]>arr[i]]){
                //max=arr[j];
            //}

        //}
    //}
// there is a better logic available

int max = arr[0];           // Start with the first element
for (int i = 1; i < n; i++) // Loop starts from 1 because we already took arr[0] as max
{
    if (arr[i] > max)
    {
        max = arr[i];
    }
}
return max;
}

void frequency(int ar[], int *brr, int n2)
{ // ifyou do int ar then this error happencount.c:38:18: error: subscripted value is neither array nor pointer nor vectorif(ar[i]==ar[j]){^  //well this ussaully happen when and i -> int count;  Incorrect Variable Type: You might be trying to use [] on a variable that isn't declared as an array or pointer. For example, if ar is an integer or some other non-array type, attempting to access ar[i] would cause this error.
  // Reset the frequency array
    for (int i = 0; i < n2; i++)
    {
        brr[i] = 0;
    }

    int count;
    int k;
    for (int i = 0; i < n2; i++)
    {
        // int count=0;//what is th edifference between both intialization
        count = 0;
        for (int j = 0; j < n2; j++)
        {
            if (ar[i] == ar[j])
            {
                count++;
            }
        }
        k = ar[i];
        brr[k] = count;
    }
}

void refilling(int ar2[], int *brr2, int n3)
{
    int k = 0;

    // Iterate over all possible values (0 to maxi)
    for (int i = 0; i < n3; i++)
    {
        // While brr2[i] (frequency) is not zero
        while (brr2[i] > 0)
        {
            // Fill the original array ar2 with the element i
            ar2[k] = i;
            k++;
            // Decrease the frequency count in brr2
            brr2[i]--;
        }
    }
}

int main()
{
    int a[5] = {1, 8, 3, 4, 3};
    int size = 5;

    printf("Before sorting the array is::");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    // take out the max element to define the size of next array
    int maxi = max_element(a, size);

    // size of second array will be now
    // int b[maxi]={0};//make it a dynamic allocation if you want this tyoe of intialization ot work

    // Dynamically allocate the second array
    int *b = (int *)malloc((maxi + 1) * sizeof(int));

    // Initialize the array
    for (int i = 0; i <= maxi; i++)
    {
        b[i] = 0;
    }

    // now calculate the frequency of from first array and fill the second one accordingly
    frequency(a, b, maxi);

    // now we have to fill the old array agian with the elemnets of the b array
    refilling(a, b, maxi + 1);

    // now print the fianl aarray a
    printf("After sorting the array is::");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    free(b);
    return 0;
}
*/


    // question  refilling(a,b,maxi+1);
    // what is the purpise of max+1 size



#include <stdio.h>
#include <stdlib.h>

int max_element(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void frequency(int ar[], int *brr, int n2) {
    // Reset the frequency array
    for (int i = 0; i < n2; i++) {
        brr[i] = 0;
    }
    for (int i = 0; i < n2; i++) {
        brr[ar[i]]++;
    }
}

void refilling(int ar2[], int *brr2, int n3) {
    int k = 0;
    for (int i = 0; i < n3; i++) {
        while (brr2[i] > 0) {
            ar2[k] = i;
            k++;
            brr2[i]--;
        }
    }
}

int main() {
    int a[5] = {1, 8, 3, 4, 3};
    int size = 5;

    printf("Before sorting the array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int maxi = max_element(a, size);

    // Allocate an array with size (maxi + 1) to handle all possible values
    int *b = (int *)malloc((maxi + 1) * sizeof(int));

    // Initialize the array
    for (int i = 0; i <= maxi; i++) {
        b[i] = 0;
    }

    frequency(a, b, size);

    refilling(a, b, maxi + 1);

    printf("After sorting the array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(b);
    return 0;
}
