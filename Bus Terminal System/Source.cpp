#include"Header.h"
#include"BusSeat.h"
#include"Bus.h"
#include"account.h"
#include"manager.h"
#include"ticket.h"
void schedule();
void ticketing();
void account();
void management();
//void main() {
//
//}
//void main() {
//	bus bus,bus2;
//	cout<<bus.bookSeat("usama");
//	cout << bus.bookSeat("asd");
//	bus.showSeats();
//	bus.cancelSeat(2);
//	bus.showSeats();
//	cout << bus.bookSeat("usama");
////	bus.bookSeat("asd");
//	bus.showSeats();
//	cout << "------------------\n";
//	bus2.bookSeat("usama");
//	bus2.bookSeat("asd");
//	bus2.showSeats();
//	bus2.cancelSeat(2);
//	bus2.showSeats();
//	bus2.bookSeat("afd");
//	bus2.bookSeat("usama");
//	bus2.showSeats();
// }
void main() {
	int menuRes;
	bool cnt = true;;
	while (cnt) {
		system("cls");
		cout << "\n\t\t\t\t--- BUS TERMINAL MANAGEMENT SYSTEM ---\n";
		cout << "\n\n\n\n\t\t\t\t\t\t\t\tMENU\n";
		cout << "\n\t\t\t\t\t\t\t\t 1. Check Schedule";
		cout << "\n\t\t\t\t\t\t\t\t 2. Ticketing";
		cout << "\n\t\t\t\t\t\t\t\t 3. Accounts";
		cout << "\n\t\t\t\t\t\t\t\t 4. Terminal Management";
		cout << "\n\t\t\t\t\t\t\t\t 0. Exit\n";
		cin >> menuRes;
		while (menuRes < 0 || menuRes>4) {
			cout << "INVALID OPTION CHOSEN... TRY AGAIN\n";
			cin >> menuRes;
		}
		switch (menuRes) {
		case 1:
			schedule();
			break;
		case 2:
			ticketing();
			break;
		case 3:
			account();
			break;
		case 4:
			management();
			break;
		case 0:
			cnt = false;
			exit(1);
		}
	}
}
void schedule() {
	bus bus;
	ifstream fin;
	fin.open(fname);
	if (fin.fail()) {
		cout << "File not found\n";
		cin.ignore((numeric_limits< streamsize >::max)(), '\n');
		return;
	}
	else {
		cout << "\t -- THESE BUSES AER CURRENTLY AT TERMINAL --\n";
		cout << "\t\t\t---TODAY SCHEDULE---\n";
		cout << "\tBUS NUMBER\t\tFROM\t\tTO\t\tTIME\n\n";
		while (fin.read((char*)&bus, sizeof(bus))) {
			if (bus.is_Present()) {
				cout << "\t" << bus.getNum();
				cout << "\t\t\t" << bus.getFrom();
				cout << "\t\t" << bus.getTo();
				cout << "\t\t"<<bus.getTime() << endl;
			}
		}
		fin.close();
	}
	system("pause");
	main();
}
void ticketing() {
	ticket t;
	int menuRes;
	bool cnt = true;;
	while (cnt) {
		system("cls");
		cout << "\n\t\t\t\t---       MANAGEMENT       ---\n";
		cout << "\n\n\n\n\t\t\t\t\t\t\t\tMENU\n";
		cout << "\n\t\t\t\t\t\t\t\t 1. Book Seat";
		cout << "\n\t\t\t\t\t\t\t\t 2. Cancel Seat";
		cout << "\n\t\t\t\t\t\t\t\t 3. Check Booking";
		cout << "\n\t\t\t\t\t\t\t\t 0. Exit\n";
		cin >> menuRes;
		while (menuRes < 0 || menuRes>3) {
			cout << "INVALID OPTION CHOSEN... TRY AGAIN\n";
			cin >> menuRes;
		}
		switch (menuRes) {
		case 1:
			t.bookSeat();
			break;
		case 2:
			t.cancelSeat();
			break;
		case 3:
			t.showAll();
			break;
		case 0:
			cnt = false;
			main();
		}
	}
	system("pause");
}
void account() {
	ifstream finTic;
	finTic.open("account.txt");
	if (finTic.fail()) {
		cout << "account file is not opening\n";
		return;
	}
	finTic.read((char*)&acc, sizeof(acc));
	int menuRes;
	bool cnt = true;;
	while (cnt) {
		system("cls");
		cout << "\n\t\t\t\t---       ACCOUNTS       ---\n";
		cout << "\n\n\n\n\t\t\t\t\t\t\t\tMENU\n";
		cout << "\n\t\t\t\t\t\t\t\t 1. Check Total Balence";
		cout << "\n\t\t\t\t\t\t\t\t 2. Total Seats Booked";
		cout << "\n\t\t\t\t\t\t\t\t 0. Exit\n";
		cin >> menuRes;
		while (menuRes < 0 || menuRes>2) {
			cout << "INVALID OPTION CHOSEN... TRY AGAIN\n";
			cin >> menuRes;
		}
		switch (menuRes) {
		case 1:
			cout << "total balence is : " << acc.getBal() << endl;
			system("pause");
			break;
		case 2:
			cout << "total seat booked : "<<acc.getTic()<<endl;
			system("pause");
			break;
		case 0:
			cnt = false;
			main();
		}
	}
}
void management() {
	string uPas = "";
	char ch;
	cout << "ONLY AUTHORIZED PERSONS CAN ACCESS THIS---- ENTER PASWORD TO ACCESS\n";
	ch = _getch();
	while (ch != 13) {
		uPas.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	string tPas="pas123";
	while (uPas!=tPas) {
		cout << "Wrong Pasword !!\n Enter pasword again OR type '0' to exit\n";
		string uPas = "";
		ch = _getch();
		while (ch != 13) {
			uPas.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		if (uPas=="0") {
			return;
		}
		if (uPas == tPas) {
			break;
		}
	}
	manager manager;
	int menuRes;
	bool cnt = true;;
	while (cnt) {
		system("cls");
		cout << "\n\t\t\t\t---       MANAGEMENT       ---\n";
		cout << "\n\n\n\n\t\t\t\t\t\t\t\tMENU\n";
		cout << "\n\t\t\t\t\t\t\t\t 1. Add New Bus";
		cout << "\n\t\t\t\t\t\t\t\t 2. Incoming And Outgoing";
		cout << "\n\t\t\t\t\t\t\t\t 3. Check Bus Status";
		cout << "\n\t\t\t\t\t\t\t\t 4. Current Situation At Terminal";
		cout << "\n\t\t\t\t\t\t\t\t 0. Exit\n";
		cin >> menuRes;
		while (menuRes < 0 || menuRes>4) {
			cout << "INVALID OPTION CHOSEN... TRY AGAIN\n";
			cin >> menuRes;
		}
		switch (menuRes) {
		case 1:
			manager.addBus();
			break;
		case 2:
			manager.inOut();
			break;
		case 3:
			manager.busStatus();
		
			break;
		case 4:
			manager.read();
			break;
		case 0:
			cnt = false;
			main();
		}
	}
}
