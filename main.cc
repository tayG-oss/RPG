//Fill out this comment with your names and which bullet points you did
//Partners:
//Bullet Points:
//Extra Credit:
//URL to cover art and music:
#include "/public/read.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

double f(double x) {
	return x * x * x * x;
}

double leftriemannSum(int a, int b, int numRectangles) {

	double rectangleWidth = (b - a) / numRectangles;
	double sum = 0;

	for (int i = 0; i < numRectangles; i++) {
		double xi = a + i * rectangleWidth;
		sum += f(xi) * rectangleWidth;
	}

	return sum;
}


int main() {
	int lowerBound = 1;
	int upperBound = 6;
	int numRectangles = 5;
	int answer = 0;

	double result;

	result = leftriemannSum(lowerBound, upperBound, numRectangles); // Answer is 979 for future reference.

	cout << "Using Left Riemann Sum, integrate x^4 from 1 to 6 with 5 rectangles" << endl;

	int count = 0;

	/*
	   No clue if an attempt limit will be added in future development, only added here for testing purposes


	*/

	while (count != 3) {
		cout << "Enter answer: ";
		cin >> answer;
		if (result == answer) {
			cout << "Yippee you did it :DD" << endl;
			return 0;
		} else {
			cout << "womp womp :(, try again" << endl;
		}

		count++;
	}

	if (count == 3) {
		cout << "You failed, try again" << endl;
	}

}
