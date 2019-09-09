#include "CreditAccount.hpp"
//TODO Implement CreditAccount class

CreditAccount::CreditAccount(const int customerID) : Account(-1) {
	// TODO implement
}

bool CreditAccount::withdrawMoney(Money amount) {
	// TODO implement
	return false;
}

bool CreditAccount::depositMoney(Money amount) {
	// TODO implement
	bool valid =  amountValid(amount);
	if (valid) {
		this->Balance.subtract(amount);
	}
}

CreditAccount::~CreditAccount() {
	// TODO implement
}
