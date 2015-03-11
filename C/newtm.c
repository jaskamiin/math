//REALLY basic function to find a simple derivative
static inline double diff(double(*f)(double), double x0){
	const double delta = 1.0e-6; // or similar
	double	x1 = x0 - delta, 
			x2 = x0 + delta,
			y1 = f(x1),
			y2 = f(x2);

	return (y2 - y1) / (x2 - x1);
}

double newton_method(double(*f)(double), double a){
	for (int i = 0; i < 1000; i++){
		if (f(a) == diff(f, a)) break;
		if (fabs(f(a) - diff(f, a)) <= 0.00005f) break;
		a = a - f(a) / diff(f, a);
	}
}
