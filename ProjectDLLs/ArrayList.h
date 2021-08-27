#pragma once

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "List.h"

template<typename T>
class ArrayList : public List<T>
{
public:
	ArrayList();
	ArrayList(const ArrayList<T>& rhs);
	~ArrayList();
	ArrayList& operator=(const ArrayList<T>& rhs);

	void add(const T& item); // add value to the end of the list
	bool add(size_t index, const T& item); // add a value to a particular index 
	bool get(size_t index, T& return_item) const; // retrieve the value of an element 
	bool set(size_t index, const T& new_item); //change the value of an element in the array
	bool remove(size_t index); //remove an element (at the end)
	size_t size() const; //how many elements are in the actual array(not size of array)
	void selection_sort();
	void insertion_sort();
	void merge_sort();
	void quick_sort();
	void sort();

private:
	T* items;
	size_t capacity; // current size of the array holding the elements
	size_t length; // ammount of elements the array is currenty holding

	// helper to resize items array
	void resize();

	//helper functions for the merge and quick sort 
	void merge_sort(size_t start, size_t end);
	void quick_sort(size_t start, size_t end);
};

// constructor creates an array with ten values and a total capacity of ten
template<typename T>
ArrayList<T>::ArrayList()
	: capacity(10), length(0)
{
	items = new T[capacity];
}


template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& rhs)
	: capacity(10), length(0), items(nullptr)
{
	// defer to assignment operator
	*this = rhs;
}


// TODO: Finish the remaining functions below
//this space is for the destructor

template<typename T>
ArrayList<T>::~ArrayList() {
	delete[]items;
}

//operator overloader for = which deepcopies rhs into lhs
template<typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs) {
	if (this != &rhs) {
		delete[]items;
		length = rhs.length;
		capacity = rhs.capacity;
		items = new T[capacity];
		for (int i = 0; i < size(); i++) {
			items[i] = rhs.items[i];
		}

	}
	return *this;
}

//method that appends a value onto the end of the array list, calls resize() if necessary
template<typename T>
void ArrayList<T>::add(const T& item) {
	if (length == capacity) {
		resize();
	}
	items[size()] = item;
	length = length + 1;
}

//method that inserts a value into a given index, calls resize() if necessary
template<typename T>
bool ArrayList<T>::add(size_t index, const T& item) {
	if (index <= size()) {
		if (length == capacity) {
			resize();
		}
		for (int i = size(); i > index; i--) {
			items[i] = items[i - 1];
		}
		items[index] = item;
		length = length + 1;
		return true;
	}
	else { return false; }
}

//method that creates a new array with a larger capacity(10 more spaces) 
//then copies the values from the smaller array into the larger
template<typename T>
void ArrayList<T>::resize() {
	size_t new_cap = capacity * 2;
	T* temp = new T[new_cap];
	for (int i = 0; i < length; ++i) {
		temp[i] = items[i];
	}

	capacity = new_cap;
	delete[]items;
	items = temp;
}

//method that retrives a given value based on a given index
template<typename T>
bool ArrayList<T>::get(size_t index, T& return_item) const {
	if (index < size()) {
		return_item = items[index];
		return true;
	}
	else { return false; }
}

//method that sets a given index within the array to a given value
template<typename T>
bool ArrayList<T>::set(size_t index, const T& new_item) {
	if (index < size()) {
		items[index] = new_item;
		return true;
	}
	else { return false; }
}

//method that removes a given value from the array based on a given index
template<typename T>
bool ArrayList<T>::remove(size_t index) {
	if (index < size()) {
		int i;
		for (i = index; i < size() - 1; i++) {
			items[i] = items[i + 1];
		}
		length = length - 1;
		return true;
	}
	else { return false; }
}

//returns the length of the array
template<typename T>
size_t ArrayList<T>::size() const {
	return this->length;
}

template<typename T>
void ArrayList<T>::selection_sort() {
	if (size() != 0) {
		int smallest_index = 0;
		T temp;
		for (int i = 0; i < size() - 1; ++i) {
			smallest_index = i;
			for (int j = i + 1; j < size(); ++j) {
				if (items[smallest_index] > items[j]) {
					smallest_index = j;
				}
			}
			temp = items[smallest_index];
			items[smallest_index] = items[i];
			items[i] = temp;
		}
	}
}

template<typename T>
void ArrayList<T>::insertion_sort() {
	if (size() != 0) {
		int j;
		T temp;
		for (int i = 0; i < size(); ++i) {
			j = i;
			while (j > 0 && items[j - 1] > items[j]) {
				temp = items[j];
				items[j] = items[j - 1];
				items[j - 1] = temp;
				--j;
			}
		}
	}
}

template<typename T>
void ArrayList<T>::merge_sort() {
	if (size() > 1) {
		merge_sort(0, size() - 1);
	}
}

template<typename T>
void ArrayList<T>::merge_sort(size_t start, size_t end) {
	if (start < end) {
		//partition steps
		int mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);

		//The merge process
		int left_partition_pos = start;
		int right_partition_pos = mid + 1;
		int merge_pos = 0;
		T temp[(end - start) + 1];

		while (left_partition_pos <= mid && right_partition_pos <= end) {
			if (items[left_partition_pos] <= items[right_partition_pos]) {
				temp[merge_pos++] = items[left_partition_pos++];
			}
			else {
				temp[merge_pos++] = items[right_partition_pos++];
			}
		}
		while (left_partition_pos <= mid) {
			temp[merge_pos++] = items[left_partition_pos++];
		}

		while (right_partition_pos <= end) {
			temp[merge_pos++] = items[right_partition_pos++];
		}
		for (int i = 0; i < (end - start) + 1; ++i) {
			items[start + i] = temp[i];
		}
	}

}

template<typename T>
void ArrayList<T>::quick_sort() {
	if (size() > 1) {
		quick_sort(0, size() - 1);
	}
}

template<typename T>
void ArrayList<T>::quick_sort(size_t start, size_t end) {
	//base case
	if (start >= end) {
		return;
	}
	//partition steps
	T temp;
	int right_side_pos = end; //h
	int left_side_pos = start; //l
	bool finish = false;

	int mid = start + (end - start) / 2;
	T pivot = items[mid];
	while (!finish) {
		while (items[left_side_pos] < pivot) {
			++left_side_pos;
		}
		while (pivot < items[right_side_pos]) {
			--right_side_pos;
		}
		if (left_side_pos >= right_side_pos) {
			finish = true;
		}
		else {
			temp = items[left_side_pos];
			items[left_side_pos] = items[right_side_pos];
			items[right_side_pos] = temp;

			++left_side_pos;
			--right_side_pos;
		}
	}
	//recursion steps
	quick_sort(start, right_side_pos);
	quick_sort(right_side_pos + 1, end);
}

template<typename T>
void ArrayList<T>::sort() {
	quick_sort();
}
#endif