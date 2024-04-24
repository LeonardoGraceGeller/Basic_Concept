/*************************************************************************
 > File Name: merge_sort.cpp
 > Author: furunze
 > Created Time: Wed Apr 24 17:19:55 2024
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
const int N = 500;

int n;//数组容量
int arr[N];//被排序的数组
int help[N];//辅助数组,用于实现存放排好序的数组

void merge(int arr[],int l,int m,int r);
void merge_sort_recursion(int arr[],int l,int r);
void merge_sort_notrecursion(int arr[],int l,int r);
//递归版
void merge_sort_recursion(int arr[],int l,int r){
    if(l == r) return;//边界情况
    int m = l+(r-l)/2;//l到r的中点
    //分治
    merge_sort_recursion(arr,l,m);
    merge_sort_recursion(arr,m+1,r);
    
    //合并
    merge(arr,l,m,r);
}

void merge_sort_notrecursion(int arr[],int l,int r){
    //step为步长:1 2 4 8...
    //每次有步长个数相比较
    for(int l,m,r,step = 1;step < n;step <<= 1){
        l = 0;
        while(l < n){
            m = l + step - 1;
            if(m + 1 >= n){
                //此时没有右边界,直接跳出
                break;
            }
            r = min(l + (step << 1) - 1, n - 1);
            //合并
            merge(arr,l,m,r);
            l = r + 1;
        }
    }
}

void merge(int arr[],int l,int m,int r){
    int i = l;//指针,用于移动help数组下标
    int a = l,b = m + 1;//a相当于是左半部分的指针,b是右半部分的指针

    while(a<=m&&b<=r){//左边和右边的每一个值相互比较,谁小谁放在help数组中,并且指针向后移动
        help[i++] = arr[a]<=arr[b]?arr[a++]:arr[b++];
    }
    while(b<=r){//右半部分的剩余元素放在help数组中
        help[i++] = arr[b++];
    }
    while(a<=m){//左半部分的剩余元素放在help数组中
        help[i++] = arr[a++];
    }
    for(i = l;i<=r;i++){
        arr[i] = help[i];
    }
}

int main(int argc, char* argv[])
{
    printf("请输入数组容量");
    scanf("%d",&n);
    printf("请输入数组内容");
    for(int i = 0;i < n;i++)scanf("%d",&arr[i]);
    merge_sort_recursion(arr,0,n-1);
    
    for(int i = 0;i < n;i++)printf("%d ",arr[i]);
    printf("请输入数组内容");
    for(int i = 0;i < n;i++)scanf("%d",&arr[i]);
    merge_sort_notrecursion(arr,0,n-1);
    for(int i = 0;i < n;i++)printf("%d ",arr[i]);
    return 0;
}

