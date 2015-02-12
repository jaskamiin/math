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
    float a1 = a, b2 = b, pM1 = a, p = (a1+b1)/2;
    while (abs( p - pM1 ) < e){
        f(p)*f(a1) > 0 ? a1 = p : b1 = p;
        pM1 = p;
        p = (a1+b)/2;
    }
    
    return p;
}

//a1 = a
//b1 = b
//p0 = a
//"#" 
//p = (a1+b1)/2
//if the acceptable relative error is satisfied, goto STOP
//if f(p1)*f(a1) > 0, continue, otherwise go to "$"
//a = p1, b = b
//goto "#"
//"$"
//a = a, b = p1
//goto "#"
//STOP