#include <stdio.h>
#include <stdlib.h> /* malloc, free */
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
        int* left = (int*)malloc(mid*sizeof(int));
        int* right = (int*)malloc((numsSize-mid)*sizeof(int));

        for (int i = 0; i < mid; ++i)
            left[i] = nums[i];

        for (int i = mid; i < numsSize; ++i)
            right[i-mid] = nums[i];

        mergeSort(left, mid);
        mergeSort(right, numsSize-mid);
        merge(nums, left, mid, right, numsSize-mid);

        free(left);
        free(right);
    }
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int copy[numsSize];
    for(int i = 0; i < numsSize; i++)
    {
        copy[i] = nums[i];
    }
    
    mergeSort(nums, numsSize);
    int m1 = 0;
    int m2 = numsSize-1;
    while (nums[m1] + nums[m2] != target)
    {
        if (nums[m1] + nums[m2] < target) m1++;
        else if(nums[m1] + nums[m2] > target) m2--;
        else break;
    }

    int ele1 = -1, ele2 = -1;
    for (int i = 0; i < numsSize; i++)
    {
        if (copy[i] == nums[m1]) 
        {   
            ele1 = i;
        }
        if (copy[i] == nums[m2]) 
        {
            ele2 = i;
        }
        
        if (ele1 >= 0 && ele2 >= 0)
        {
            break;
        }
    }
    int* res = (int*)malloc(2*sizeof(int));
    res[0] = ele1;
    res[1] = ele2;
    return res;
}


int main()
{
    int nums[] = {2,7,11,15};
    int target = 9;
    int size = 2;
    int* returnSize = NULL;
    int* r = twoSum(nums, size, target, returnSize);
    printf("%d %d\n", r[0], r[1]);
	return 0;
}