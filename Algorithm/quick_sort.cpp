/*************************************************************************
 > File Name: quick_sort.cpp
 > Author: furunze
 > Created Time: Fri Apr 26 16:40:42 2024
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 500;
void quick_sort(int arr[],int l,int r);
void partition1(int arr[],int l,int r,int x);
void partition2(int arr[],int l,int r,int x);
void quick_sort(int arr[],int l,int r){
    if(l >= r) return;//边界条件
    int m = (l+r)/2;
    int x = arr[m];//选取中间值作为基准值,小于x的在x的左边,大于x的在x的右边
    partition2(arr,l,r,x);
    quick_sort(arr,l,m-1);
    quick_sort(arr,m+1,r);
}

//用于返回已经排好序的位置的下标
//arr[i] <= x i和a位置交换,i++,a++
//arr[i] > x i++
void partition1(int arr[],int l,int r,int x){
    int a = l,xi = 0;
    for(int i = l;i <= r;i++){
        if(arr[i] <= x){
            swap(arr[a],arr[i]);
            if(arr[a] == x){
                xi = a;
            }
            a++;
        }
    }
    swap(arr[xi],arr[a-1]);
}

//arr[i] < x,a和i位置的值做交换,a++,i++
//arr[i] == x,i++
//arr[i] > x,b和i位置的值做交换,b--
void partition2(int arr[],int l,int r,int x){
    int a = l,b = r;
    int i = l;
    while(i<=b){
        if(arr[i] == x){
            i++;
        }else if(arr[i] < x){
            swap(arr[a++],arr[i++]);
        }else{
            swap(arr[b--],arr[i]);
        }
    }
}

int main(int argc, char* argv[])
{
    int n;
    int arr[N];
    cout<<"请输入数组容量:";
    cin>>n;
    cout<<"请输入数组内容:";
    for(int i = 0;i < n;i++)cin>>arr[i];
    quick_sort(arr,0,n-1);
    for(int i = 0;i < n;i++)cout<<arr[i]<<" ";
    return 0;
}
