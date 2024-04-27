/*************************************************************************
 > File Name: heapsort.cpp
 > Author: furunze
 > Created Time: Sat Apr 27 16:18:23 2024
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 500;
int arr[N];
int n;

//堆往上的调整
//i位置代表下标
void heapInsert(int arr[],int i){
    while(arr[i] > arr[(i-1)/2]){
        swap(arr[i],arr[(i-1)/2]);//比父节点大交换位置
        i = (i-1)/2;
    }
}

//堆向下调整
//从第i个位置向下调整
void heapify(int arr[],int i,int size){
    int l = i * 2 + 1;//左孩子
    while(l<size){
        int best = l + 1 < size && arr[l+1] > arr[l]?l+1:l;//l+1是右孩子,如果存在,判断左孩子和右孩子哪个大
        best = arr[best]>arr[i]?best:i;//比较自己与最大的孩子节点的值
        if(best == i) break;//如果自己比较大,不用向下调整,直接退出
        swap(arr[i],arr[best]);//否则交换自己与较大的孩子的位置
        i = best;//接着与下一个左右孩子比较
        l = i * 2 + 1;
        
    }
}

//从顶到底建堆法
//时间复杂度O(N*logN)
void heapsort_TopToBottom(int arr[]){
    for(int i = 0;i < n;i++){
        heapInsert(arr,i);
    }//这一段的复杂度为O(N*logN)
    int size = n;
    while(size>1){
        swap(arr[0],arr[--size]);//将最大的节点arr[0]放在最后一个位置  --size:将size位置与堆断开,表示size位置已经排好序(note:最大下标是n-1,这就是为什么用--size而不是size--)
        heapify(arr,0,size);//调整堆的顺序
    }
}

//从底到顶建堆法
//时间复杂度O(N*logN)
void heapsort_BottomToTop(int arr[]){
    for(int i = n - 1;i>=0;i--){//从n-1的节点向下调整
        heapify(arr,i,n);
    }//这一段的时间复杂度为O(N)
    int size = n;
    while(size>1){
        swap(arr[0],arr[--size]);
        heapify(arr,0,size);
    }
}
int main(int argc, char* argv[])
{
    cin>>n;
    for(int i = 0;i<n;i++)cin>>arr[i];
    heapsort(arr);
    for(int i = 0;i<n;i++)cout<<arr[i]<<" ";
    return 0;
}

