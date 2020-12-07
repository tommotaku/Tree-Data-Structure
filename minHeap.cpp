#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    int size;
    vector<int> heap;
    int capacity;
    public:
    MinHeap(int capacity);
    void insert(int key);
    void heapify(int i);
    int extractMin();
    void decreaseKey(int i, int val);
    void deleteKey(int k);

    int parent(int i);
    int left(int i);
    int right(int i);
};

MinHeap::MinHeap(int capacity){
    int size = 0;
    heap.resize(capacity);
}

int MinHeap::parent(int i){
    return (i-1)/2;
}

int MinHeap::left(int i){
    return 2*i+1;
}

int MinHeap::right(int i){
    return 2*i+2;
}

void MinHeap::insert(int key){
    if(size == capacity)
        cout << "Heap is full";
    else{
        size++;
        int i = size-1;
        heap[i] = key;
        while(i != 0 && heap[parent(i)] > heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
        cout << "Inserted successfully";
    }    
}

int MinHeap::extractMin(){
    if(size == 0)
        return -1;
    if(size == 1){
        int k = heap[0];
        size--;
        return k;
    }
    else{
        int k = heap[0];
        heap[0] = heap[size-1];
        size--;
        heapify(0);
        return k;
    }
}

void MinHeap::heapify(int i){
    int smallest = i;
    int l = left(i);
    int r = right(i);
    if(l < size && heap[l] < heap[i]){
        smallest = l;
    }
    if(r < size && heap[r] < heap[smallest]){
        smallest = r;
    }
    if(smallest != i){
        swap(heap[smallest], heap[i]);
        heapify(smallest);
    }
}

void MinHeap::decreaseKey(int i, int val){
    heap[i] = val;
    while(i != 0 && heap[parent(i)] < heap[i]){
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}

int main(){
    MinHeap h(10);
    h.insert(3);
    h.insert(1);
    h.insert(4);
    h.insert(5);
    h.insert(8);
    h.insert(9);
    h.insert(6);
    cout << h.extractMin() << endl;
    h.deleteKey(3);
    cout << h.extractMin() << endl;
}