// #include <stdio.h>


// void justPrintArr(int arr[], int size){
//     for(int i=0;i<size;i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }


// // void reverseArray(int arr[], int size) {
// //     int i,j,temp;
// //     for(i=0,j=size-1;i<j;i++,j--){
// //         temp = arr[i];
// //         arr[i] = arr[j];
// //         arr[j]= temp;
// //     } 
// // }

// // void sortTheArray(int arr[],int size){
// //     int i,j = 1,temp;
//     // while (j<= size)
//     // {
//     //     for(i=0; i<size-1; i++){
//     //         if(arr[i]>arr[i+1]){
//     //             temp = arr[i];
//     //             arr[i] = arr[i+1];
//     //             arr[i+1] = temp;
//     //         }
//     //     }
//     //     j+= 1;
//     // }
//     // for(i=0; i<size-1; i++){
//     //     if(arr[i]>arr[i+1]){
//     //         temp = arr[i];
//     //         arr[i] = arr[i+1];
//     //         arr[i+1] = temp;
//     //     }
//     // }
// // }

// void rearrangeTheArray(int arr[], int size){
//     int i,j=0,k=0;
//     int arr01[size];
//     int arr02[size];
//     for(i=0;i<size;i++){
//         if (arr[i]<0){
//             arr01[j] = arr[i];
//             j+=1;
//         }else{
//             arr02[k] = arr[i];
//             k+=1;
//         }
//     }

//     for(i=0;i<j;i++){
//         arr[i] = arr01[i];
//     }
//     for(i=0;i<k;i++){
//         arr[j+i] = arr02[i];
//     }
    
// }
// int main() {

//     // Reversing an array 

// //     int arr[] = {1,2,3,4};
// //     for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
// //         printf("%d ",arr[i]);
// //     }
// //     printf("\n");
// //     reverseArray(arr,sizeof(arr)/sizeof(arr[0]));
// //     for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
// //         printf("%d ",arr[i]);
// //     }


// // Sorting an array

// // int arr[] = {4,5,3,7,91,0};
// // justPrintArr(arr,sizeof(arr)/sizeof(arr[0]));
// // sortTheArray(arr,sizeof(arr)/sizeof(arr[0]));
// // justPrintArr(arr,sizeof(arr)/sizeof(arr[0]));

// // seperating the negative and positive elements in an array

// int arr[] = {-14, -5, -3, 7, -91, 1};
// justPrintArr(arr,sizeof(arr)/sizeof(arr[0]));
// rearrangeTheArray(arr,sizeof(arr)/sizeof(arr[0]));
// justPrintArr(arr,sizeof(arr)/sizeof(arr[0]));

//     return 0;
// }

#include <stdio.h>

void rearrangeArray(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left <= right) {
        // Find the first positive element from the left
        while (left <= right && arr[left] < 0) {
            left++;
        }
        // Find the first negative element from the right
        while (left <= right && arr[right] >= 0) {
            right--;
        }
        // Swap the positive and negative elements
        if (left <= right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {-14, -5, -3, 7, -91, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    rearrangeArray(arr, n);

    printf("\nRearranged Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
