#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Spec {
	COMPUTER_SCIENCE, INFORMATICS, MATH_ECONOMICS,
	PHYSICS_INFORMATICS, WORK_TRAINING
};

string specStr[] = { "����\'����� �����", "�����������",
"���������� �� ��������", "Գ���� �� �����������","������� ��������" };

struct Student
{
	string secondname;
	unsigned kurs;
	Spec spec;
	int physics;
	int math;
	int inf;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
int* Num(Student* s, const int N);
double LineSearch(Student* s, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;

	int* k = new int[3];

	cout << "������ N = "; cin >> N;

	Student* s = new Student[N];

	Create(s, N);
	Print(s, N);

	k = Num(s, N);

	cout << "������� �\'����� � �����������: " << k[0] << endl;
	cout << "������� ������� � �����������: " << k[1] << endl;
	cout << "������� ����� � �����������: " << k[2] << endl << endl;

	cout << "������� �������� �� �������� � � ������ � � ���������� 4 ��� 5: "
		<< LineSearch(s, N) << "%" << endl;

	system("pause");
	return 0;
}

void Create(Student* s, const int N)
{
	int spec;

	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;

		cin.get();
		cin.sync();

		cout << "\t�������: "; getline(cin, s[i].secondname);
		cout << "\t����: "; cin >> s[i].kurs;
		cout << "\t������������:\n [0]����\'����� �����\n [1]�����������\n"
			<< " [2]���������� �� ��������\n [3]Գ���� �� �����������\n"
			<< " [4]������� ��������\n ��� ����: "; cin >> spec;

		s[i].spec = (Spec)spec;

		switch (s[i].spec)
		{
		case COMPUTER_SCIENCE:
			cout << "\t������ � ������: "; cin >> s[i].physics;
			cout << "\t������ � ����������: "; cin >> s[i].math;
			cout << "\t������ � �����������: "; cin >> s[i].inf;
			break;
		case INFORMATICS:
			cout << "\t������ � ������: "; cin >> s[i].physics;
			cout << "\t������ � ����������: "; cin >> s[i].math;
			cout << "\t������ � �����������: "; cin >> s[i].inf;
			break;
		case MATH_ECONOMICS:
		case PHYSICS_INFORMATICS:
		case WORK_TRAINING:
			cout << "\t������ � ������: "; cin >> s[i].physics;
			cout << "\t������ � ����������: "; cin >> s[i].math;
			cout << "\t������ � �����������: "; cin >> s[i].inf;
			break;
		}
		cout << endl;
	}
}

void Print(Student* s, const int N)
{
	cout << "========================================================================================="
		<< endl;
	cout << "| � |   �������   | ���� |      ������������      | Գ���� | ���������� | ����������� |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(12) << left << s[i].secondname << " "
			<< "|   " << setw(1) << right << s[i].kurs << "  "
			<< "| " << setw(23) << left << specStr[s[i].spec] << " "
			<< "|    " << setw(1) << right << s[i].physics << "   "
			<< "|      " << setw(1) << left << s[i].math << "     ";

		switch (s[i].spec)
		{
		case COMPUTER_SCIENCE:
			cout << "|       " << setw(1) << right << s[i].inf << "     |" << endl;
			break;
		case INFORMATICS:
			cout << "|       " << setw(1) << right << s[i].inf << "     |" << endl;
			break;
		case MATH_ECONOMICS:
		case PHYSICS_INFORMATICS:
		case WORK_TRAINING:
			cout << "|       " << setw(1) << right << s[i].inf << "     |" << endl;
			break;
		}
	}
	cout << "========================================================================================="
		<< endl;
	cout << endl;
}

int* Num(Student* s, const int N)
{
	int* k = new int[3];

	for (int j = 0; j < 3; j++)
	{
		k[j] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		if (s[i].inf == 5)
		{
			k[0]++;
		}

		if (s[i].inf == 4)
		{
			k[1]++;
		}

		if (s[i].inf == 3)
		{
			k[2]++;
		}
	}

	return k;
}

double LineSearch(Student* s, const int N)
{
	double k = 0.0, n = N;

	for (int i = 0; i < N; i++)
	{
		if (s[i].math == 4 && s[i].physics == 4 ||
			s[i].math == 5 && s[i].physics == 5)
		{
			k++;
		}
	}

	return 100.0 * k / n;
}