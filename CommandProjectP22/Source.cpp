#include<iostream>
#include<io.h>
#include<direct.h>
#include<Windows.h>
using namespace std;

char theme[20];
char answerFromUser[25];
char answerFromFile[25];
int cnt = 0;

void ShowResult()
{
	system("cls");

	cout << "–езультаты викторины - " << cnt << " вопросов:" << endl;

	for (size_t i = 0; i < cnt; i++)
	{
		cout << answerFromFile[i]<<" ";
	}

	cout << endl;

	for (size_t i = 0; i < cnt; i++)
	{
		cout << answerFromUser[i] << " ";
	}

	cout << endl;
}

void ShowQuestion()
{
	FILE* fp;
	char buff[100];
	int var1 = _chdir("Questions");

	fopen_s(&fp, theme, "r");

	if (fp != nullptr)
	{
		do
		{
			system("cls");

			for (size_t i = 0; i < 6; i++)
			{
				fgets(buff, 100, fp);

				if (i == 5)
				{
					answerFromFile[cnt] = buff[0];
				}
				else
				{
					cout << buff;
				}
			}

			cout << "¬ведите ответ - ";

			cin >> answerFromUser[cnt];

			cnt++;

		} while (buff[1]!='#');

		fclose(fp);
	}

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

	ShowResult();

}


int main()
{

	Victorina();


}