function x0 = NLNewton(x0, TOL, N)

% set up
format long;
syms x y;

% make sure x0 is a column vector so the transposes below make sense
x0 = x0(:);

% this is the system we will solve
F = [3*x^2 - y^2; 3*x*y^2 - x^3 - 1];

for k = 1:N
   % compute F(x0) and J(x0)
   Fx = double(subs(F, [x y], x0'));
   Jx = double(subs(jacobian(F, [x y]), [x y], x0'));
   
   % evaluate J(x0)y0 = -F(x0)
   y0 = Jx\-Fx;
   
   % test ending condition
   if norm(y0, 'inf') < TOL
       return;
   end
   
   % refine solution vector
   x0 = x0 + y0;
end
display('Maximum iterations exceeded')
