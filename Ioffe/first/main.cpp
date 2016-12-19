#include <stdio.h>
#define True 1
int main() {

    int x1, x2, y1, y2, x, y;
    int sum1, sum2, sum, cnt = 0, cnt1 = 0, cnt2 = 0, n, k = 1;
    float z;

    printf("Введите целую часть первого числа не более 9 цифр:");
    scanf("%9d",&x1);
    printf("Введите дробную часть первого числа не более 9 цифр:");
    scanf("%9d",&x2);
    printf("Введите целую часть первого числа не более 9 цифр:");
    scanf("%9d",&y1);
    printf("Введите дробную часть первого числа не более 9 цифр:");
    scanf("%9d",&y2);
    printf("Переменная x=%d%s%d",x1,".",x2);
    printf("\nПеременная y=%d%s%d",y1,".",y2);
    sum1 = x1 + y1;
    y = y2;
    x = x2;
    if (x1 < 0) x = -x;
    else if (y1 < 0) y = -y;
    while (x2 >= 1){
        x2/=10;
        cnt1+=1;
    }
    while (y2 >= 1){
        y2/=10;
        cnt2++;
    }
        if (cnt1 < cnt2){
            n = cnt2 - cnt1;
            for (int i = 0; i < n; ++i) {
                k*=10;
            }
            x = x*k;
            sum2 = x + y;
            cnt1 = cnt2;
        }
        else if (cnt1 > cnt2){
            n = cnt1 - cnt2;
            for (int i = 0; i < n; ++i) {
                k*=10;
            }
            y = y*k;
            sum2 = x + y;
            cnt2 = cnt1;
        } else {

            sum2 = x + y;
        }

    sum = sum2;
    while (sum2){
        sum2/=10;
        cnt+=1;
    }

    if (cnt > cnt2){
        k = 1;
        sum1+=1;
        for (int i = 0; i < cnt - 1; ++i) {
            k*=10;
        }
        sum = sum - k;
  }
    sum2 = sum;
    cnt = 0;
    while (sum2){
        sum2/=10;
        cnt+=1;
    }
    if (cnt < cnt2){
        printf("\nРезультат сложения =%d%s%d%d",sum1,".",0,sum);
    } else{
        printf("\nРезультат сложения =%d%s%d",sum1,".",sum);
    }






//    return 0;
}