#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

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
		static string PipeName;
		static double dlina;
		static double diameter;
		static string status;

		//��������� ��
		static string KSName;
		static int plNum;
		static string efficiency;






		//�������� �����
		if (choice == 1) {


			cout << "����������, ������� �������������� �����\n";
			cout << "������������ �������(��������): ";
			cin >> PipeName;

			cout << "�������� ����� ��� "; cout << PipeName; cout << ":\n";
			cin >> dlina;

			cout << "�������� ������� ��� "; cout << PipeName; cout << ":\n";
			cin >> diameter;

			
			cout << "������� (Repairing, IS): \n";
			cin >> status;


			cout << "����� ����� "; cout << PipeName; cout << " ������� "; cout << dlina; cout << " ��������� "; cout << diameter; cout << " � ��������� "; cout << status; cout << " ���� ������� �������\n\n";

		}

		//�������� ��
		else if (choice == 2)
		{

			cout << "����������, ������� �������������� ��:\n";

			cout << "��������: \n";
			cin >> KSName;

			cout << "���������� �����: \n";
			cin >> plNum;

			cout << "������������� (������, �������, �������): \n";
			cin >> efficiency;

			cout << "�� � ��������� "; cout << KSName; cout << " � ������ ����� "; cout << plNum; cout << " ��� ������� ������. �������������: "; cout << efficiency; cout << "\n";


		}

		//�������� ���� ��������
		else if (choice == 3)
		{
			cout << "\t�������� ���� ��������\n\n";

			if (PipeName.empty())
			{
				cout << "���� ���\n\n";
			}

			else
			{
				cout << "1) ����� "; cout << PipeName; cout << " ������� "; cout << dlina; cout << " � ��������� "; cout << diameter; cout << " �������: "; cout << status; cout << "\n\n";
			}

			if (KSName.empty())
			{
				cout << "�� ���\n\n";
			}
			
			else
			{
				cout << "2) �� � ��������� "; cout << KSName; cout << " � ������ ����� "; cout << plNum; cout << " �������������: "; cout << efficiency; cout << "\n\n";
			}
		}


		//������������� �����
		else if (choice == 4)
		{
			cout << "������������� �����\n"; cout << PipeName; cout << "\n";
			if (PipeName.empty())
			{
				cout << "����� ��� �� ���� �������. ���������� �������� �����\n\n";
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
		}

		//������������� ��
		else if (choice == 5)
		{
			cout << "������������� ��: \n";

			if (KSName.empty())
			{
				cout << "��� ����������� ��\n";
			}
			else
			{
				cout << "��������: \n";
				cin >> KSName;

				cout << "����� �����: \n";
				cin >> plNum;

				cout << "�������������: \n";
				cin >> efficiency;

				cout << "�������� ��������� �������\n\n";
			}
		}
		//���������
		else if (choice == 6)
		{

			ofstream pipeData("pipeline.txt");
			pipeData << "����� ";  pipeData << PipeName; pipeData << " �����: "; pipeData << dlina; pipeData << " ������� ";  pipeData << diameter; pipeData << "�������: "; pipeData << status;
			ofstream KSData("KC.txt");
			KSData << KSName; KSData << " ����� �����: "; KSData << plNum; KSData << " �������������: "; KSData << efficiency;
			cout << "�������� ������ ���� ���������\n\n";
		}

		//���������
		else if (choice == 7)
		{
			vector<double> pipeVector;
			ifstream input_pipe("pipeline.txt");
			double pipeVar;
			while (input_pipe >> pipeVar)
			{
				pipeVector.push_back(pipeVar);
			}

			vector<double> kcVector;
			ifstream input_kc("KC.txt");
			double kcVar;
			while (input_kc >> kcVar)
			{
				kcVector.push_back(kcVar);
			}
			
		}

		//�����
		else if (choice == 0)
		{
			exit(0);
		}

		else
		{
			cout << "�������� ��� �����. ����������� �����.\n\n";
		}
	}
	return 0;
}

