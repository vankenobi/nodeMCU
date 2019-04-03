#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int fonk(int &bir,int &iki)
{
	bir = 43;
	iki = 89;
	cout<<bir<<"ve"<<iki<<endl;
	return 0;
}
int main()
{
	int a = 5, b = 6;
	cout<<a<<"ve"<<b<<endl;
	fonk(a,b);
	

	return 0;
}
