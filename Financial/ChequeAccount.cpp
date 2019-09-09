#include "ChequeAccount.hpp"
//TODO Implement ChequeAccount class

Money ChequeAccount::TransactionsFee = Money(1,0);
Money ChequeAccount::limit = Money(3000,0);
ChequeAccount::ChequeAccount(const int customerID) : Account(customerID) {
	// TODO implement

}

bool ChequeAccount::withdrawMoney(Money amount) {
	// TODO implement
	amount.add(TransactionsFee);
	bool valid = amountValid(amount);

	if (valid) {
		this->Balance.subtract(amount);

		if (!(amountValid(Balance))) {
			this->Balance = Money(0,0);
		}
	}
	return valid;
}

bool ChequeAccount::depositMoney(Money amount) {
	// TODO implement
	bool valid = amountValid(amount);
	if (amount.getDollars() <= limit.getDollars()) {
		if (valid) {
			this->Balance.add(amount);
			return true;
		}
	}
	return false;
}

Money* ChequeAccount::getTransactionFee() const {
	// TODO implement
	return &TransactionsFee;
}

ChequeAccount::~ChequeAccount() {
	// TODO implement
}

