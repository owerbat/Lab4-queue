#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class TQueue {
	int first;
	int last;
	int size;
	int maxsize;
	T* ring;
public:
	TQueue(int _maxsize = 10) {
		if (_maxsize <= 0) {
			char *str = "Queue's maxsize must be a positive number";
			throw str;
		}
		maxsize = _maxsize;
		ring = new T[maxsize];
		first = 0;
		last = -1;
		size = 0;
	}

	TQueue(const TQueue& q) {
		maxsize = q.maxsize;
		ring = new T[maxsize];
		first = q.first;
		last = q.last;
		size = q.size;
		for (int i = 0; i < maxsize; i++) {
			ring[i] = q.ring[i];
		}
	}

	~TQueue() {
		delete[] ring;
	}

	int isempty() {
		if (size == 0)
			return 1;
		return 0;
	}

	int isfull() {
		if (size == maxsize)
			return 1;
		return 0;
	}

	void push(const T elem) {
		if (isfull()) {
			char *str = "The queue is full, you can't add a new element";
			throw str;
		}
		last = (last + 1) % maxsize;
		ring[last] = elem;
		size++;
	}

	T pop() {
		if (isempty()) {
			char *str = "The queue is empty, you can't delete an element";
			throw str;
		}
		int tmp = first;
		first = (first + 1) % maxsize;
		size--;
		return ring[tmp];
	}

	T getLastElem() {
		return ring[last];
	}

	int getFirst() {
		return first;
	}

	int getSize() {
		return size;
	}

	int getMaxsize() {
		return maxsize;
	}

	T top() {
		if (isempty()) {
			char *str = "The queue is empty, you can't get the top";
			throw str;
		}
		return ring[first];
	}

	int getLast(){
		return last;
	}

	int operator==(const TQueue& q) const {
		if ((maxsize != q.maxsize) || (size != q.size) || (first != q.first) || (last != q.last))
			return 0;
		for (int i = first; i < last; i++) {
			if (ring[i] != q.ring[i])
				return 0;
		}
		return 1;
	}

	int operator!=(const TQueue& q) const {
		return !(*this == q);
	}
};