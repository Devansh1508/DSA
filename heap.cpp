#include <bits/stdc++.h>
#include <array>
using namespace std;

class heap{
    public:
    vector<int> arr;
    int size;

    heap(){
        arr.push_back(-1);
        size=0;
    }

    // time complexity of insert operation is O(logn) 
    // max heap 
    void insert(int val){
        arr.push_back(val); size++;
        int i=size;
        while(i>1 && val>arr[i/2]){
            swap(arr[i],arr[i/2]);
            i=i/2;
        }
    }

    void deleteRoot(){
        if(size==0){cout<<"heap is empty"<<endl; return;}
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int left=2*i;
            int right=2*i+1;
            if(left<size && arr[left]>arr[i]){swap(arr[i],arr[left]); i=left;}
            else if(right<size && arr[right]>arr[i]){swap(arr[i],arr[right]); i=right;}
            else return;
        }
    }

    void print(){
        for (int i=1;i<=size;i++)cout<<arr[i]<<" ";
        cout<<endl;
    }
};

void heapify(vector <int> &arr,int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<n && arr[left]>arr[largest])largest=left;
    if(right<n && arr[right]>arr[largest])largest=right;

    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

int main()
{
    heap h;
    h.insert(20);
    h.insert(10);
    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.print();

    h.deleteRoot();
    h.print();

    vector<int> arr={-1,10,20,30,40,50,80};
    for (int i=(arr.size())/2-1;i>0;i--)heapify(arr,arr.size(),i);
    for (int i=1;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}