#include<iostream>
#include<io.h>
#include<direct.h>
#include<Windows.h>
using namespace std;


struct Question
{
	char question[7][100];
};


Question* questions = nullptr;
char theme[20];
int questionCounter;

Question* dinArr(Question* arr, int& arrSize, Question& val)
{
	Question* tmp = nullptr;

	if (arrSize == 0)
	{
		tmp = new Question;
		tmp[0] = val;
	}
	else
	{
		tmp = new Question[arrSize + 1];

		for (size_t i = 0; i < arrSize; i++)
		{
			tmp[i] = arr[i];
		}
		tmp[arrSize] = val;

		delete[]arr;
	}

	arrSize++;

	return tmp;
}

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
	bool choice = false;

	for (size_t i = 0; i < questionCounter; i++)
	{
		system("cls");
		do
		{
			for (size_t j = 0; j < 5; j++)
			{
				cout << questions[i].question[j];
			}

			cout << "Введите ответ - ";

			cin >> ch;

			switch (ch)
			{
			case 'a': index = 1; choice = true;
				break;
			case 'b': index = 2; choice = true;
				break;
			case 'c': index = 3; choice = true;
				break;
			case 'd': index = 4; choice = true;
				break;
			default: system("cls"); cout << "Выбор не верный" << endl; choice = false;
				break;
			}
		} while (!choice);

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

			questions = dinArr(questions, questionCounter, tmp);

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

	delete[] questions;
}


int main()
{
	Victorina();
}