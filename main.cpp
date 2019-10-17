#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_CTYPE,"russian");
	int i=0,j =0 , N;
	double  h, dmax;
	double* x, * y;
	cout<<"Введите шаг: ";
	while (true)
	{
		
		cin>>h;
		N=2./h;
		cout<<N<<endl;
		x=new double[N+1]; 
		y=new double[N+1]; 
		int iter;
		x[0]=0;
		y[0]=0;
		dmax=0;
		for(i=0;i<N;i++)
		{
			x[i+1]=x[i]+h;
			y[i+1]=y[i]+h*(y[i]/2+x[i]);
			if(abs(y[i+1]-(4*exp(x[i+1]/2)-2*x[i+1]-4))>dmax)
			{
				dmax=fabs(y[i+1]-(4*exp(x[i+1]/2)-2*x[i+1]-4));
				iter=i+1;
			}
			cout<<"y["<<i+1<<"]="<<y[i+1]<<"						y["<<i+1<<"]="<<4*exp(x[i+1]/2)-2*x[i+1]-4<<endl;
		
			if(i==N-1)
			{
				cout<<"dmax["<<iter<<"] = "<< dmax<<endl<<endl;
				dmax=0;
			}
		}
		j++;
		delete [] x;
		delete [] y;

	}
	
	return 0;
}

