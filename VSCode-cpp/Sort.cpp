#include<iostream>
#include<stdlib.h>//qsort函数库
template <typename T>
T compare(const void* a, const void* b) {
    return (*(T*)a - *(T*)b);
}
template <typename T>
void Mysort(T a[],int m) {
    qsort(a, m, sizeof(T), compare);
}

int main()
{
    int m=6,a[10]={1,4,2,6,3,5};
    Mysort(a,m); 
    for(int i=0;i<m;i++)
        std::cout<<a[i]<<' ';
    system("pause");
    return 0;   
}