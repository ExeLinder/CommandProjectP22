#include<iostream>
#include<io.h>
#include<Windows.h>
using namespace std;

char theme[20];

void LoadTheme()
{
	cout << "������� �������� ���� - ";

	cin >> theme;
}

void LoadQuestions()
{
	_finddata_t fileinfo;
	intptr_t ptr;
	int res = 0;

	if ((ptr = _findfirst("Questions\\*.txt", &fileinfo)) != -1)
	{
		while (!res)
		{
			cout << fileinfo.name << endl;

			res = _findnext(ptr, &fileinfo);
		}
	}

	_findclose(ptr);

	cout << endl;
}

void Victorina()
{
	setlocale(LC_ALL, "ru");

	cout << "Victorina" << endl << endl;

	LoadQuestions();

	LoadTheme();

	cout << theme;
}


int main()
{

	Victorina();


}