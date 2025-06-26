#include <stdio.h>
#include <stdlib.h>

struct ValueIndex {
    int value;
    int index;
};

// Comparison function for qsort
int compare(const void* a, const void* b) {
    struct ValueIndex* va = (struct ValueIndex*)a;
    struct ValueIndex* vb = (struct ValueIndex*)b;
    return va->value - vb->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* addends = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 2;
    
    if(numsSize == 2) {
        if(nums[0] + nums[1] == target) {
            addends[0] = 0;
            addends[1] = 1;
            return addends;
        }
        else {
            *returnSize = 0;
            return NULL;
        }
    }
    
    struct ValueIndex* valIndexArr = (struct ValueIndex*)malloc(numsSize * sizeof(struct ValueIndex));
    
    for(int i = 0; i < numsSize; i++) {
        valIndexArr[i].value = nums[i];
        valIndexArr[i].index = i;
    }
    
    qsort(valIndexArr, numsSize, sizeof(struct ValueIndex), compare);
    
    int left = 0;
    int right = numsSize - 1;
    
    while(left < right) {
        int sum = valIndexArr[left].value + valIndexArr[right].value;
        
        if(target == sum) {
            addends[0] = valIndexArr[left].index;
            addends[1] = valIndexArr[right].index;
            return addends;
        }
        else if(sum > target) {
            right--;
        }
        else {
            left++;
        }
    }
    
    free(valIndexArr);
    *returnSize = 0;
    return NULL;
}

// Test function
int main() {
    // Test case 1: [2,7,11,15], target = 9
    int nums1[] = {2, 7, 11, 15};
    int returnSize1;
    int* result1 = twoSum(nums1, 4, 9, &returnSize1);
    
    printf("Test 1: [2,7,11,15], target = 9\n");
    if(result1 != NULL) {
        printf("Result: [%d, %d]\n", result1[0], result1[1]);
        free(result1);
    } else {
        printf("No solution found\n");
    }
    
    // Test case 2: [3,2,4], target = 6
    int nums2[] = {3, 2, 4};
    int returnSize2;
    int* result2 = twoSum(nums2, 3, 6, &returnSize2);
    
    printf("\nTest 2: [3,2,4], target = 6\n");
    if(result2 != NULL) {
        printf("Result: [%d, %d]\n", result2[0], result2[1]);
        free(result2);
    } else {
        printf("No solution found\n");
    }
    
    // Test case 3: [3,3], target = 6
    int nums3[] = {3, 3};
    int returnSize3;
    int* result3 = twoSum(nums3, 2, 6, &returnSize3);
    
    printf("\nTest 3: [3,3], target = 6\n");
    if(result3 != NULL) {
        printf("Result: [%d, %d]\n", result3[0], result3[1]);
        free(result3);
    } else {
        printf("No solution found\n");
    }
    
    return 0;
}