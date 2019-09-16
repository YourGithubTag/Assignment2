#include "Account.hpp"
int Account::NextAccountID = 0;
Account::Account(const int customerID) {
	// Construting the Account object
	this->CustomerID = customerID; //setting the customersID
	this->AccountID = Account::NextAccountID++; //setting the AccountID from the nextID, then iterating NextID
}

int Account::getAccountID() const {
	// Getting AccountID
	return this->AccountID;
}

int Account::getCustomerID() const {
	// Getting CustomerID
	return this->CustomerID;
}

Money Account::getBalance() const {
	// Getting Balance
	return this->Balance;
}

bool Account::aboveZero(Money amount) {
	//Function which checks if the amount parameter is above zero or not.
	if (amount.asCents() >= 0) {
		return true;
	}
	else {
		return false;
	}
}

Money Account::getAbsoluteBalance() const {
	//function which returns the absolute balance, converting negative to positive.
	int invert = 0;
	if (this->Balance.asCents() < 0) {
		invert = -1 * (this->Balance.asCents()); //converting negative to positive
		return Money(0,invert);
	}
	else {
		return this->Balance;
	}

}
Account::~Account() {

}

