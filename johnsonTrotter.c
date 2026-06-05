#include <stdio.h>
int getMobile(int a[], int dir[], int n){
    int mobile = 0, mobile_prev = 0;
    for (int i = 0; i < n; i++){
        if (dir[a[i] - 1] == 0 && i != 0){
            if (a[i] > a[i - 1] && a[i] > mobile_prev){
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
        if (dir[a[i] - 1] == 1 && i != n - 1){
            if (a[i] > a[i + 1] && a[i] > mobile_prev){
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }
    return mobile;
}
int searchPos(int a[], int n, int mobile){
    for (int i = 0; i < n; i++){
        if (a[i] == mobile)
            return i;
    }
    return -1;
}
void printPermutation(int a[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void johnsonTrotter(int n){
    int a[n], dir[n];
    for (int i = 0; i < n; i++){
        a[i] = i + 1;
        dir[i] = 0;
    }
    printPermutation(a, n);
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i * (i + 1) / 2; j++)
            ;
    }
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    for (int i = 1; i < fact; i++)
    {
        int mobile = getMobile(a, dir, n);
        int pos = searchPos(a, n, mobile);

        if (dir[mobile - 1] == 0)
        {
            int temp = a[pos];
            a[pos] = a[pos - 1];
            a[pos - 1] = temp;
            pos--;
        }
        else
        {
            int temp = a[pos];
            a[pos] = a[pos + 1];
            a[pos + 1] = temp;
            pos++;
        }

        for (int j = 0; j < n; j++)
        {
            if (a[j] > mobile)
                dir[a[j] - 1] = 1 - dir[a[j] - 1];
        }

        printPermutation(a, n);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
