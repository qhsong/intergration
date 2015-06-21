#include<stdio.h>
#include<math.h>

double comp_trep(double (*f)(double),double a,double b) {
	int n=2,i=0;	
	double Tn,T2n;
	double h = (b-a)/2.0;

	Tn = h/2.0*(f((double)a) + f((double)b)); 
	while(1) {
		double sum = 0;
		for(i=1;i<=n-1;i++) {
			sum += f(a+i*h+h/2.0);
		}

		T2n = Tn/2.0 + h/2.0 * sum;
		if(fabs(T2n-Tn)/3<0.00000001) {
			break;
		}
		Tn=T2n;
		h /=2.0;
		n *=2;
		
	}

	return T2n;
}

double ff(double x) {
	return exp(x)*sqrt(1-x*x);
}

int main() {
	int n;
	for(n=0;n<10;n++)
	printf("%15.13f\n",comp_trep(ff,-1,1));
	return 0;

}
