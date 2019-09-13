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
	if ( amountValid(amount,true)) {
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
	if (amountValid(amount, false)) {
		this->Balance.add(amount);
		return true;
	}
	else {
		return false;
	}
}

bool ChequeAccount::amountValid(Money amount, bool isWithdraw) {
	if ( this->aboveZero(amount) ) {

			if (!isWithdraw) {
				if (amount.asCents() <= limit.asCents()) {
					return true;
				}
				else {
					return false;
				}
			}

			else if (isWithdraw){
				if (this->Balance.asCents() >= amount.asCents()) {
					return true;
				}
					else {
						return false;
					}
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

