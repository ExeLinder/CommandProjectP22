#include<iostream>
#include<io.h>
#include<direct.h>
#include<Windows.h>
using namespace std;

char theme[20];

int questionCounter;


struct Question
{
	char question[7][100];
};

Question questions[10];

void ShowResult()
{
	system("cls");

	cout << "Результаты викторины - " << questionCounter << " вопросов:" << endl;

	for (size_t i = 0; i < questionCounter; i++)
	{
		cout << "Вопрос:" << endl;
		cout << questions[i].question[0];
		cout << "Правильный ответ:" << endl;
		cout << questions[i].question[5];
		cout << "Ответ игрока:" << endl;
		cout << questions[i].question[6];

		if (strcmp(questions[i].question[6], questions[i].question[5]) == 0)
		{
			cout << "Ответ верный!" << endl;
		}
		else
		{
			cout << "Ответ не верный!" << endl;
		}
		cout << endl;
	}

}

void ShowQuestion()
{
	char ch = 0;
	int index = 0;

	for (size_t i = 0; i < questionCounter; i++)
	{
		system("cls");

		for (size_t j = 0; j < 5; j++)
		{
			cout << questions[i].question[j];
		}

		cout << "Введите ответ - ";

		cin >> ch;

		switch (ch)
		{
		case 'a': index = 1;
			break;
		case 'b': index = 2;
			break;
		case 'c': index = 3;
			break;
		case 'd': index = 4;
			break;
		default: cout << "Не верный выбор";
			break;
		}

		strcpy_s(questions[i].question[6], 100, questions[i].question[index]);

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

	cout << "Введите название темы - ";

	cin >> theme;
}

void loadFile()
{
	FILE* fp;
	int var1 = _chdir("Questions");

	fopen_s(&fp, theme, "r");

	Question tmp;

	if (fp != nullptr)
	{
		while (1)
		{
			for (size_t i = 0; i < 6; i++)
			{
				fgets(tmp.question[i], 100, fp);

				if (strstr(tmp.question[i], "#"))
				{
					fclose(fp);
					return;
				}
			}

			questions[questionCounter] = tmp;

			questionCounter++;
		}
		fclose(fp);
	}
};

void Victorina()
{
	setlocale(LC_ALL, "ru");

	cout << "Victorina" << endl << endl;

	SelectTheme();

	loadFile();

	ShowQuestion();

	ShowResult();
}


int main()
{
	Victorina();

}