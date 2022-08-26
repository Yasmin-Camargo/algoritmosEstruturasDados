#include <stdio.h>

void Insertionsort( int data[], int n) {
	int tmp,i,j;
	for (j=1; j<n; j++) {
		i=j-1;
		tmp = data[j];
		while ( (i>=0) && (tmp < data[i]) ) {
			data[i+1] = data[i];
			i--;
		}//while
		data[i+1] = tmp;
	}//for
}//Insertionsort

int main()
{
	int data[3];
	int n=3;

	data[0]=3;
	data[1]=1;
	data[2]=2;

	Insertionsort(data, n);
}

