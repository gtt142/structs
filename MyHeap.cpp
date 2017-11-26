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
	void deleteMax();

public:
	void push(T);
	T popMax();
	int size() { return heap.size(); };
	
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

template <typename T>
void MyHeap<T>::deleteMax() {
	if (heap.size() > 1) {
		T elem = heap.back();
		heap.pop_back();
		heap[0] = elem;
		siftDown(0);
	}
	else if (heap.size() == 1) {
		heap.pop_back();
	}
}

template <typename T>
T MyHeap<T>::popMax() {
	if (heap.size() > 0) {
		T maxEl = heap[0];
		deleteMax();
		return maxEl;
	}
}


int countSets(MyHeap<int> &basket, int K) {
	if (K <= 0)
		return -1;
	int sets = 0;
	while (basket.size() > 0) {
		int weight = 0;
		vector<int> hand;
		while (weight <= K && basket.size() > 0) {
			int elem = basket.popMax();
			weight += elem;
			if (weight > K) {
				basket.push(elem);
			}
			else {
				int newEl = elem / 2;
				if (newEl > 0)
					hand.push_back(newEl);
			}
		}

		for (vector<int>::iterator it = hand.begin(); it != hand.end(); it++) {
			basket.push(*it);
		}
		sets++;
	}
	return sets;
}

int main() {
	MyHeap<int> basket;
	int K = 0;
	int elCount = 0;
	cin >> elCount;
	for(int i = 0; i < elCount; i++){
		int n;
		cin >> n;
		basket.push(n);
	}
	cin >> K;
	basket.print();
	
	int sets = countSets(basket, K);
	cout << sets << endl;
	return 0;
}
