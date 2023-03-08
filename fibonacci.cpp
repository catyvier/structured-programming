int fib(int x) {
   if ((x==1)||(x==0)) return x;
   
   return fib(x-1) + fib(x-2);
}
