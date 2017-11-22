#pragma once

#include <iostream>

using namespace std;

typedef unsigned int uint;

template <class T>
class TQueue {
	uint first;
	uint last;
	uint size;
	uint maxsize;
	T* ring;
public:
	TQueue(uint _maxsize = 10) {
		maxsize = _maxsize;
		ring = new T[maxsize];
		first = 0;
		last = -1;
		size = 0;
	}

	TQueue(const TQueue& q) {
		if (maxsize != q.maxsize) {
			q.maxsize = maxsize;
			delete[] q.ring;
			q.ring = new T[q.maxsize];
		}
		q.first = first;
		q.last = last;
		q.size = size;
		for (uint i = first; i <= last; i++) {
			q.ring[i] = ring[i];
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
};