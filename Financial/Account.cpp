#include "Account.hpp"
int Account::NextAccountID = 0;
Account::Account(const int customerID) {
	// TODO implement
	this->CustomerID = customerID;
	this->AccountID = Account::NextAccountID++;
}

int Account::getAccountID() const {
	// TODO implement
	return this->AccountID;
}

int Account::getCustomerID() const {
	// TODO implement
	return this->CustomerID;
}

Money Account::getBalance() const {
	// TODO implement
	//Money m(-1,-1);
	return this->Balance;
}

bool Account::aboveZero(Money amount) {
	if (amount.asCents() >= 0) {
		return true;
	}
	else {
		return false;
	}
}

Money Account::getAbsoluteBalance() const {
	int invert = 0;
	if (this->Balance.asCents() < 0) {
		invert = -1 * (this->Balance.asCents());
		return Money(0,invert);
	}
	else {
		return this->Balance;
	}

}
Account::~Account() {
	// TODO implement
}

