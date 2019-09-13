#include "CreditAccount.hpp"
//TODO Implement CreditAccount class

Money CreditAccount::limit = Money(5000,0);

CreditAccount::CreditAccount(const int customerID) : Account(customerID) {
	// TODO implement
}

bool CreditAccount::withdrawMoney(Money amount) {
	// TODO implement
		if (amountValid(amount, true)) {
			this->Balance.subtract(amount);
			return true;
		}
	return false;
}

bool CreditAccount::depositMoney(Money amount) {
	// TODO implement
	if (amountValid(amount,false)) {
		this->Balance.add(amount);
		return true;
	}
	return false;
}

bool CreditAccount::amountValid(Money amount , bool isWithdraw) {
	if ( this->aboveZero(amount) ) {
		if (!isWithdraw) {
			if ((this->Balance.asCents() + amount.asCents()) <= limit.asCents()) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (isWithdraw){
			return true;
		}
	}
	return false;
}

CreditAccount::~CreditAccount() {
	// TODO implement
}
