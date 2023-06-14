#include<iostream>
#include<io.h>
using namespace std;

void LoadQuestions()
{
	_finddata_t fileinfo;
	intptr_t ptr;
	int res = 0;

	if ((ptr = _findfirst("Questions\\*.txt", &fileinfo))!=-1)
	{
		while (!res)
		{
			cout << fileinfo.name<<endl;

			res = _findnext(ptr, &fileinfo);
		}
	}

	_findclose(ptr);
}

void Victorina()
{
	cout << "Victorina" << endl << endl;

	LoadQuestions();
}


int main()
{
	
	Victorina();


}