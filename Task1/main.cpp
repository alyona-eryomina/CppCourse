#include <iostream>
#include <vector>
#include <stdlib.h>
#include "curve.h"

int main() {
	std::vector<Curve*> vector;
	int n = 10; // number of curves

	// Generation curves vector
	for (int i = 0; i < n; i++) {
		int temp = rand();
		if (temp % 2) {
			Circle *a = new Circle((float)(temp % 100 / 3 + 1));
			vector.push_back(static_cast<Curve*>(a));
		}
		else {
			Ellipse *a = new Ellipse((float)(temp % 100 / 3 + 1), (float)(temp % 100 / 7 + 1));
			vector.push_back(static_cast<Curve*>(a));
		}
	}

	// Sort ascending areas
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (vector[j]->get_area() > vector[j + 1]->get_area()) {
				Curve* temp = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = temp;
			}
		}
	}

	// Summation of areas
	float sum_area = 0.0f;
	for (int i = 0; i < n; i++) {
		sum_area += vector[i]->get_area();
	}

	return 0;
}