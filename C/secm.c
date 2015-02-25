double secm(double(*f)(double), double a, double b){
	double c;
	for (int i = 0; i < 1000; i++){
		if (f(a) == f(b)) break;
		c = a - f(a) * (a - b) / (f(a) - f(b));
		b = a; a = c;
	}
	return c;
}