#include <stdio.h>
#include <time.h>
#include <float.h>
#include <benchmark.h>

typedef double (*func)(double);

//test function: x^5 + 7x^4 - 8x^3 + x^2 - 2
double test(double x){
	return (x*x*x) + (4*x) - 10;
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

//test method with function f(x), eps = 10^-20, on [1,2]
int main(){
	func f = &test;
	double start, end, ans;

	start = get_time();
	ans = bisect(f, .00000000000000000000001l, 1, 2);
	end = get_time();

	printf("The root is %.*g and took %e seconds", DECIMAL_DIG*2, ans, end-start);
	
    getchar();
	return 0;
}