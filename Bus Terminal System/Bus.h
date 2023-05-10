#pragma once
class bus{
	string busNum;
	string to, from;
	int time;
	busSeat seat;
	bool isPresent;
	int fare;
public:
	int bookSeat(string);
	bool cancelSeat(int);
	void showSeats();
	void setNum(string);
	void setTo(string);
	void setFrom(string);
	void setTime(int);
	void setFair(int);
	bool is_Present();
	void changeStatus();
	busSeat getSeat();
	string getNum();
	string getTo();
	string getFrom();
	int getTime();
	int getBookedSeat();
	int getTotalSeat();
	int getFare();
	bus() {
		busNum.reserve(10);
		to.reserve(3);
		from.reserve(3);
		time = 0;
		isPresent = true;
	}
};
int bus::bookSeat(string name) {
	return seat.bookSeat(name);
}
bool bus::cancelSeat(int num) {
	return seat.cancelSeat(num);
}
void bus::showSeats() {
	seat.showSeats();
}
void bus::setNum(string num) {
	busNum = num;
}
void bus::setTo(string newTo) {
	to = newTo;
}
void bus::setFrom(string newFrom) {
	from = newFrom;
}
void bus::setTime(int newTime) {
	time = newTime;
}
void bus::setFair(int val) {
	fare = val;
}
string bus::getNum() {
	return busNum;
}
string bus::getTo() {
	return to;
}
string bus::getFrom() {
	return from;
}
int bus::getTime() {
	return time;
}
bool bus::is_Present() {
	return isPresent;
}
int bus::getBookedSeat() {
	return seat.getBooked();
}
void bus::changeStatus() {
	isPresent = !isPresent;
}
int bus::getTotalSeat() {
	return seat.getTotal();
}
busSeat bus::getSeat() {
	return seat;
}
int bus::getFare() {
	return fare;
}