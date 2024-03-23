
#include <iostream>
#include <vector>
#include "BinarySearch.hpp"
#include <string>



class Set {
protected:
	std::string* array;
	size_t current_size;
	size_t capacity;
	void resize(const size_t new_capacity) {
		auto* new_array = new std::string[new_capacity];
		for (size_t i = 0; i < capacity; ++i) {
			new_array[i] = array[i];
		}
		capacity = new_capacity;
		delete[] array;
		array = new_array;
	}

public:
	explicit Set(size_t initial_size) : array(new std::string[initial_size]{}), capacity(initial_size), current_size(0) {}

	~Set() {
		delete[] array;
	}
	void insert(const std::string& string) {

		if (current_size >= capacity) {
			resize(current_size*2);
		}

		if (is_member(string)) { return; };

		size_t index = binary_search(array, current_size, string);

		if (index < current_size) {
			for (size_t i = current_size; i > index; i--)
			{

				array[i] = array[i-1];
			}
			array[index] = string;
		}
		else {
			array[index] = string;
		}
		current_size++;
	}

	bool is_member(const std::string& element) const{
		size_t index = binary_search(array, current_size, element);
		if (array[index] == element)return true;
		return false;
	}

	void remove(const std::string& element) {
		size_t index = binary_search(array, current_size, element);
		if (array[index] == element) {
			for (size_t i = index; i < current_size; i++)
			{
				array[i] = array[i + 1];
			}
			current_size--;
		}
	}

	size_t size() {
		return current_size;
	}

	Set intersect(Set& set) {
		Set intersection(std::min(set.size(), current_size));
		int i = 0;
		int j = 0;
		int k = 0;
		const std::string* other_array = set.array;
		const size_t other_size = set.size();
		while (i < current_size && j < other_size) {
			if (array[i] < other_array[j]) {
				++i;
			}
			else if (other_array[j] < array[i]) {
				++j;
			}
			else {  // Elements are equal
				intersection.array[k] = other_array[j];
				++intersection.current_size;
				++i;
				++j;
				++k;
			}
		}

		return intersection;
	}
	Set sum(Set& other) {
		const size_t other_size = other.current_size;

		Set sum(other_size+ current_size);

		int i = 0, j = 0, k = 0;
		const std::string* other_array = other.array;
		while (i < current_size && j < other_size) {
			if (i > 0 && array[i - 1] == array[i]) { 
				++i;  
				continue; 
			} 

			if (j > 0 && other_array[j - 1] == other_array[j]) { 
				++j;  
				continue; 
			}

			if (array[i] < other_array[j]) {
				sum.array[k++] = array[i++];
				++sum.current_size;
			} else if (other_array[j] < array[i]) {
				sum.array[k++] = other_array[j++];
				++sum.current_size;
			} else { 
				sum.array[k++] = array[i];
				++sum.current_size;
				++i;
				++j;
			}
		}

		// Add remaining elements
		while (i < current_size) { 
			if (i == 0 || array[i] != array[i - 1]) {
				sum.array[k++] = array[i];
				++sum.current_size;
			}
			++i; 
		}

		while (j < other_size) { 
			if (j == 0 || other_array[j] != other_array[j - 1]) {
				sum.array[k++] = other_array[j];
				++sum.current_size;
			}
			++j; 
		}
		return sum;
	}
	Set difference(Set other) {

		const size_t other_size = other.current_size;

		Set difference(std::max(other_size, current_size));

		int i = 0, j = 0, k = 0;
		const std::string* other_array = other.array;
		
		while (i < current_size && j < other_size) {
			if (array[i] < other_array[j]) {
				difference.array[k++] = array[i++];
				++difference.current_size;
			} else if (other_array[j] < array[i]) {
				++j; 
			} else { 
				++i;  
				++j; 
			}
		}

		// Add remaining elements of array
		while (i < current_size) { 
			difference.array[k++] = array[i++];
			++difference.current_size;
		}
		return difference;
	}
	const std::string* get_array() {
		return this->array;
	}

	void print()const  {
		for (size_t i = 0; i < current_size; i++)
		{
			std::cout << array[i]<<std::endl;
		}
	}
};