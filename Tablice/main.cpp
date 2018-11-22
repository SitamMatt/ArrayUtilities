#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Array.h"
using namespace std;

int main() {
	srand(time(0));
//	setlocale(LC_ALL, "");
	int n = 0;
	int *tab = Array::create_wizard(n);
	
	int minimum = Array::min(tab, n);
	cout << "Najmniejsza warto�� w ci�gu to: " << minimum << endl;

	int count_of_minimal = Array::count_of_val(tab, minimum, n);
	cout << "Warto�� `" << minimum << "` wyst�puje w ci�gu " << count_of_minimal << " razy\n";

	int *indexes_of_minimal = Array::indexes_of(tab, minimum, count_of_minimal, n);
	cout << "Indeksy warto�ci minimalnej: \n";
	Array::printa(indexes_of_minimal, count_of_minimal);

	int even_sum = Array::sum_even_values(tab, n);
	cout << "Suma wyraz�w parzystych wynosi: " << even_sum << endl;

	int even_indexes_sum = Array::sum_even_indexes(tab, n);
	cout << "Suma wraz�w o indeksach parzystych wynosi: " << even_indexes_sum << endl;

	int sum = Array::sum(tab, n);
	cout << "Suma ci�gu wynosi: " << sum << endl;

	bool is = Array::contains(tab, 10, n);
	if (is) cout << "10 jest elementem tego ci�gu\n";
	else cout << "10 nie jest elementem tego ci�gu\n";

	Array::shift_to_end(tab, n);
	Array::printa(tab, n);
	cout << endl;

	Array::shift_index_to_end(tab, 5, n);
	Array::printa(tab, n);
	cout << endl;

	int min_index = Array::where_min(tab, n);
	cout << "Najmniejszy wyraz ci�gu znajduje si� na " << min_index << " miejcu\n";

	int *indexes_1 = Array::indexes_ofFast(tab, 5, n);
	int l=0;
	int *indexes_2 = Array::indexes_ofLight(tab, 5, l, n);
	cout << "indeksy liczby 5 spos�b pierwszy:\n";
	Array::printa(indexes_1, n);
	cout << "spos�b drugi:\n";
	Array::printa(indexes_2, l);

	Array::reverse_in_place(tab, n);
	Array::printa(tab, n);

	int *reversed_2 = Array::reverse_non_in_place(tab, n);
	Array::printa(reversed_2, n);

	int *unsorted_1 = Array::copy(tab, n);
	int *sorted_1 = Array::bubble_sort(unsorted_1, n);
	Array::printa(sorted_1, n);

	int *unsorted_2 = Array::copy(tab, n);
	int *sorted_2 = Array::bubble_sort_with_warden(unsorted_2, n);
	Array::printa(sorted_2, n);

	int *unsorted_3 = Array::copy(tab, n);
	int *sorted_3 = Array::selection_sort(unsorted_3, n);
	Array::printa(sorted_3, n);

	int *sorted_4 = Array::sort_non_in_situ(tab, n);
	Array::printa(sorted_4, n);
	Array::printa(tab, n);

	int *unsorted_5 = Array::copy(tab, n);
	int *sorted_5 = Array::insertion_sort_1(unsorted_5, n);
	Array::printa(sorted_5, n);

	int *unsorted_6 = Array::copy(tab, n);
	int *sorted_6 = Array::insertion_sort_2(unsorted_6, n);
	Array::printa(sorted_6, n);

	int *unsorted_7 = Array::copy(tab, n);
	int *sorted_7 = Array::insertion_sort_reversed(unsorted_7, n);
	Array::printa(sorted_7, n);

	cout << endl;
	system("pause");
	return 0;
}