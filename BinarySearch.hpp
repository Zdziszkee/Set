



inline size_t binary_search(const std::string* array, const size_t array_size, const std::string& element) {
	int left_bound = 0;
	int right_bound = array_size - 1;

	while (left_bound <= right_bound) {
		int mid = left_bound + (right_bound - left_bound) / 2;
		int comparisonResult = array[mid].compare(element);

		if (comparisonResult == 0) {
			return mid;
		}
		 if (comparisonResult < 0) {
			left_bound = mid + 1;
		}else {
			right_bound = mid - 1;
		}
	}
	return left_bound;
}