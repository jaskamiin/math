# secant method for root-finding
def secant(f, a, b):
    a = float(a)
    b = float(b)
    c = float(0)
    for x in xrange(0, 1000):
        if f(a) == f(b):
            break
        else:
            c = a - (f(a) * (a - b)) / (f(a) - f(b))
            b = a
            a = c
    return c
    

# bisection method of root-finding
def bisect(f, a, b, eps):
    if b < a:
        a, b = b, a
    if eps <= 0:
        return "Error tolerance must be greater than zero"
    if f(a)*f(b) > 0:
        return "Invalid interval"
    a = float(a)
    b = float(b)
    while True:
        c = (a + b) / 2
        if (b - c)/2 <= eps:
            break
        if (f(b) * f(c)) <= 0:
            a = c
        else:
            b = c
    return c
   

# numerical differentiation (primitive - can be done much better)
def ndiff(f, x, h=.000000000001):
    return (f(x+h) - f(x)) / h 