#include <iostream>
using namespace std;
int main()
{
    int a = 1;
	int b = 1;
	if(a && b)
	{
		cout<<"&"<<1<<endl;
	}
	else if(a || b)
	{
		cout<<"|"<<1<<endl;
	}
    return 0;
}