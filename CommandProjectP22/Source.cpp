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

Question questions[5];


void ShowResult()
{
	system("cls");

	cout << "���������� ��������� - " << questionCounter << " ��������:" << endl;

	for (size_t i = 0; i < 5; i++)
	{
		cout << "������:" << endl;
		cout << questions[i].question[0];
		cout << "���������� �����:" << endl;
		cout << questions[i].question[5];
		cout << "����� ������:" << endl;
		cout << questions[i].question[6];

		if ((questions[i].question[6])[0] == (questions[i].question[5])[0])
		{
			cout << "����� ������!" << endl;
		}
		else
		{
			cout << "����� �� ������!" << endl;
		}
		cout << endl;
	}

}

void ShowQuestion()
{
	char ch = 0;
	int index = 0;

	for (size_t i = 0; i < 5; i++)
	{
		system("cls");

		for (size_t j = 0; j < 5; j++)
		{
			cout << questions[i].question[j];
		}

		cout << "������� ����� - ";

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
		default:
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

	cout << "������� �������� ���� - ";

	cin >> theme;
}

void loadFile()
{
	FILE* fp;

	int var1 = _chdir("Questions");

	fopen_s(&fp, theme, "r");


	if (fp != nullptr)
	{
		for (size_t i = 0; i < 30; i++)
		{
			for (size_t j = 0; j < 6; j++)
			{
				fgets(questions[questionCounter].question[j], 100, fp);
			}

			i += 5;
			questionCounter++;

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
}


int main()
{
	Victorina();

}