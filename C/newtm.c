//REALLY basic function to find a simple derivative
static inline double diff(double(*f)(double), double x0){
	const double delta = 1.0e-6; // or similar
	double  x1 = x0 - delta, 
            x2 = x0 + delta,
            y1 = f(x1),
            y2 = f(x2);

    return (y2 - y1) / (x2 - x1);
}

//newton method implementation
double newton_method(double(*f)(double), double a){
    for (int i = 0; i < 1000; i++){
        double dA = diff(f, a), fA = f(a);
        if (fA == dA) break; 
        if (fabs(fA - dA) <= 0.00005f) break;
        a = a - fA / dA;
    }
}
