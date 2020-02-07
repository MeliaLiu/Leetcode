#include <stdio.h>
int myAtoi(char * str){
    int start = 0;
    while (str[start] == ' '){
        start++;
    }
    if (str[start] != '-' && str[start] != '+' && (str[start] < 48 || str[start] > 57)){
        return 0;
    }
    while (str[start] != '-' && str[start] != '+' && (str[start] < 48 || str[start] > 57)){
        start++;
        if (str[start] == 0){
            return 0;
        }
    }

    int end = start;
    while (str[end+1] >= 48 && str[end+1] <= 57){
        end++;
    }

    int sign = 1;
    if (str[start] == '-'){
        sign = -1;
        start++;
    }else if(str[start] == '+'){
        start++;
    }
    
    long long res = 0;

    int flag = 0;
    while (start <= end){
        long long temp = str[start]-48;
        if (temp != 0 || flag == 1){
            if (end-start+1 > 10){
                return sign == 1 ? 2147483647 : -2147483648;
            }
            for (int i = 0; i < end-start; i++){
                temp *= 10;
            }
            res += temp;
            flag = 1;
        }
        start++;
    }
    
    if (sign == 1){
        return res > 2147483647 ? 2147483647 : (int)res;
    }else{
        return 0-res < -2147483648 ? -2147483648 : (int)(0-res);
    }
}


int main()
{
    printf("%d\n", myAtoi("  0000000000012345678"));
    return 0;
}