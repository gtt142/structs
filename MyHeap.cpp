#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyHeap{
private:
	vector<T> heap;
	int parent(int);
	int leftChild(int);
	int rightChild(int);
	void siftDown(int);
	void siftUp(int);

public:
	void push(T);
	T getMax() {};
	
	void print();
};

template <typename T>
void MyHeap<T>::print() {
	for (vector<T>::iterator it = heap.begin(); it != heap.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;
}

template <typename T>
int MyHeap<T>::leftChild(int par) {
	int left = 2 * par + 1;
	if (left < heap.size())
		return left;
	return -1;
}

template <typename T>
int MyHeap<T>::rightChild(int par) {
	int right = 2 * par + 2;
	if (right < heap.size())
		return right;
	return -1;
}

template <typename T>
int MyHeap<T>::parent(int child) {
	int par = (child - 1) / 2;
	if (child != 0)
		return par;
	return -1;
}

template <typename T>
void MyHeap<T>::siftDown(int el) {
	int lChild = leftChild(el);
	int rChild = rightChild(el);
	int maxval = el;
	if (lChild >= 0 && heap[lChild] > heap[maxval])
		maxval = lChild;
	if (rChild >= 0 && heap[rChild] > heap[maxval])
		maxval = rChild;
	if (maxval != el) {
		T temp = heap[el];
		heap[el] = heap[maxval];
		heap[maxval] = temp;
		siftDown(maxval);
	}
}

template <typename T>
void MyHeap<T>::siftUp(int el) {
	while (el > 0)
	{
		int par = parent(el);
		if (heap[par] >= heap[el])
			return;
		T temp = heap[par];
		heap[par] = heap[el];
		heap[el] = temp;
		el = par;
	}
}

template <typename T>
void MyHeap<T>::push(T el) {
	heap.push_back(el);
	siftUp(heap.size() - 1);
}


int main() {
	MyHeap<int> h;
	int n;
	while (cin >> n) {
		h.push(n);
	}
	h.print();
	return 0;
}
