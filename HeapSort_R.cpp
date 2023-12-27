#include <queue>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
using namespace std;




struct BinaryHeap {
	vector<int>BinaryHeap;


	void BinaryPush(const int& enemy) {
		BinaryHeap.push_back(enemy);
		SiftUp(BinaryHeap.size() - 1);
	}
	void SiftUp(int index) {

		for (int i = index; i > 0; i = (i - 1) / 2) {
			if (BinaryHeap[(i - 1) / 2] < BinaryHeap[i]) {
				swap(BinaryHeap[(i - 1) / 2], BinaryHeap[i]);
			}
			else {
				return;
			}
		}
	}
	void SiftDown(int index) {
		int leftChildIndex = getLeftChild(index);
		int rightChildIndex = getRightChild(index);

		if (leftChildIndex == -1) {
			return;
		}

		int maxChildIndex = leftChildIndex;

		if (rightChildIndex != -1 && BinaryHeap[leftChildIndex] < BinaryHeap[rightChildIndex]) {
			maxChildIndex = rightChildIndex;
		}

		if (BinaryHeap[maxChildIndex] < BinaryHeap[index] || BinaryHeap[maxChildIndex] == BinaryHeap[index]) {
			return;
		}

		swap(BinaryHeap[maxChildIndex], BinaryHeap[index]);
		SiftDown(maxChildIndex);
	}

	int getParent(int index) {
		return (index - 1) / 2;
	}

	int getLeftChild(int index) {
		int t = (2 * index) + 1;
		if (t <= BinaryHeap.size() - 1)
		{
			return t;
		}
		else
		{
			return -1;
		}
	}

	int getRightChild(int index) {
		int t = (2 * index) + 2;
		if (t <= BinaryHeap.size() - 1)
		{
			return t;
		}
		else
		{
			return -1;
		}
	}

	void print() {
		for (int i = 0; i < BinaryHeap.size(); i++) {
			cout << BinaryHeap[i] << endl;
		}
	}

	int size() {
		return BinaryHeap.size();
	}
};


struct PriorityQueue
{
	BinaryHeap queue;

	void push(const int& enemy)
	{
		queue.BinaryHeap.push_back(enemy);
		queue.SiftUp(queue.BinaryHeap.size() - 1);
	}

	int top()
	{
		return queue.BinaryHeap[0];
	}

	void pop() {
		if (queue.BinaryHeap.size() == 0) {
			cout << "No elements" << endl;
			return;
		}
		swap(queue.BinaryHeap[0], queue.BinaryHeap[queue.BinaryHeap.size() - 1]);
		queue.BinaryHeap.pop_back();
		queue.SiftDown(0);
	}

	int size()
	{
		return queue.BinaryHeap.size();
	}

	bool empty()
	{
		if (queue.BinaryHeap.size() == 0)
		{
			return true;
		}
		return false;
	}

	void clean()
	{
		queue.BinaryHeap.clear();
	}
};


struct HeapSort
{
	vector<int>Sort;

	void buildHeap(int* array, int arraySize) {
		for (int i = 0; i < arraySize; i++) {

			Sort.push_back(array[i]);
		}
		int i = arraySize - 1;
		while (i != -1) {

			if (getLeftChild(i) != -1) {
				SiftDown(i);
			}
			i--;
		}
	}

	void pop() {
		if (Sort.size() == 0) {
			cout << "No elements" << endl;
			return;
		}
		swap(Sort[0], Sort[Sort.size() - 1]);
		Sort.pop_back();
		if (!Sort.empty()) {
			SiftDown(0);
		}
	}

	void heapSort(int* array, int arraySize) {
		buildHeap(array, arraySize);
		for (int i = 0; i < arraySize; i++) {
			array[i] = Sort[0];
			pop();
		}
		for (int i = arraySize-1; i>=0; i--) {
			cout << array[i] << " ";
		}
	}

	void SiftDown(int index) {

		int leftChildIndex = getLeftChild(index);
		int rightChildIndex = getRightChild(index);

		if (leftChildIndex == -1) {
			return;
		}

		int maxChildIndex = leftChildIndex;

		if (rightChildIndex != -1 && Sort[leftChildIndex] < Sort[rightChildIndex]) {
			maxChildIndex = rightChildIndex;
		}

		if (Sort[maxChildIndex] < Sort[index] || Sort[maxChildIndex] == Sort[index]) {
			return;
		}

		swap(Sort[maxChildIndex], Sort[index]);
		SiftDown(maxChildIndex);
	}


	void SiftUp(int index) {

		for (int i = index; i > 0; i = (i - 1) / 2) {
			if (Sort[(i - 1) / 2] < Sort[i]) {
				swap(Sort[(i - 1) / 2], Sort[i]);
			}
			else {
				return;
			}
		}
	}

	void print() {
		for (int i = 0; i < Sort.size(); i++) {
			cout << Sort[i] << endl;
		}
	}


	int getParent(int index) {
		return (index - 1) / 2;
	}

	int getLeftChild(int index) {
		int t = (2 * index) + 1;
		if (t <= Sort.size() - 1)
		{
			return t;
		}
		else
		{
			return -1;
		}
	}

	int getRightChild(int index) {
		int t = (2 * index) + 2;
		if (t <= Sort.size() - 1)
		{
			return t;
		}
		else
		{
			return -1;
		}
	}
};

int main()
{
	srand(time(NULL));
	int a[1000];
	int b[1000];
	HeapSort Sort;

	cout << "START: " << endl;
	for (int i = 0; i < 1000; i++) {
		a[i] = rand() % 100;
		b[i] = a[i];
		cout << a[i] << " ";
	}


	cout << endl;
	cout << endl;
	cout << "HEAPSORT: " << endl;

	clock_t myStart = clock();
	Sort.heapSort(a, 1000);
	clock_t myEnd = clock();

	cout << endl;
	float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;
	cout << "Time of work: " << myTime << endl;
	cout << endl;


	int n = sizeof(b) / sizeof(b[0]);

	clock_t myStart1 = clock();
	sort(b, b + n);
	clock_t myEnd1 = clock();

	float myTime1 = (float(myEnd1 - myStart1)) / CLOCKS_PER_SEC;
	cout << "STL sort: " << endl;

	for (int i = n - 1; i >= 0; i--) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Time of work: " << myTime1 << endl;

}




