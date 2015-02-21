#include <stdio.h>

typedef float (*func)(float);

//test function: x^5 + 7x^4 - 8x^3 + x^2 - 2
float test(float x){
	return (x*x*x*x*x) + (7*x*x*x*x) - (8*x*x*x) + (x*x) - 2;
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

//test method with function f(x), e = 10^-4, on [1,2]
int main(){
	func f = &test;
	printf("The root is %f", bisect(f, .001f, 0, 2));
	getchar();
	return 0;
}