#ifndef ARRAY_H
#define ARRAY_H

namespace Array {
	// choose between random filling or on your own
	int *create_wizard(int &n);

	// print an array `tab`
	void printa(int tab[], int n);

	// count the occurences of `k` value in array
	int count_of_val(int tab[], int k, int n);

	// return minimum
	int min(int tab[], int n);

	// return the last occur of minimal value
	int where_min(int tab[], int n);

	// return an array filled with indexes of `tab` where `k` value occur
	int *indexes_of(int tab[], int k, int occurences, int n);

	// optimized version returning indexes of minimal value in array
	int *test_indexes_of_minimal(int tab[], int n);

	// nothing to add
	int sum_even_values(int tab[], int n);

	// the same comm
	int sum_even_indexes(int tab[], int n);

	// sumaraize values in `tab`
	int sum(int tab[], int n);

	// check if `k` is an element of `tab`
	bool contains(int tab[], int k, int n);

	// move first element to the end of `tab`
	void shift_to_end(int *tab, int n);

	// move element at `k` index to the end of `tab`
	void shift_index_to_end(int tab[], int k, int n);

	// return indexes of `k` in `tab`. Higher memory usage
	int *indexes_ofFast(int tab[], int k, int n);

	// return indexes of `k` in `tab`. Lesser memory usage
	int *indexes_ofLight(int tab[], int k, int &count, int n);

	// like the name saying
	void reverse_in_place(int tab[], int n);

	// non in situ version
	int *reverse_non_in_place(int tab[], int n);

	// copy an entire array
	int *copy(int *tab, int n);

	//////////////////////////////////////
	////// Sorting algorithms ////////////
	//////////////////////////////////////

	int *bubble_sort(int tab[], int n);

	int *bubble_sort_with_warden(int tab[], int n);

	int *selection_sort(int tab[], int n);

	int *sort_non_in_situ(int *tab, int n);

	int *insertion_sort_1(int tab[], int n);

	int *insertion_sort_2(int tab[], int n);

	int *insertion_sort_reversed(int tab[], int n);

}


#endif // ARRAY_H
