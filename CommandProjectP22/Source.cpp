#include<iostream>
#include<io.h>
#include<Windows.h>
using namespace std;

char theme[20];

void ShowQuestion()
{

}

void SelectTheme()
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

	cout << "¬ведите название темы - ";

	cin >> theme;
}

void Victorina()
{
	setlocale(LC_ALL, "ru");

	cout << "Victorina" << endl << endl;

	SelectTheme();

	ShowQuestion();

}


int main()
{

	Victorina();


}