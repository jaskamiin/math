#include <stdio.h>
#include <time.h>
#include <math.h>
#include <float.h>
#include "benchmark.h"

typedef double (*func)(double);

//test function: x^5 + 7x^4 - 8x^3 + x^2 - 2
static inline double test(double x){
	return (x*x*x) - (x*x) - (x) - 1;
}

//function to perform bisection method
double bisect(double(*f)(double), double eps, double a, double b){

	//ensure interval is a < b, epsilon > 0 
	//and that a root exists in [a,b] using the intermediate value theorem
	if (b < a){ double temp = a; a = b; b = temp; }
	if (eps <= 0) return 0;
	if (f(a)*f(b) > 0) { printf("Invalid interval - returning\n");  return 0; }

	double c;
	while (1){	
		c = (a + b) / 2;
		if ((b - c)/2 <= eps) break;
		f(b)*f(c) <= 0 ? a = c : b = c;
	}
	return c;
}

double secant_method(double(*f)(double), double a, double b){
	double c;
	for (int i = 0; i < 1000; i++){
		if (f(a) == f(b)) break;
		c = a - f(a) * (a - b) / (f(a) - f(b));
		b = a; a = c;
	}
	return c;
}

//test method with function f(x), e = 10^-20, on [1,2]
int main(){
	func f = &test;
	double start, end, ans;

	start = get_time();
	ans = bisect(f, .000000000000001l, 1, 2);
	end = get_time();

	printf("\nBisection Method : %.*g\n\t(RUNTIME): %e seconds\n", DECIMAL_DIG * 2, ans, end - start);


	start = get_time();
	ans = secant_method(f, 1, 2);
	end = get_time();

	printf("\nSecant Method:\t%.*g\n\t(RUNTIME): %e seconds\n", DECIMAL_DIG * 2, ans, end - start);

	getchar();
	return 0;
}