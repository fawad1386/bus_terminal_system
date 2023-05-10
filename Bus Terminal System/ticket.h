#pragma once
account_cl acc;
class ticket {
	bus bus;
public:
	bool bookSeat();
	bool cancelSeat();
	bool showAll();
};
bool ticket::bookSeat() {
	bool isfound=false;
	ifstream fin;
	fin.open(fname);
	ofstream fout, foutTic;
	fout.open("temp.txt", ios::trunc);
	foutTic.open("account.txt", ios::trunc);
	string busName;
	cout << "pls enter the number of bus in which to book seat\n";
	cin.ignore();
//	cin >> busName;
	getline(cin, busName);
	if (fin.fail()) {
		cout << "File not opening\n";
		return 0;
	}
	else {
		while (fin.read((char*)&bus, sizeof(bus))) {
			if (bus.getNum() == busName) {
				int n;
				cout << "enter name of coustomer\n";
				getline(cin, busName);
				n = bus.bookSeat(busName);
				isfound = true;
				acc.incAcc(bus.getFare());
				acc.incTicket();
				foutTic.write((char*)&acc, sizeof(acc));
				cout << "seat booked and Seat number is "<< n<< endl;
			}
			fout.write((char*)&bus, sizeof(bus));
		}
	}
	if (!isfound) {
		cout << "Bus not found\n";
	}
	fin.close();
	fout.close();
    remove("manager.txt");
	rename("temp.txt", "manager.txt");
	system("pause");
	return 1;
}
bool ticket::cancelSeat() {
	bool isfound = false;
	ifstream fin;
	fin.open(fname);
	ofstream fout,foutTic;
	foutTic.open("account.txt",ios::trunc);
	fout.open("temp.txt", ios::trunc);
	string busName;
	cout << "pls enter the number of bus in which to cancel seat\n";
	cin.ignore();
	getline(cin, busName);
	int num;
	cout << "seat number to cancel\n";
	cin >> num;
	if (fin.fail()) {
		cout << "File not opening\n";
		return 0;
	}
	else {
		while (fin.read((char*)&bus, sizeof(bus))) {
			if (bus.getNum() == busName) {
				bus.getSeat().cancelSeat(num);
				cout << "seat canceled and 15% of ticket fare will be deducted\n";
				int i = bus.getFare() - ((bus.getFare() * 15) / 100);
				acc.decAcc(i);
				acc.decTicket();
				foutTic.write((char*)&acc, sizeof(acc));
				cout << "coustomer will get RS " << i << endl;
			}
			fout.write((char*)&bus, sizeof(bus));
		}
	}
	fin.close();
	fout.close();
	remove("manager.txt");
	rename("temp.txt", "manager.txt");
	system("pause");
	return 1;

}
bool ticket::showAll() {
	bool isfound = false;
	ifstream fin;
	fin.open(fname);
	string busName;
	if (fin.fail()) {
		cout << "File not opening\n";
		return 0;
	}
	else {
		cout << "pls enter the number of bus in which to book seat\n";
		cin.ignore();
		cout << busName;
		getline(cin, busName);
		while (fin.read((char*)&bus, sizeof(bus))) {
			if (bus.getNum() == busName) {
				cout<<bus.getBookedSeat();
				bus.showSeats();
				system("pause");
				isfound = true;
			}
		}
		fin.close();
		return 1;
	}
}