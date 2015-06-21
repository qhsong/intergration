#include<stdio.h>
#include<math.h>

const double PI=3.141592653;

double guass_ch1(double(*f)(double),int n) {
	int i;
	double sum=0;
	for(i=1 ; i<=n ;i++) {
		sum += f(cos((double)(2*i-1)/(2*n)*PI));
	}
	double tmp = PI/n;
	return tmp * sum; 
}

double ff(double x) {
	return exp(x);
}
int main() {
	printf("%15.13f\n",guass_ch1(ff,100000));
	return 0;
}
