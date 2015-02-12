/*
    C implementation of Bisection method for root-finding
*/

#define abs(x) x >= 0 ? x : -x

//test function ---  x^3 + x^2 + x + 1
float f(float x){
    return (x*x*x)+(x*x)+ x + 1;
}

//f - function to evaluate
//e - error tolerance
//[a,b] - interval in which to find root (assuming a, b in Z)
float bisect(float (*f)(float), float e, int a, int b){
  
    //use intermediate value theorem to check 
    //if a root exists in interval [a,b]
    short flag;
    a >= 0 ? (b >= 0 ? flag = 0 : flag = 1 ) : (b < 0 ? flag = 0 : flag = 1 );
    if (flag == 0) return 0;
    
    //begin bisection method
    float a1 = (float)a, b2 = (float)b, pM1 = (float)a, p = (a+b)/2;
    while (abs( p - pM1 ) < e){
        f(p)*f(a) > 0 ? a = p : b = p;
        pM1 = p;
        p = (a+b)/2;
    }
    
    return p;
}