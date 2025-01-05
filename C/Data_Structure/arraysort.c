#include <stdio.h>  
  
int main() {  
    int n, m;  
    scanf("%d", &n); // 读取第一个数组的长度  
    int arr1[n];  
    for (int i = 0; i < n; i++) {  
        scanf("%d", &arr1[i]); // 读取第一个数组的元素  
    }  
      
    scanf("%d", &m); // 读取第二个数组的长度  
    int arr2[m];  
    for (int i = 0; i < m; i++) {  
        scanf("%d", &arr2[i]); // 读取第二个数组的元素  
    }  
      
    // 合并两个数组  
    int merged[n + m];  
    int i = 0, j = 0, k = 0;  
    while (i < n && j < m) {  
        if (arr1[i] < arr2[j]) {  
            merged[k++] = arr1[i++];  
        } else {  
            merged[k++] = arr2[j++];  
        }  
    }  
      
    // 复制剩余的元素  
    while (i < n) {  
        merged[k++] = arr1[i++];  
    }  
    while (j < m) {  
        merged[k++] = arr2[j++];  
    }  
      
    // 输出合并后的数组  
    for (int l = 0; l < n + m; l++) {  
        printf("%d\n", merged[l]);  
    }  
      
    return 0;  
}