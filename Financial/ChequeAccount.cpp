#include "ChequeAccount.hpp"
//TODO Implement ChequeAccount class


Money ChequeAccount::limit = Money(3000,0);
ChequeAccount::ChequeAccount(const int customerID) : Account(customerID) {
	// TODO implement
	this->TransactionsFee = Money(1,0);
	this->TPointer = &TransactionsFee;

}

bool ChequeAccount::withdrawMoney(Money amount) {
	// TODO implement
	amount.add(TransactionsFee);
	bool valid = amountValid(amount);

	if ( (this->Balance.asCents() >= amount.asCents() ) && (valid) ) {
		this->Balance.subtract(amount);
		this->TransactionsFee.add(Money(1,0));
		return true;
	}
	else {
		return false;
	}
}

bool ChequeAccount::depositMoney(Money amount) {
	// TODO implement
	bool valid = amountValid(amount);
	if (amount.asCents() <= limit.asCents()) {
		if (valid) {
			this->Balance.add(amount);
			return true;
		}
	}

	return false;
}

Money* ChequeAccount::getTransactionFee() const {
	// TODO implement
	return TPointer;
}

ChequeAccount::~ChequeAccount() {
	// TODO implement
}

