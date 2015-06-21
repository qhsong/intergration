#include<stdio.h>
#include<math.h>

const double PI=3.141592653;

double guass_ch1(double(*f)(double),int n) {
	int i;
	double sum=0;
	for(i=1 ; i<=n ;i++) {
		sum += pow(sin(i*PI/(n+1)),2)*f(cos(i*PI/(n+1))); 
	}
	double tmp = PI/(n+1);
	return tmp * sum; 
}

double ff(double x) {
	return exp(x);
}
int main() {
	int n;
	for(n=0;n<1000;n++)
	printf("%20.18f\n",guass_ch1(ff,10));
	return 0;
}
