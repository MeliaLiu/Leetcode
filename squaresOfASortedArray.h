
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

void merge(int* nums, int* nums1, int numsSize1, int* nums2, int numsSize2)
{
    int m1 = 0;
    int m2 = 0;
    int i = 0;

    while (m1 < numsSize1 && m2 < numsSize2)
    {
        if (nums1[m1] < nums2[m2])
            nums[i++] = nums1[m1++];
        else
            nums[i++] = nums2[m2++];
    }

    if (m1 < numsSize1)
        while (m1 < numsSize1) nums[i++] = nums1[m1++];
    else
        while (m2 < numsSize2) nums[i++] = nums2[m2++];
}

void mergeSort(int* nums, int numsSize)
{
    if (numsSize >= 2)
    {
        int mid = numsSize/2;
        int left[mid];
        int right[numsSize-mid];

        for (int i = 0; i < mid; ++i)
            left[i] = nums[i];

        for (int i = mid; i < numsSize; ++i)
            right[i-mid] = nums[i];

        mergeSort(left, mid);
        mergeSort(right, numsSize-mid);
        merge(nums, left, mid, right, numsSize-mid);

    }
}

int* sortedSquares(int* A, int ASize, int* returnSize){
    for (int i = 0; i < ASize; i++){
        A[i] = A[i]*A[i];
    }
    mergeSort(A, ASize);
    int* res = (int*)malloc(sizeof(int)*ASize);
    for (int i = 0; i < ASize; i++){
        res[i] = A[i];
    }
    *returnSize = ASize;
    return res;
}