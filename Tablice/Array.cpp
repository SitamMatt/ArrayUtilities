#include <iostream>
#include "Array.h"

namespace Array {
	using namespace std;
	int *create_wizard(int &n) {
		// wprowadzanie d³ugoœci tablicy `tab`
		cout << "WprowadŸ liczbê n(iloœæ elementów tablicy): ";
		cin >> n;

		// sprawdzanie czy `n` jest dodatnie
		if (n <= 0) {
			cout << "Wartoœæ nie jest dodatnia!";
			return 0;
		}

		int *tab = new int[n];
		// wype³nianie tablicy `tab`
		int decyzja = -1;

		// blok podejmuj¹cy decyzjê na podstawie `decyzja`
		while (decyzja != 0 && decyzja != 1) {
			cout << "Je¿eli chcesz samodzielnie wprowadziæ elementy tablicy wprowadŸ `0` w przeciwnym wypadku wprowadŸ `1` by zosta³y wprowadzone w sposób losowy: ";
			cin >> decyzja;
			if (decyzja == 0) {

				// petla do wype³niania tablicy przez u¿ytkownika
				for (int i = 0; i < n; ++i) {
					cout << "WprowadŸ wartoœc elementu tablicy o indeksie " << i << ": ";
					cin >> tab[i];
				}
			}
			else if (decyzja == 1) {

				// pêtla wype³niaj¹ca tablicê losowymi liczbami
				cout << "[ ";
				for (int i = 0; i < n; ++i) {
					// tab[i] = rand() % RAND_MAX; dla bardzo losowych liczb
					tab[i] = rand() % 20;
					cout << tab[i];
					if (i + 1 < n) {
						cout << ", ";
					}
				}
				cout << " ]" << endl;
			}
		}
		return tab;
	}

	void printa(int tab[], int n) {
		// pêtla wype³niaj¹ca tablicê losowymi liczbami
		cout << "[ ";
		for (int i = 0; i < n; ++i) {
			cout << tab[i];
			if (i + 1 < n) {
				cout << ", ";
			}
		}
		cout << " ]" << endl;
	}

	int count_of_val(int tab[], int k, int n) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (tab[i] == k) count++;
		}
		return count;
	}

	int min(int tab[], int n) {
		int min = tab[0];
		for (int i = 1; i < n; i++) {
			if (min > tab[i]) min = tab[i];
		}
		return min;
	}

	int where_min(int tab[], int n) {
		int i_min = 0;
		for (int i = 1; i < n; i++) {
			if (tab[i_min] > tab[i]) i_min = i;
		}
		return i_min;
	}

	int *indexes_of(int tab[], int k, int occurences, int n) {
		int *indexes = new int[occurences];
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (tab[i] == k) {
				indexes[j] = i;
				j++;
			}
		}
		return indexes;
	}

	int *test_indexes_of_minimal(int tab[], int n) {
		int min = tab[0];
		int count = 1;
		int min_index = 0;
		int max_index = 0;
		for (int i = 1; i < n; i++) {
			if (min > tab[i]) {
				min = tab[i];
				min_index = i;
				max_index = i;
				count = 1;
			}
			else if (min == tab[i]) {
				count++;
				max_index = i;
			}
		}
		int *indexes = new int[count];
		indexes[0] = min_index;
		int l = 1;
		for (int j = min_index + 1; j < max_index + 1; ++j) {
			if (tab[j] == min) {
				indexes[l] = j;
				l++;
			}
		}
		return indexes;
	}

	int sum_even_values(int tab[], int n) {
		int suma = 0;
		for (int i = 0; i < n; i++) {
			if (tab[i] % 2 == 0) suma += tab[i];
		}
		return suma;
	}

	int sum_even_indexes(int tab[], int n) {
		int suma = 0;
		for (int i = 0; i < n; i += 2) {
			suma += tab[i];
		}
		return suma;
	}

	int sum(int tab[], int n) {
		int i = 0;
		int suma = 0;
		while (i < n) {
			suma += tab[i];
			i++;
		}
		return suma;
	}

	bool contains(int tab[], int k, int n) {
		for (int i = 0; i < n; i++) {
			if (tab[i] == k) return true;
		}
		return false;
	}

	void shift_to_end(int *tab, int n) {
		int bufor;
		for (int i = 0; i < n - 1; i++) {
			bufor = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = bufor;
		}
	}

	void shift_index_to_end(int tab[], int k, int n) {
		int bufor;
		for (int i = k; i < n - 1; ++i) {
			bufor = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = bufor;
		}
	}

	int *indexes_ofFast(int tab[], int k, int n) {
		int *indexes = new int[n];
		for (int i = 0, j = 0; i < n; i++) {
			if (tab[i] == k) indexes[j++] = i;
		}
		return indexes;
	}

	int *indexes_ofLight(int tab[], int k, int &count, int n) {
		for (int i = 0; i < n; i++) {
			if (tab[i] == k) count++;
		}
		int *indexes = new int[count];
		for (int i = 0, j = 0; i < n && j < count; i++) {
			if (tab[i] == k) indexes[j++] = i;
		}
		return indexes;
	}

	void reverse_in_place(int tab[], int n) {
		for (int i = 0; i < n / 2; i++) {
			int bufor = tab[i];
			tab[i] = tab[n - i - 1];
			tab[n - i - 1] = bufor;
		}
	}

	int *reverse_non_in_place(int tab[], int n) {
		int *reversedTab = new int[n];
		for (int i = n - 1; i >= 0; i--) {
			reversedTab[n - i - 1] = tab[i];
		}
		return reversedTab;
	}

	int *copy(int *tab, int n) {
		int *copy = new int[n];
		for (int i = 0; i < n; i++)
		{
			copy[i] = tab[i];
		}
		return copy;
	}

	int *bubble_sort(int tab[], int n) {
		int temp = 0;
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < n - i - 1; ++j) {
				if (tab[j] > tab[j + 1]) {
					temp = tab[j];
					tab[j] = tab[j + 1];
					tab[j + 1] = temp;
				}
			}
		}
		return tab;
	}

	int *bubble_sort_with_warden(int tab[], int n) {
		bool warden = true;
		int temp = 0;
		for (int i = 0; i < n - 1 && warden; ++i) {
			warden = true;
			for (int j = 0; j < n - i - 1; ++j) {
				if (tab[j] > tab[j + 1]) {
					temp = tab[j];
					tab[j] = tab[j + 1];
					tab[j + 1] = temp;
					warden = true;
				}
			}
		}
		return tab;
	}

	int *selection_sort(int tab[], int n) {
		int i_min = 0;
		int temp = 0;
		for (int i = 0; i < n - 1; i++) {
			i_min = i;
			for (int j = i + 1; j < n; j++) {
				if (tab[i_min] > tab[j]) i_min = j;
			}

			temp = tab[i];
			tab[i] = tab[i_min];
			tab[i_min] = temp;
		}
		return tab;
	}

	// sort non in situ utility
	int check(int *indexes, int n) {
		for (int i = 0; i < n; i++) {
			if (indexes[i] <= 0) {
				return i;
			}
		}
	}

	int *sort_non_in_situ(int *tab, int n) {
		int *indexes = new int[n];
		int *sorted = new int[n];
		int min;
		for (int k = 0; k < n; ++k) {
			min = check(indexes, n);
			for (int i = 0; i < n; i++) {
				if (indexes[i] == 5) continue;
				if (tab[min] > tab[i]) {
					min = i;
				}
			}
			indexes[min] = 5;
			sorted[k] = tab[min];
		}
		return sorted;
	}

	int *insertion_sort_1(int tab[], int n) {
		int temp;
		for (int i = 1; i < n; i++) {
			temp = tab[i];
			for (int j = i - 1; j >= 0 && temp < tab[j]; j--) {
				tab[j + 1] = tab[j];
				tab[j] = temp;
			}
		}
		return tab;
	}

	int *insertion_sort_2(int tab[], int n) {
		int j, temp;
		for (int i = 1; i < n; i++) {
			temp = tab[i];
			j = i - 1;
			while (temp < tab[j] && j >= 0) {
				tab[j + 1] = tab[j];
				j--;
			}
			tab[j + 1] = temp;
		}
		return tab;
	}

	int *insertion_sort_reversed(int tab[], int n) {
		int temp;
		for (int i = n - 2; i >= 0; i--) {
			temp = tab[i];
			int j = i + 1;
			while (temp > tab[j] && j < n) {
				tab[j - 1] = tab[j];
				j++;
			}
			tab[j - 1] = temp;
		}
		return tab;
	}
}




