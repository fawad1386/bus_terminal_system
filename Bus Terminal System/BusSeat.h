class node {
public:
	string name;
	int number;
	node* next;
	bool isBooked;
	node() {
		name = "";
		number = 0;
		next = NULL;
		isBooked = false;
	}
	node(string a, int n) {
		name = a;
		next = NULL;
		number = n;
		isBooked = true;
	}
};
class busSeat {
	node* head;
	int totalSeat;
    int seatNum = 1;
	int booked;
public:
	int bookSeat(string); //THIS WILL BOOK A SEAT IN BUS
	bool cancelSeat(int); //THIS WILL UPDATE VALUE AT A SPECIFIC LOCATION
	void showSeats(); //TO DISPLAY COMPLET LINKED LIST
	int getTotal();//TO GET TOTAL NUMBER OF SEATS
	int getBooked();//TO GET TOTAL BOOKED 
	//constructor
	busSeat() {
		head = NULL;
		totalSeat = 10;
		booked = 0;
	}
};
int busSeat::bookSeat(string name) {
	if (seatNum >= totalSeat||seatNum<1) {
		cout << "Seat cant be booked \n";
		return 0;
	}
	node* newNode = new node(name, seatNum);
	if (head == NULL) {
		head = newNode;
		seatNum++;
		booked++;
		return head->number;
	}
	node* temp = head;
	while (temp->next != NULL) {
		if (!temp->isBooked) {
			temp->name = name;
			temp->isBooked = true;
			booked++;
			return temp->number;
		}
		temp = temp->next;
	}
	if (!temp->isBooked) {
		temp->name = name;
		temp->isBooked = true;
		booked++;
		return temp->number;
	}
	temp->next = newNode;
	seatNum++;
	booked++;
	return newNode->number;
}
bool busSeat::cancelSeat(int num) {
	if (head == NULL) {
		cout << "No seat is booked in this bus yet\n";
		return 0;
	}
	if (head->number == num) {
		char res = NULL;
		cout << "seat : '" << head->number << " is booked on name of :" << head->name << ". you sure to cancel this seat ? (Y/N)" << endl;
		cin >> res;
		if (res == 'Y' || res == 'y') {
			head->isBooked = false;
			head->name = "";
			booked--;
			return 1;
		}
		else if (res == 'N' || res == 'n') {
			return 0;
		}
	}
	else {
		node* temp = head;
		while (temp != NULL) {
			if (temp->number == num) {
				char res = NULL;
				cout << "seat : '" << temp->number << "' is booked on name of :" << temp->name << ". you sure to cancel this seat ? (Y/N)" << endl;
				cin >> res;
				while (res != 'Y' && res != 'y' && res != 'N' && res != 'n') {
					cout << "Invalid input --- enter 'y' or 'Y' for YES and 'n' or 'N' for NO\n";
					cin >> res;
				}
				if (res == 'Y' || res == 'y') {
					temp->isBooked = false;
					temp->name = "";
					temp = temp->next;
					booked--;
					return 1;
				}
				else if (res == 'N' || res == 'n') {
					return 0;
				}
			}
			temp = temp->next;
		}
	}
}
void busSeat::showSeats() {
	if (head == NULL) {
		cout << "list is empty";
		return;
	}
	node* temp = head;
	while (temp != NULL) {
		if (temp->isBooked) {
			cout << " Seat Number : " << temp->number << " is booked by :" << temp->name << endl;
		}
		else {
			cout << " Seat Number : " << temp->number << " is not booked" << endl;
		}
		temp = temp->next;
	}
}
int busSeat::getTotal() {
	return totalSeat;
}
int busSeat::getBooked() {
	return booked;
}