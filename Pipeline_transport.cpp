#include <iostream>

using namespace std;


int main()
{
	while (true)
	{


		setlocale(LC_ALL, "Russian");

		cout << "������� �������� ��������������� ���������� ����� � ����\n\n";

		cout << "\t\t���������� ������� ����� ��������:\n\n 1. �������� �����\n 2. �������� ��\n 3. �������� ���� ��������\n 4. ������������� �����\n 5. ������������� ��\n 6. ���������\n 7. ���������\n 0. �����\n";

		int choice;

		cin >> choice;

		// ��������� �����
		string PipeName;
		double dlina;
		double diameter;
		string status;

		//��������� ��
		string KSName;
		int plNum;
		string efficiency;

		if (choice == 1) {


			cout << "����������, ������� �������������� �����\n";
			cout << "������������ �������(��������): ";
			cin >> PipeName;

			cout << "�������� ����� ��� "; cout << PipeName; cout << ":\n";
			cin >> dlina;

			cout << "�������� ������� ��� "; cout << PipeName; cout << ":\n";
			cin >> diameter;

			cout << "������� (� �������/�� � �������): \n";
			cin >> status;


			cout << "����� ����� "; cout << PipeName; cout << " ������� "; cout << dlina; cout << " ��������� "; cout << diameter; cout << " ���� ������� �������\n";

		}
		else if (choice == 2)
		{

			cout << "����������, ������� �������������� ��:\n";

			cout << "��������: \n";
			cin >> KSName;

			cout << "���������� �����: \n";
			cin >> plNum;

			cout << "������������� (������, �������, �������): \n";
			cin >> efficiency;

			cout << "�� � ���������"; cout << KSName; cout << " � ������ ����� "; cout << plNum; cout << " ��� ������� ������. �������������: "; cout << efficiency;



		}
		else if (choice == 3)
		{
			cout << "\t�������� ���� ��������\n";

			if (PipeName.empty())
			{
				cout << "���� ���";
			}
			else if (KSName.empty())
			{
				cout << "�� ���";
			}

			cout << "������������ �����:\n";

			cout << "1)�����"; cout << PipeName; cout << " ������� "; cout << dlina; cout << " ���������"; cout << diameter; cout << "�������: "; cout << status; cout << "\n";

			cout << "������������ ��: \n";

			cout << "�� � ���������"; cout << KSName; cout << " � ������ ����� "; cout << plNum; cout << " ��� ������� ������. �������������: "; cout << efficiency;
		}

		else if (choice == 4)
		{
			cout << "������������� �����\n"; cout << PipeName;
			if (PipeName.empty())
			{
				cout << "����� ��� �� ���� �������. ���������� �������� �����\n";
			}
			else
			{
				cout << "��������:\n";
				cin >> PipeName;

				cout << "�����:\n";
				cin >> dlina;

				cout << "�������:\n";
				cin >> diameter;

				cout << "�������:\n";
				cin >> status;

				cout << "�������� ��������� �������/n";
			}
		else if(choice == 5)
		{
			cout << "������������� ��: \n";

			if (KSName.empty())
			{
				cout << "��� ����������� ��\n";
			}
			else
			{
				cin >> KSName;

				cin >> plNum;

				cin >> efficiency;

				cout << "�������� ��������� �������";
			}
		}
		else if (choice == 6)
		{
			
		}

	}
	return 0;
}
