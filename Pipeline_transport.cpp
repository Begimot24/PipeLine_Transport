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

		cout << "Базовые сущности трубопроводного транспорта нефти и газа\n\n";

		cout << "\t\tПожалуйста введите номер операции:\n\n 1. Добавить трубу\n 2. Добавить КС\n 3. Просмотр всех объектов\n 4. Редактировать трубу\n 5. Редактировать КС\n 6. Сохранить\n 7. Загрузить\n 0. Выход\n";

		int choice;

		cin >> choice;

		// Параметры трубы
		static string PipeName;
		static double dlina;
		static double diameter;
		static string status;

		//Параметры КС
		static string KSName;
		static int plNum;
		static string efficiency;






		//добавить трубу
		if (choice == 1) {


			cout << "Пожалуйста, введите характеристики трубы\n";
			cout << "Километровая отметка(название): ";
			cin >> PipeName;

			cout << "Выберите длину для "; cout << PipeName; cout << ":\n";
			cin >> dlina;

			cout << "Выберите диаметр для "; cout << PipeName; cout << ":\n";
			cin >> diameter;

			
			cout << "Признак (Repairing, IS): \n";
			cin >> status;


			cout << "Новая труба "; cout << PipeName; cout << " длинною "; cout << dlina; cout << " диаметром "; cout << diameter; cout << " с признаком "; cout << status; cout << " была успешно создана\n\n";

		}

		//добавить кс
		else if (choice == 2)
		{

			cout << "Пожалуйста, введите характеристики КС:\n";

			cout << "Название: \n";
			cin >> KSName;

			cout << "Количество цехов: \n";
			cin >> plNum;

			cout << "Эффективность (Низкая, Средняя, высокая): \n";
			cin >> efficiency;

			cout << "КС с названием "; cout << KSName; cout << " и числом цехов "; cout << plNum; cout << " был успешно создан. Эффективность: "; cout << efficiency; cout << "\n";


		}

		//просмотр всех объектов
		else if (choice == 3)
		{
			cout << "\tПросмотр всех объектов\n\n";

			if (PipeName.empty())
			{
				cout << "Труб нет\n\n";
			}

			else
			{
				cout << "1) Труба "; cout << PipeName; cout << " длинною "; cout << dlina; cout << " и диаметром "; cout << diameter; cout << " Признак: "; cout << status; cout << "\n\n";
			}

			if (KSName.empty())
			{
				cout << "КС нет\n\n";
			}
			
			else
			{
				cout << "2) КС с названием "; cout << KSName; cout << " и числом цехов "; cout << plNum; cout << " Эффективность: "; cout << efficiency; cout << "\n\n";
			}
		}


		//редактировать трубу
		else if (choice == 4)
		{
			cout << "Редактировать трубу\n"; cout << PipeName; cout << "\n";
			if (PipeName.empty())
			{
				cout << "Труба ещё не была создана. Пожалуйста создайте трубу\n\n";
			}
			else
			{
				cout << "Название:\n";
				cin >> PipeName;

				cout << "Длина:\n";
				cin >> dlina;

				cout << "Диаметр:\n";
				cin >> diameter;

				cout << "Признак:\n";
				cin >> status;

				cout << "Операция выполнена успешно/n";
			}
		}

		//редактировать кс
		else if (choice == 5)
		{
			cout << "Редактировать КС: \n";

			if (KSName.empty())
			{
				cout << "Нет добавленных КС\n";
			}
			else
			{
				cout << "Название: \n";
				cin >> KSName;

				cout << "Число цехов: \n";
				cin >> plNum;

				cout << "Эффективность: \n";
				cin >> efficiency;

				cout << "Операция выполнена успешно\n\n";
			}
		}
		//сохранить
		else if (choice == 6)
		{

			ofstream pipeData("pipeline.txt");
			pipeData << "Труба ";  pipeData << PipeName; pipeData << " Длина: "; pipeData << dlina; pipeData << " Диаметр ";  pipeData << diameter; pipeData << "Признак: "; pipeData << status;
			ofstream KSData("KC.txt");
			KSData << KSName; KSData << " Число цехов: "; KSData << plNum; KSData << " Эффективность: "; KSData << efficiency;
			cout << "Введённые данные были сохранены\n\n";
		}

		//загрузить
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

		//выход
		else if (choice == 0)
		{
			exit(0);
		}

		else
		{
			cout << "Неверный тип ввода. Попытайтесь снова.\n\n";
		}
	}
	return 0;
}

