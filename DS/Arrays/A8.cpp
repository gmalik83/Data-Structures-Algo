#include <bits/stdc++.h>
using namespace std;
// Use Min Heap and call extract-min K times
// Prototype to swap two integers
void swap(int *x, int *y);
// Class for Min-Heap
class MinHeap
{
    int *harr;     //pointer to array of elements in heap
    int capacity;  // maximum possible size
    int heap_size; // Current Number of Elements in Heap
public:
    MinHeap(int a[], int size); // Constructor
    void MinHeapify(int i);     // To MinHeapify Subtree rooted with index
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    // Extract Min Element (Root)
    int extractMin();
    int getMin() { return harr[0]; } // Return Minimum in MinHeap
};
MinHeap::MinHeap(int a[], int size)
{
    heap_size = size;
    harr = a; // Store Address of the array
    int i = (heap_size - 1) / 2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}
// Method to remove minimum element (root) from MinHeap
int MinHeap::extractMin()
{
    if (heap_size == 0)
        return INT_MAX;

    // Store Minimum Value
    int root = harr[0];
    // If more than 1 item , move the last item to root and call heapify
    if (heap_size > 1)
    {
        harr[0] = harr[heap_size - 1];
        MinHeapify(0);
    }
    heap_size--;
    return root;
}
// Method to Min-Heapify the element
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
// Swap Two Elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
// Function to return kth smallest element
int kthsmallest(int arr[], int n, int k)
{
    MinHeap mh(arr, n);
    // ExtractMin K-1 times
    for (int i = 0; i < k - 1; i++)
        mh.extractMin();
    // Return minimum = root
    return mh.getMin();
}

int main()
{
    int arr[] = {5, 2, 3, 1, 0};
    int k = 3;
    cout << k << "th smallest element is " << kthsmallest(arr, 5, k);

    return 0;
}