#pragma once

#ifndef ARRAY_LIST_COLLECTION_H
#define ARRAY_LIST_COLLECTION_H

#include "collection.h"
#include "ArrayList.h"

template<typename K, typename V>
class ArrayListCollection : public Collection<K, V>
{
public:
	~ArrayListCollection() {};
	void add(const K& a_key, const V& a_val);
	void remove(const K& a_key);
	bool find(const K& search_key, V& the_val) const;
	void find(const K& k1, const K& k2, ArrayList<K>& keys) const;
	void keys(ArrayList<K>& all_keys) const;
	void sort(ArrayList<K>& all_keys_sorted) const;
	size_t size() const;

private:
	//initialize the Arraylist for the collection
	ArrayList<std::pair<K, V>> kv_list;
};

template<typename K, typename V>
void ArrayListCollection<K, V>::add(const K& a_key, const V& a_val) {
	//calls the add function in array_list.h
	std::pair<K, V> new_pair(a_key, a_val);
	kv_list.add(new_pair);
}

template<typename K, typename V>
void ArrayListCollection<K, V>::remove(const K& a_key) {
	V removed_val;
	bool found = false, moved_to = false;
	size_t index = 0;
	std::pair<K, V> curr_pair;

	//determines whether value is in the list or not
	found = find(a_key, removed_val);

	if (found == true) {
		//starts from beginning and searches for value to be removed
		kv_list.get(index, curr_pair);
		while (removed_val != curr_pair.second) {
			index = index + 1;
			kv_list.get(index, curr_pair);
		}
		kv_list.remove(index);

	}
}

template<typename K, typename V>
bool ArrayListCollection<K, V>::find(const K& search_key, V& the_val) const {
	std::pair<K, V> curr_pair;

	for (int i = 0; i < kv_list.size(); ++i) {
		kv_list.get(i, curr_pair);
		if (search_key == curr_pair.first) {
			the_val = curr_pair.second;
			return true;
		}
	}

	return false;
}

template<typename K, typename V>
void ArrayListCollection<K, V>::find(const K& k1, const K& k2, ArrayList<K>& keys) const {
	std::pair<K, V> curr_pair;

	//runs through the list and finds all keys that fit within the range and adds them to keys
	for (int i = 0; i < kv_list.size(); ++i) {
		kv_list.get(i, curr_pair);
		if (curr_pair.first >= k1 && curr_pair.first <= k2) {
			keys.add(curr_pair.first);
		}
	}
}

template<typename K, typename V>
void ArrayListCollection<K, V>::keys(ArrayList<K>& all_keys) const {
	std::pair<K, V> new_pair;
	for (int i = 0; i < kv_list.size(); ++i) {
		kv_list.get(i, new_pair);
		all_keys.add(new_pair.first);
	}
}

template<typename K, typename V>
void ArrayListCollection<K, V>::sort(ArrayList<K>& all_keys_sorted) const {
	ArrayList<K> unsorted_keys;
	keys(unsorted_keys);
	unsorted_keys.ArrayList<K>::sort();
	all_keys_sorted = unsorted_keys;

}

template<typename K, typename V>
size_t ArrayListCollection<K, V>::size() const {
	// a key can only represent one value so counting the # of keys will give you the size of kv_list
	ArrayList<K> all_keys;
	keys(all_keys);

	//returns call to ArrayList size() function
	return all_keys.size();
}

#endif