#include<iostream>
#include<io.h>
#include<direct.h>
#include<Windows.h>
using namespace std;

char theme[20];
char answerFromUser[25];
char answerFromFile[25];
int questionCounter;
char** fileData = nullptr;
int row;

void ShowResult()
{
	system("cls");

	cout << "–езультаты викторины - " << questionCounter << " вопросов:" << endl;

	for (size_t i = 0; i < questionCounter; i++)
	{
		cout << answerFromFile[i]<<" ";
	}

	cout << endl;

	for (size_t i = 0; i < questionCounter; i++)
	{
		cout << answerFromUser[i] << " ";
	}

	cout << endl;
}

void ShowQuestion()
{
	for (size_t i = 0; i < row; i++)
	{
		system("cls");

		for (size_t j = 0; j < 6; j++)
		{
			if (j==5)
			{
				answerFromFile[questionCounter] = (fileData[i+j])[0];
			}
			else
			{
				cout << fileData[i + j];
			}
		}

		i += 5;

		cout << "¬ведите ответ - ";

		cin >> answerFromUser[questionCounter];

		questionCounter++;
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

void loadFile()
{
	FILE* fp;

	fileData = new char* [100];

	for (size_t i = 0; i < 100; i++)
	{
		fileData[i] = new char[100];
	}

	int var1 = _chdir("Questions");

	fopen_s(&fp, theme, "r");


	if (fp != nullptr)
	{
		for (size_t i = 0; i < 100; i++)
		{
			fgets(fileData[i], 100, fp);

			row++;

			if ((fileData[i])[1] == '#')
			{
				break;
			}

		}

		fclose(fp);
	}
}

void Victorina()
{
	setlocale(LC_ALL, "ru");

	cout << "Victorina" << endl << endl;

	SelectTheme();

	loadFile();

	ShowQuestion();

	ShowResult();

	for (size_t i = 0; i < 100; i++)
	{
		delete[] fileData[i];
	}
	delete[] fileData;

}


int main()
{

	Victorina();


}