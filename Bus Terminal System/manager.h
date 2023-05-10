#pragma once
string fname = "manager.txt";
class manager {
	bus bus;
public:
	void addBus();
	void read();
	void inOut();
	void busStatus();
};
void manager::addBus() {
	string strInput;
	int intInput;
	ofstream fout;
	fout.open(fname, ios::app);
	cout << "Enter the number of bus\n";
	cin >> strInput;
	bus.setNum(strInput);
	cout << "From where it will go\n";
	cin >> strInput;
	bus.setFrom(strInput);
	cout << "where to?\n";
	cin >> strInput;
	bus.setTo(strInput);
	cout << "Enter time of departure\n";
	cin >> intInput;
	bus.setTime(intInput);
	cout << "Enter fare of this bus\n";
	cin >> intInput;
	bus.setFair(intInput);
	fout.write((char*)&bus, sizeof(bus));
	fout.close();
}
void manager::read() {
	ifstream fin;
	fin.open(fname);
	if (fin.fail()) {
		cout << "File not found\n";
		system("pause");
	}
	else {
		while (fin.read((char*)&bus, sizeof(bus))) {
			cout << "\nNumber of bus is : " << bus.getNum() << endl;
			cout << "Bus is going from : " << bus.getFrom() << endl;
			cout << "Bus is going to  : " << bus.getTo() << endl;
			cout << "time of departure is : " << bus.getTime() << endl;
			cout << "Fare of bus is : " << bus.getFare() << endl;
			if (bus.is_Present()) {
				cout << "bus is present\n";
			}
			else {
				cout << "Bus is not at terminal\n";
			}
			cout << "---------------------------------------------------------------------\n";
		}
		fin.close();
	}
	system("pause");
}
void manager::inOut() {

	bool isFound = false;
	ifstream fin;
	fin.open(fname);
	ofstream fout;
	fout.open("temp.txt", ios::trunc);
	string bNum;
L1:
	cout << "Enter number of bus to change its status\n";
	cin >> bNum;
	while (fin.read((char*)&bus, sizeof(bus))) {
		if (bus.getNum() == bNum) {
			cout << "BUS FOUND\n";
			bus.changeStatus();
			fout.write((char*)&bus, sizeof(bus));
			isFound = true;
		}
		else {
			fout.write((char*)&bus, sizeof(bus));
		}
	}
	if (!isFound) {
		char res;
		cout << "BUS NOT FOUND ... TRY SEARCH AGAIN(Y/N)\n";
		cin >>res;
		while (res != 'Y' && res != 'y' && res != 'N' && res != 'n') {
			cout << "Invalid strInput --- enter 'y' or 'Y' for YES and 'n' or 'N' for NO\n";
			cin >> res;
		}
		if (res == 'Y' || res == 'y') {
			goto L1;
		}
	}
	fin.close();
	fout.close();
	remove("manager.txt");
	rename("temp.txt", "manager.txt");
}
void manager::busStatus() {
	string busN;
	bool isfound=false;
	cout << "Enter the number of bus\n";
	cin >> busN;
	ifstream fin;
	fin.open(fname);
	if (fin.fail()) {
		cout << "No bus file created yet\n";
		system("pause");
	}
	else {
		while (fin.read((char*)&bus, sizeof(bus))) {
			if (bus.getNum() == busN) {
				if (!bus.is_Present()) {
					cout << "This bus is not at terminal\n";
					break;
				}
				cout << "\t\t--BUS DETAILS--\n";
				cout << "BUS NUMBER\t\tFROM\t\tTO\t\tTIME\t\tFARE\t\tSEATS BOOKED YET\t\tAVAILABLE SEATS\n";
				cout <<  bus.getNum();
				cout << "\t\t\t" << bus.getFrom();
				cout << "\t\t" << bus.getTo();
				cout << "\t\t" << bus.getTime();
				cout << "\t\t" << bus.getFare();
				cout << "\t\t" << bus.getBookedSeat();
				cout << "\t\t\t\t" << bus.getTotalSeat() - bus.getBookedSeat() << endl;
				isfound = true;
				break;
			}
		}
		fin.close();
		if (!isfound) {
			cout << "BUS NOT FOUND-- \n";
		}
		system("pause");
	}
}