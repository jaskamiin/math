float bisect(float(*f)(float), float e, float a, float b){
	//use intermediate value theorem to check 
	//if a root exists in interval [a,b]
	if (f(a)*f(b) > 0) return 0; 

	float c;
	while (1){
		c = (a + b) / 2;
		if ((b-c)/c<=e) break;
		f(b)*f(c) <= 0 ? a = c : b = c;
	}
	return c;
}
