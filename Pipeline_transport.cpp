#include <iostream>
#include <fstream> 
#include <sstream> 
#include <string> 

using namespace std;

struct pipe {
	string pipe_name;
	int dlina;
	int diameter;
	bool mntn;
};

struct CS {
	string cs_name;
	int cs_num;
	int work_cs;
	double efc;
};


string get_str() {
	string str;
	cin >> ws;
	getline(std::cin, str);
	return str;
}


void menu() {
	cout << "\t\t Select an operation \n\n";
	cout << "1. Add a pipe \n";
	cout << "2. Add CS \n";
	cout << "3. Просмотр всех объектов \n";
	cout << "4. Редактировать трубу \n";
	cout << "5. Редактировать КС \n";
	cout << "6. Сохранить \n";
	cout << "7. Загрузть \n";
	cout << "0. Выход\n\n"; 
}


void pipe_add(pipe& pipe_chr)
{

	cout << "Введите название трубы: \n";
	pipe_chr.pipe_name = get_str();

	cout << "Введите длину трубы: \n";
	cin >> pipe_chr.dlina;

	while (cin.fail() || cin.peek() != '\n' || pipe_chr.dlina < 0) {
		cin.clear();
		cin.ignore(1000, 'n');
		cout << "Ввод некорректный.Введите длину трубы : \n";
		cin >> pipe_chr.dlina;
	}

	cout << "Введите диаметр трубы: \n";

	cin >> pipe_chr.diameter;

	while (cin.fail() || cin.peek() != '\n' || pipe_chr.diameter < 0) {
		cin.clear();
		cin.ignore(1000, 'n');
		cout << "Ввод некорректный.Введите диаметр трубы : \n";
		cin >> pipe_chr.diameter;
	}

	cout << "Находится в эксплуатации[1/0]?: \n";
	cin >> pipe_chr.mntn;

	while (cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ввод некорректный. Находится в эксплуатации?[1/0]: \n";
		cin >> pipe_chr.mntn;
	}
}
void add_cs(CS& cs_chr) {
	cout << "Введите название кс: \n";
	cs_chr.cs_name = get_str();

	cout << "Введите число цехов: \n";
	cin >> cs_chr.cs_num;

	while (cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ввод некорректный. Введите число цехов:  \n";
		cin >> cs_chr.cs_num;
	}

	cout << "Введите число рабочих цехов: \n";
	cin >> cs_chr.work_cs;

	while (cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ввод некорректный. Введите число рабочих цехов:  \n";
		cin >> cs_chr.work_cs;
	}

	cout << " Введите коэффициент эффективности: \n";
	cin >> cs_chr.efc;

	while (cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ввод некорректный. Введите коэффициент эффективности:  \n";
		cin >> cs_chr.efc;
	}

}


void overview(pipe& pipe_chr, CS& cs_chr) {
	if (!pipe_chr.pipe_name.empty()) {
		cout << "\t\t Трубы \n\n";

		cout << "Название: " << pipe_chr.pipe_name << '\n';
		cout << "Длина: " << pipe_chr.dlina << '\n';
		cout << "Диаметр: " << pipe_chr.diameter << '\n';

		if (pipe_chr.mntn == 1) {
			cout << "В эксплуатации?: Yes\n";
		}
		else {
			cout << "В эксплуатации?: No\n";
		}
	}
	else {

		cout << "Труб - нет\n";
	}

	if (!cs_chr.cs_name.empty()) {

		cout << "\t\t Компрессорные станции \n\n";

		cout << "Название: " << cs_chr.cs_name << '\n';
		cout << "Число цехов: " << cs_chr.cs_num << '\n';
		cout << "Число рабочих цехов: " << cs_chr.work_cs << '\n';
		cout << "Коэффициент эффективности: " << cs_chr.efc << '\n';
	}
	else {
		cout << "\t\t Компрессорные станции	\n";
	}
}

void edit_pipe(pipe& pipe_chr) {
	if (pipe_chr.pipe_name.empty()) {        
		cout << "Труба не была создана\n";
	}
	else {
		cout << "Введите длину трубы: \n";
		cin >> pipe_chr.dlina;

		while (cin.fail() || cin.peek() != '\n' || pipe_chr.dlina < 0) {
			cin.clear();
			cin.ignore(1000, 'n');
			cout << "Ввод некорректный.Введите длину трубы : \n";
			cin >> pipe_chr.dlina;
		}

		cout << "Введите диаметр трубы: \n";

		cin >> pipe_chr.diameter;

		while (cin.fail() || cin.peek() != '\n' || pipe_chr.diameter < 0) {
			cin.clear();
			cin.ignore(1000, 'n');
			cout << "Ввод некорректный.Введите диаметр трубы : \n";
			cin >> pipe_chr.diameter;
		}

		cout << "В эксплуатации[1/0]?:  \n";
		cin >> pipe_chr.mntn;

		while (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ввод некоректный. : ";
			cin >> pipe_chr.mntn;
		}
	}
}


void edit_cs(CS& cs_chr) {
	if (cs_chr.cs_name.empty()) {
		cout << "Компрессорная станция не была создана\n";
	}
	else {
		cout << "Введите число цехов:";
		cin >> cs_chr.cs_num;

		while (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ввод некорректный. Введите число цехов:  \n";
			cin >> cs_chr.cs_num;
		}

		cout << "Введите число рабочих цехов: \n";
		cin >> cs_chr.work_cs;

		while (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ввод некорректный. Введите число рабочих цехов:  \n";
			cin >> cs_chr.work_cs;
		}

		cout << " Введите коэффициент эффективности: \n";
		cin >> cs_chr.efc;
		
		while (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ввод некорректный. Введите коэффициент эффективности:  \n";
			cin >> cs_chr.efc;
		} 
	}

}

void save_pipe(pipe& pipe_chr, ofstream& write) {
	if (write.is_open()) {
		write << pipe_chr.pipe_name << endl;
		write << pipe_chr.dlina << endl;
		write << pipe_chr.diameter << endl;
		write << pipe_chr.mntn << endl;
	}
	else {
		cout << "Неполадки!";
	}
	cout << "Данные успешно сохранены." << endl;
}

void save_cs(CS& cs_chr, ofstream& write) {
	if (out.is_open()) {
		write << cs_chr.cs_name << endl;
		write << cs_chr.cs_num << endl;
		write << cs_chr.work_cs << endl;
		write << cs_chr.efc << endl;
	}
	else {
		cout << "Неполадки!";
	}
	cout << "Данные успешно сохранены." << endl;
}

void load_pipe(pipe& obj_pipe, ifstream& read) {
	if (read.is_open()) {
		read >> pipe_chr.name;
		read >> pipe_chr.length;
		read >> pipe_chr.diameter;
		read >> pipe_chr.maintenance;
	}
	else {
		cout << "Неполадки!";
	}
	cout << "Данные успешно загружены." << endl;
}

void load_сs(CS& cs_chr, ifstream& read) {
	if (read.is_open()) {
		read >> cs_chr.cs_name;
		read >> cs_chr.cs_num;
		read >> cs_chr.work_cs;
		read >> cs_chr.efc;
	}
	else {
		cout << "Неполадки!";
	}
	cout << "Данные успешно загружены." << endl;
}

int main() {

	setlocale(LC_ALL, "Russian");
	
	cout << "\tБазовые сущности трубопроводного транспорта газа или нефти\n\n";

	pipe pipe_chr;
	CS ch_chr;

	ofstream out;		
	ifstream read;		
	string line;

	while (1) {
		int option;

		menu();
		cin >> clear;
		cin >> option;

		while (cin.fail() || cin.peek() != '\n' || option < 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Введённый вариант отсутствует, попытайтесь снова, пожалуйста: ";
			cin >> option;
		}
		switch (option) {
		case 1:
			add_pipe(pipe_chr);
			break;
		case 2:
			add_cs(cs_chr);
			break;
		case 3:
			overview(pipe_chr, cs_chr);
			break;
		case 4:
			edit_pipe(pipe_chr);
			break;
		case 5:
			edit_cs(cs_chr);
			break;
		case 6:
			write.open("file.txt");
			write.close();
			if (!pipe_chr.pipe_name.empty()) {
				write.open("file.txt", ios_base::app);
				write << "pipe\n";
				save_pipe(pipe_chr, write);
				write.close();
			}
			if (!cs_chr.cs_name.empty()) {
				write.open("Data.txt", ios_base::app);
				write << "comp_station\n";
				save_cs(cs_chr, write);
				write.close();
			}
			break;
		case 7:
			read.open("Data.txt");
			if (read.peek() == ifstream::traits_type::eof()) {  
				cout << "Данные не были найдены";
			}
			else {
				while (getline(read, line)) {
					if (line.find("pipe") != string::npos) {
						load_pipe(pipe_chr, read);
					}
					if (line.find("comp_station") != string::npos) {
						load_сs(cs_chr, read);
					}
				}
			}
			break;
		case 0:
			cout << "Выход";
			exit(0);
		default:
			cout << "Выберите операцию \n";
			break;
		}
	}
	return 0;
}




