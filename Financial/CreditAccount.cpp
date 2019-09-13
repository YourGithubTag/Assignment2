#include "CreditAccount.hpp"
//TODO Implement CreditAccount class

Money CreditAccount::limit = Money(5000,0);

CreditAccount::CreditAccount(const int customerID) : Account(customerID) {
	// TODO implement
}

bool CreditAccount::withdrawMoney(Money amount) {
	// TODO implement
	bool valid =  amountValid(amount);
		if (valid) {
			this->Balance.subtract(amount);
			return true;
		}
	return false;
}

bool CreditAccount::depositMoney(Money amount) {
	// TODO implement
	bool valid =  amountValid(amount);
	if (valid && ((this->Balance.asCents() + amount.asCents()) <= limit.asCents() )) {
		this->Balance.add(amount);
		return true;
	}
	return false;
}

CreditAccount::~CreditAccount() {
	// TODO implement
}
