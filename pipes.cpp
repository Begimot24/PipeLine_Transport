#include <iostream>
#include <fstream> 
#include <sstream> 
#include <string> 

using namespace std;

struct pipe {
	string name;
	int length;
	int diameter;
	bool maintenance;
};

struct comp_station {
	string name;
	int num_department;
	int work_department;
	double efficiency;
};

string get_str() {
	string str;
	cin >> ws;
	getline(std::cin, str);
	return str;
}

void menu() {
	cout << "					    Ââåäèòå íåîáõîäèìóþ âàì öèôðó                                               " << '\n';
	cout << "1. Äîáàâèòü òðóáó" << '\n';
	cout << "2. Äîáàâèòü ÊÑ" << '\n';
	cout << "3. Ïðîñìîòð âñåõ îáúåêòîâ" << '\n';
	cout << "4. Ðåäàêòèðîâàòü òðóáó" << '\n';
	cout << "5. Ðåäàêòèðîâàòü ÊÑ" << '\n';
	cout << "6. Ñîõðàíèòü" << '\n';
	cout << "7. Çàãðóçèòü" << '\n';
	cout << "0. Âûõîä" << '\n' << '\n';
}

void add_pipe(pipe& obj_pipe) {
	cout << "Ââåäèòå íàçâàíèå òðóáû: ";
	obj_pipe.name = get_str();
	cout << "Ââåäèòå äëèíó òðóáû: ";
	cin >> obj_pipe.length;
	while (cin.fail() || cin.peek() != '\n' || obj_pipe.length < 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Äàííûå ââåäåíû íåâåðíî, ïîïðîáóéòå åù¸ ðàç: ";
		cin >> obj_pipe.length;
	}
	cout << "Ââåäèòå äèàìåòð òðóáû: ";
	cin >> obj_pipe.diameter;
	while (cin.fail() || cin.peek() != '\n' || obj_pipe.diameter < 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Äàííûå ââåäåíû íåâåðíî, ïîïðîáóéòå åù¸ ðàç: ";
		cin >> obj_pipe.diameter;
	}
	cout << "Ïîäëåæèò ëè îíà ðåìîíòó?: ";
	cin >> obj_pipe.maintenance;
	while (cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Äàííûå ââåäåíû íåâåðíî, ïîïðîáóéòå åù¸ ðàç: ";
		cin >> obj_pipe.maintenance;
	}
}

void add_comp_station(comp_station& obj_comp_station) {
	cout << "Ââåäèòå íàçâàíèå ñòàíöèè: ";
	obj_comp_station.name = get_str();
	cout << "Ââåäèòå êîëè÷åñòâî öåõîâ: ";
	cin >> obj_comp_station.num_department;
	while (cin.fail() || cin.peek() != '\n' || obj_comp_station.num_department < 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Äàííûå ââåäåíû íåâåðíî, ïîïðîáóéòå åù¸ ðàç: ";
		cin >> obj_comp_station.num_department;
	}
	cout << "Ââåäèòå êîëè÷åñòâî ðàáîòàþùèõ öåõîâ: ";
	cin >> obj_comp_station.work_department;
	while (cin.fail() || cin.peek() != '\n' ||
		obj_comp_station.work_department < 0 || obj_comp_station.work_department > obj_comp_station.num_department) { // ïðîâåðêà ðàáî÷èõ ñòàíöèé 
		cin.clear();																								  // äîëæíî áûòü ìåíüøå
		cin.ignore(1000, '\n');
		cout << "Äàííûå ââåäåíû íåâåðíî, ïîïðîáóéòå åù¸ ðàç: ";
		cin >> obj_comp_station.work_department;
	}
	cout << "Ââåäèòå åãî ýôôåêòèâíîñòü: ";
	cin >> obj_comp_station.efficiency;
	while (cin.fail() || cin.peek() != '\n' || obj_comp_station.efficiency < 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Äàííûå ââåäåíû íåâåðíî, ïîïðîáóéòå åù¸ ðàç: ";
		cin >> obj_comp_station.efficiency;
	}
}

void view(pipe& obj_pipe, comp_station& obj_comp_station) {
	if (!obj_pipe.name.empty()) {
		cout << "					    Òðóáà                                                                 " << '\n';
		cout << "Íàçâàíèå òðóáû - " << obj_pipe.name << '\n';
		cout << "Äëèíà òðóáû - " << obj_pipe.length << '\n';
		cout << "Äèàìåòð òðóáû - " << obj_pipe.diameter << '\n';
		if (obj_pipe.maintenance == 1) {
			cout << "Ðåìîíò?: Yes\n";
		}
		else {
			cout << "Ðåìîíò?: No\n";
		}
	}
	else {
		cout << "						Òðóáà îòñóòñòâóåò\n";
	}
	if (!obj_comp_station.name.empty()) {
		cout << "					    Ñòàíöèÿ                                                                 " << '\n';
		cout << "Íàçâàíèå ñòàíöèè - " << obj_comp_station.name << '\n';
		cout << "Êîëè÷åñòâî öåõîâ - " << obj_comp_station.num_department << '\n';
		cout << "Êîëè÷åñòâî ðàáîòàþùèõ öåõîâ - " << obj_comp_station.work_department << '\n';
		cout << "Ýôôåêòèâíîñòü ñòàíöèè - " << obj_comp_station.efficiency << '\n';
	}
	else {
		cout << "						ÊÑ îòñóòñòâóåò\n";
	}
}

void change_pipe(pipe& obj_pipe) {
	if (obj_pipe.name.empty()) {        // ïðîâåðêà íà íàëè÷èå òðóáû
		cout << "Âû íå ââåëè òðóáó\n";
	}
	else {
		cout << "Ðàáîòàåò òðóáà èëè íåò(0 - íå ðàáîòàåò, 1 - ðàáîòàåò): ";
		cin >> obj_pipe.maintenance;
		while (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Äàííûå ââåäåíû íåâåðíî, ïîïðîáóéòå åù¸ ðàç: ";
			cin >> obj_pipe.maintenance;
		}
	}
}

void change_comp_station(comp_station& obj_comp_station) {
	if (obj_comp_station.name.empty()) {	// ïðîâåðêà íà íàëè÷èå ÊÑ
		cout << "Âû íå ââåëè ÊÑ\n";
	}
	else {
		cout << "Ñêîëüêî öåõîâ çàäåéñòâîâàíî â ðàáîòå: ";
		cin >> obj_comp_station.efficiency;
		while (cin.fail() || cin.peek() != '\n' || obj_comp_station.efficiency < 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Äàííûå ââåäåíû íåâåðíî, ïîïðîáóéòå åù¸ ðàç: ";
			cin >> obj_comp_station.efficiency;
		}
	}
}

void save_pipe(pipe& obj_pipe, ofstream& out) {
	if (out.is_open()) {
		out << obj_pipe.name << endl;
		out << obj_pipe.length << endl;
		out << obj_pipe.diameter << endl;
		out << obj_pipe.maintenance << endl;
	}
	else {
		cout << "Îøèáêà!";
	}
	cout << "Äàííûå òðóáû çàãðóæåíû â ôàéë." << endl;
}

void save_comp_station(comp_station& obj_comp_station, ofstream& out) {
	if (out.is_open()) {
		out << obj_comp_station.name << endl;
		out << obj_comp_station.num_department << endl;
		out << obj_comp_station.work_department << endl;
		out << obj_comp_station.efficiency << endl;
	}
	else {
		cout << "Îøèáêà!";
	}
	cout << "Äàííûå ÊÑ çàãðóæåíû â ôàéë." << endl;
}

void download_pipe(pipe& obj_pipe, ifstream& read) {
	if (read.is_open()) {
		read >> obj_pipe.name;
		read >> obj_pipe.length;
		read >> obj_pipe.diameter;
		read >> obj_pipe.maintenance;
	}
	else {
		cout << "!";
	}
	cout << "Äàííûå òðóáû âûãðóæåíû èç ôàéëà." << endl;
}

void download_comp_station(comp_station& obj_comp_station, ifstream& read) {
	if (read.is_open()) {
		read >> obj_comp_station.name;
		read >> obj_comp_station.num_department;
		read >> obj_comp_station.work_department;
		read >> obj_comp_station.efficiency;
	}
	else {
		cout << "Îøèáêà!";
	}
	cout << "Äàííûå ÊÑ âûãðóæåíû èç ôàéëà." << endl;
}

int main() {
	setlocale(LC_ALL, "Rus"); // Ïåðåâîä âñåõ ñèìâîëîâ íà ðóññêèé ÿçûê
	cout << "\tБазовые сущности трубопроводного транспорта газа или нефти\n\n";
	pipe obj_pipe;
	comp_station obj_comp_station;
	ofstream out;		// îáúåêò ôàéëà äëÿ çàïèñè
	ifstream read;		// îáúåêò ôàéëà äëÿ ÷òåíèÿ
	string line;        // îáúåêò ôàéëà äëÿ ÷òåíèÿ ôàéëà ïîñòðî÷íî
	while (true) {
		int choice;
		menu();  // âûçûâàåì ìåíþ
		cin.clear();
		cin >> choice;
		while (cin.fail() || cin.peek() != '\n' || choice < 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Äàííûå ââåäåíû íåâåðíî, ïîïðîáóéòå åù¸ ðàç: ";
			cin >> choice;
		}
		switch (choice) {
		case 1:
			add_pipe(pipe_chr);
			break;
		case 2:
			add_comp_station(cs_chr);
			break;
		case 3:
			view(pipe_chr, cs_chr);
			break;
		case 4:
			edit_pipe(pipe_chr);
			break;
		case 5:
			edit_cs(cs_chr);
			break;
		case 6:
			out.open("file.txt");
			out.close();
			if (!obj_pipe.name.empty()) {
				out.open("file.txt", ios_base::app);
				out << "pipe\n";
				save_pipe(obj_pipe, out);
				out.close();
			}
			if (!obj_comp_station.name.empty()) {
				out.open("file.txt", ios_base::app);
				out << "comp_station\n";
				save_comp_station(obj_comp_station, out);
				out.close();
			}
			break;
		case 7:
			read.open("file.txt");
			if (read.peek() == std::ifstream::traits_type::eof()) {  // óñëîâèå ïóñòîòû ôàéëà
				cout << "Ôàéë ïóñò!";
			}
			else {
				while (getline(read, line)) {
					if (line.find("pipe") != string::npos) {
						download_pipe(obj_pipe, read);
					}
					if (line.find("comp_station") != string::npos) {
						download_comp_station(obj_comp_station, read);
					}
				}
			}
			break;
		case 0:
			cout << "Âûõîä èç ïðîãðàììû";
			exit(0);
		default:
			cout << "Ââåäèòå ÷èñëà îò 0 äî 7\n";
			break;
		}
	}
	return 0;
}