

#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
using namespace std;
class A
{
public:
	A(){m=10;};

private:
	double m;
};

void GetMemory(char *p, int num)
{
	A *aa = new A();
}

int main(int argc,char** argv)
{

	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	char *str = NULL;
	GetMemory(str, 100);
	

	cout<<"Memory leak test!"<<endl;
	//_CrtDumpMemoryLeaks();
	return 0;
}