#include <stdio.h>
int reverse(int x){
    int temp = x;
    if (x == 0){
        return 0;
    }
    
    int count = 0;
    while (x != 0){
        x /= 10;
        count++;
    }
    
    x = temp;
    
    long long res = 0;
    int num = count;
    int flag = 0;
    int i = 0;
    while (x != 0){
        if (flag == 0){
            if (x%10 == 0){
                num--;
                x /= 10;
            }
            else{
                flag = 1;
            }
        }
        
        if (flag == 1){
            long long component = x%10;
            x /= 10;
            for (int j = 1; j < num-i; j++){
                component *= 10;
            }
            res += component;
            i++;
        }
    }

    return (res <= 2147483647 && res >= -2147483648) ? (int)res : 0;
}


int main()
{
    printf("%d\n", reverse(1563847412));
    return 0;
}