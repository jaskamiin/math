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
