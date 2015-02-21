#include <stdio.h>
#include <benchmark.h>

typedef float (*func)(float);

//test function: x^3 - x^2 - x - 2
float test(float x){
	return (x*x*x) - (x*x) - x - 2;
}

//function to perform bisection method
float bisect(float(*f)(float), float e, float a, float b){
	//use intermediate value theorem to check 
	//if a root exists in interval [a,b]
	if (f(a)*f(b) > 0) { printf("Invalid interval - returning\n");  return 0; }

	float c;
	while (1){
		c = (a + b) / 2;
		if ((b-c)/c<=e) break;
		f(b)*f(c) <= 0 ? a = c : b = c;
	}
	return c;
}

//test method with function f(x), e = 10^-6, on [1,2]
int main(){
	func f = &test;
	double start, end, ans;

	start = get_time();
	ans = bisect(f, .00001f, 1, 2);
	end = get_time();

	printf("The root is %f and took %e seconds", ans, end-start);
	return 0;
}