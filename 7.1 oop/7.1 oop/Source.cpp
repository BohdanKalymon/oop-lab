#include <array>
#include <iostream>

using namespace std;

double avg_even(array<int, 10>& a) {
	double result = 0;
	for (int i = 0; i < 10; i ++) {
		result += a[i%2];
	}
	return result / 5;
}

int main() {
	array<int, 10> a{ {1, 4, 3, 2, 5, 6, 7, 9, 10, 8} };
	cout << "array a: ";
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	};
	cout << endl;
	double avg = avg_even(a);
	cout << "Average of even items: " << avg << endl;

	return 0;
}