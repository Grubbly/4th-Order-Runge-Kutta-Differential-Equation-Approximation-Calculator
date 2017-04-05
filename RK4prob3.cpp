/*
Tristan Van Cise
2/18/2017
Differential Equations
Homework 13
This code calculates the approximate solutions to a given differential equation
by using the 4th order Runge-Kutta method. These approximations are sent to a .txt
file titled "RK4results.txt" so they can be put into a spreadsheet later.
*/

/***  Exercises 9.4 - Problem 3: y' = 1 + y^2, y(0) = 2, y(0.5)  ***/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::ofstream;
using std::pow;
using std::setprecision;

double k1(double xn, double yn, double h) {
	return h*(1 + pow(yn,2));
}

double k2(double xn, double yn, double h, double k1) {
	return h*(1 + pow((yn + 0.5*k1),2));
}

double k3(double xn, double yn, double h, double k2) {
	return h*(1 + pow((yn + 0.5*k2),2));
}

double k4(double xn, double yn, double h, double k3) {
	return h*(1 + pow((yn + k3),2));
}

int main()
{
	ofstream outfile("RK4resultsp2.txt", std::ofstream::out);

	double xn = 0, yn = 0, h = 0.1; //initial values
	outfile << setprecision(4) << yn << ", " << xn << endl; //set precision to 4 decimal places
	double calculatedK1 = k1(xn, yn, h);
	double calculatedK2 = k2(xn, yn, h, calculatedK1);
	double calculatedK3 = k3(xn, yn, h, calculatedK2);
	double calculatedK4 = k4(xn, yn, h, calculatedK3);
	double ynext = yn + (1.0 / 6.0)*(calculatedK1 + 2 * calculatedK2 + 2 * calculatedK3 + calculatedK4);
	xn += h;
	outfile << setprecision(4) << ynext << ", " << xn << endl; //set precision to 4 decimal places

	for (double i = 0; i < 0.5; i += 0.1) {
		yn = ynext;
		calculatedK1 = k1(xn, yn, h);
		calculatedK2 = k2(xn, yn, h, calculatedK1);
		calculatedK3 = k3(xn, yn, h, calculatedK2);
		calculatedK4 = k4(xn, yn, h, calculatedK3);
		ynext = yn + (1.0 / 6.0)*(calculatedK1 + 2 * calculatedK2 + 2 * calculatedK3 + calculatedK4);
		xn += h;
		outfile << setprecision(4) << ynext << ", " << xn << endl; //set precision to 4 decimal places

	}

	cout << "File Write Complete" << endl;

	return 0;
}