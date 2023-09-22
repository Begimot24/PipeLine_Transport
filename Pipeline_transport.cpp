#include <iostream>

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
		string PipeName;
		double dlina;
		double diameter;
		string status;

		//Параметры КС
		string KSName;
		int plNum;
		string efficiency;

		if (choice == 1) {


			cout << "Пожалуйста, введите характеристики трубы\n";
			cout << "Километровая отметка(название): ";
			cin >> PipeName;

			cout << "Выберите длину для "; cout << PipeName; cout << ":\n";
			cin >> dlina;

			cout << "Выберите диаметр для "; cout << PipeName; cout << ":\n";
			cin >> diameter;

			cout << "Признак (в ремонте/не в ремонте): \n";
			cin >> status;


			cout << "Новая труба "; cout << PipeName; cout << " длинною "; cout << dlina; cout << " диаметром "; cout << diameter; cout << " была успешно создана\n";

		}
		else if (choice == 2)
		{

			cout << "Пожалуйста, введите характеристики КС:\n";

			cout << "Название: \n";
			cin >> KSName;

			cout << "Количество цехов: \n";
			cin >> plNum;

			cout << "Эффективность (Низкая, Средняя, высокая): \n";
			cin >> efficiency;

			cout << "КС с названием"; cout << KSName; cout << " и числом цехов "; cout << plNum; cout << " был успешно создан. Эффективность: "; cout << efficiency;



		}
		else if (choice == 3)
		{
			cout << "\tПросмотр всех объектов\n";

			if (PipeName.empty())
			{
				cout << "Труб нет";
			}
			else if (KSName.empty())
			{
				cout << "КС нет";
			}

			cout << "Существующие трубы:\n";

			cout << "1)Труба"; cout << PipeName; cout << " длинною "; cout << dlina; cout << " диаметром"; cout << diameter; cout << "Признак: "; cout << status; cout << "\n";

			cout << "Существуюшие КС: \n";

			cout << "КС с названием"; cout << KSName; cout << " и числом цехов "; cout << plNum; cout << " был успешно создан. Эффективность: "; cout << efficiency;
		}

		else if (choice == 4)
		{
			cout << "Редактировать трубу\n"; cout << PipeName;
			if (PipeName.empty())
			{
				cout << "Труба ещё не была создана. Пожалуйста создайте трубу\n";
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
		else if(choice == 5)
		{
			cout << "Редактировать КС: \n";

			if (KSName.empty())
			{
				cout << "Нет добавленных КС\n";
			}
			else
			{
				cin >> KSName;

				cin >> plNum;

				cin >> efficiency;

				cout << "Операция выполнена успешно";
			}
		}
		else if (choice == 6)
		{
			
		}

	}
	return 0;
}
