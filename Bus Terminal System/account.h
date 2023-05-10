#pragma once
class account_cl {
	int balence;
	int ticket;
public:
	void incAcc(int);
	void incTicket();
	void decAcc(int);
	void decTicket();
	int getBal();
	int getTic();
	account_cl() {
		balence = ticket = 0;
	}
};
void account_cl::incAcc(int price) {
	balence += price;
}
void account_cl::incTicket() {
	ticket++;
}
void account_cl::decTicket() {
	ticket--;
}
void account_cl::decAcc(int price) {
	balence -= price;
}
int account_cl::getBal() {
	return balence;
}
int account_cl::getTic() {
	return ticket;
}