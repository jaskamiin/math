/*
    C language implementation of Bisection method for root-finding
    
    f - function to evaluate
    e - error tolerance
    [a,b] - interval in which to find root (assuming a, b in Z)
*/

#define abs(x) x >= 0 ? x : -x
float bisect(float (*f)(float), float e, int a, int b){
    //use intermediate value theorem to check 
    //if a root exists in interval [a,b]
    a*b >= 0 ? return 0 : continue;
    
    //begin bisection method
    float a1 = a, b2 = b, pM1 = a, p = (a1+b1)/2;
    while (abs( p - pM1 ) < e){
        f(p)*f(a1) > 0 ? a1 = p : b1 = p;
        pM1 = p;
        p = (a1+b)/2;
    }
    
    return p;
}

//-------------------------------------------------/
//example of a test function ---  x^3 + x^2 + x + 1
float f(float x){
    return (x*x*x)+(x*x)+ x + 1;
}
//-------------------------------------------------/