
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    *returnSize = 1;
    int len;
    for (len = 0; digits[len] != 0; ++len){
        *returnSize *= (digits[len] == '7' || digits[len] == '9') ? 4 : 3;
    }
    if (len == 0){
        *returnSize = 0;
        return NULL;
    }
    char** res = (char**)malloc((*returnSize)*sizeof(char*));
    char* hash[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    for (int i = 0; i < *returnSize; i++){
        res[i] = (char*)malloc((len+1)*sizeof(char));
        res[i][len] = 0;
    }
    int resSize = 1;
    for (int i = 0; i < len; i++){
        char* strs = hash[digits[i]-50];
        int digitStrLen = (digits[i] == '7' || digits[i] == '9') ? 4 : 3;
        for (int j = 0; j < digitStrLen; ++j){
            for (int k = resSize*j; k < resSize*(j+1); ++k){
                res[k][i] = strs[j]; 
                if (j != 0){
                    for (int q = 0; q < i; ++q){
                        res[k][q] = res[k%resSize][q];
                    }
                }
            }
        }
        resSize *= digitStrLen;
    }
    
    return res;
}
