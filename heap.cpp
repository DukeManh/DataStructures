#include <cmath>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void swap(T *a, T *b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template <typename T>
class MaxHeap
{
    T *arr;
    int capacity;
    int size;

public:
    MaxHeap(int cap);
    ~MaxHeap();
    void heapify(int i);
    int left(int i);
    int right(int i);
    int parent(int i);
    T getMax();
    void extractMax();
    bool remove(T key);
    bool insert(T key);
    void print();
    // void decreasekey(int key, T newVal);
    void changekey(int i, T newval);
    int getheight();
    void diagram();
};

template <typename T>
MaxHeap<T>::MaxHeap(int cap)
{
    arr = new T[cap];
    size = 0;
    capacity = cap;
}

template <typename T>
MaxHeap<T>::~MaxHeap() { delete[] arr; }

template <typename T>
T MaxHeap<T>::getMax() { return *arr; }

template <typename T>
int MaxHeap<T>::left(int i) { return 2 * i + 1; }

template <typename T>
int MaxHeap<T>::right(int i) { return 2 * i + 2; }

template <typename T>
int MaxHeap<T>::parent(int i) { return (i - 1) / 2; }

template <typename T>
void MaxHeap<T>::heapify(int i)
{

    int l = left(i);
    int r = right(i);
    int biggest = i;

    if (l < size && arr[l] > arr[i])
        biggest = l;
    if (r < size && arr[r] > arr[biggest])
        biggest = r;

    if (biggest != i)
    {
        swap<T>(&arr[biggest], &arr[i]);
        heapify(biggest);
    }
}

template <typename T>
void MaxHeap<T>::extractMax()
{
    arr[0] = arr[size - 1];
    size--;
    heapify(0);
}

template <typename T>
bool MaxHeap<T>::insert(T key)
{
    if (size == capacity)
    {
        cout << "\nno more space!!" << endl;
        return false;
    }
    arr[size++] = key;
    int i = size - 1;
    while (arr[i] > arr[parent(i)])
    {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
    return true;
}

template <typename T>
bool MaxHeap<T>::remove(T key)
{
    // for (int i = 0; arr[i] != key, i < size; i++)
    // ;
    int i = 0;
    while (arr[i] != key && i < size)
    {
        i++;
    }

    if (i == size)
    {
        cout << "Key not found, my apology." << endl;
        return false;
    }

    arr[i] = arr[size - 1];
    size--;
    heapify(i);
    return true;
}
template <typename T>
void MaxHeap<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
//template <typename T>
//void MaxHeap<T>::decreasekey(int i, T newVal)
//{
//arr[i] = newVal;
//}
template <typename T>
void MaxHeap<T>::changekey(int i, T newval)
{
    if (newval < arr[i])
    {
        arr[i] = newval;
        heapify(i);
    }
    else if (newval > arr[i])
    {
        arr[i] = newval;
        while (i != 0 && arr[i] > arr[parent(i)])
        {
            swap(&arr[i], &arr[parent(i)]);
            i = parent(i);
        }
    }
}
template <typename T>
int MaxHeap<T>::getheight()
{
    return ceil(log2(size + 1)) - 1;
}
template <typename T>
void heapify(int i, T arr[], int size)
{

    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int biggest = i;

    if (l < size && arr[l] > arr[i])
        biggest = l;
    if (r < size && arr[r] > arr[biggest])
        biggest = r;

    if (biggest != i)
    {
        swap<T>(&arr[biggest], &arr[i]);
        heapify(biggest, arr, size);
    }
}

template <typename T>
void buidheap(T arr[], int size)
{
    int n = size / 2 - 1;

    for (int i = n; i >= 0; --i)
    {
        heapify(i, arr, size);
    }
}
template <typename T>
void MaxHeap<T>::diagram()
{
    int n = 0;
    for (int i = 0; i <= getheight(); ++i)
    {
        int width = pow(2.0, double(i));

        for (int j = 0; j < width; ++j)
        {
            if (n < size)
            {
                cout << " " << arr[n];
                n++;
            }
        }
        cout << endl;
    }
}
int main()
{
    MaxHeap<string> heap(10);
    heap.insert("Canada");
    heap.print();
    cout << heap.getMax() << endl;

    heap.insert("Australia");
    heap.insert("USA");
    heap.insert("Germany");
    heap.insert("Sweden");
    heap.insert("Switzerland");
    heap.insert("France");
    heap.print();
    cout << heap.getMax() << endl;
    heap.extractMax();
    heap.print();
    cout << heap.getMax() << endl;
    heap.remove("Viet Nam");
    heap.remove("France");
    heap.print();
    heap.changekey(0, "Austria");
    heap.print();
    heap.changekey(3, "Switzerland");
    heap.print();
    int i = 0;
    cout << (bool)isnan(i) << endl;

    int arr[] = {6, 4, 8, 48, 35, 9, 2, 45, 21, 80, 0, 87, 5};
    buidheap<int>(arr, sizeof arr / sizeof *arr);
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    MaxHeap<int> test(10);
    test.insert(5);
    test.insert(1);
    test.insert(9);
    test.insert(6);
    test.insert(8);
    test.insert(0);
    test.insert(2);
    test.insert(10);
    test.diagram();
}