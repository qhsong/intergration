#include<stdio.h>
#include<math.h>

double romberg(double (*f)(double),double a,double b) {
	int n=2,i=0,count=1;
	double Tn,T2n,Sn,S2n,Cn,C2n,Rn,R2n;
	double h = (b-a)/2.0;

	Tn = h/2.0*(f((double)a) + f((double)b)); 
	while(1) {
		double sum = 0;
		for(i=1;i<=n-1;i++) {
			sum += f(a+i*h+h/2.0);
		}

		T2n = Tn/2.0 + h/2.0 * sum;
		Sn = S2n;
		S2n = (4 * T2n - Tn)/3.0;
		if(count>2) {
			C2n = (16 * S2n -Sn)/15.0;
			if(count>3){
				Cn = C2n;
				C2n = (16 * S2n -Sn)/15.0;
				R2n = (64 * C2n-Cn)/63.0;
				if(count >4) {
					Rn = R2n;
					R2n = (64 * C2n-Cn)/63.0;
					if(fabs(T2n-Tn)<0.00000001) {
						break;
					}

				}
			}	
		}
		Tn=T2n;
		h /=2.0;
		n *=2;
		count++;	
	}

	return R2n;
}

double ff(double x) {
	return exp(x)*sqrt(1-x*x);
}

int main() {
	int n;
	for(n=0;n<10;n++)
	printf("%15.13f\n",romberg(ff,-1,1));
	return 0;

}
