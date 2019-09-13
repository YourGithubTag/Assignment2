#include "Transaction.hpp"
#include <string>

int Transaction::NextTransactionID = 1;

Transaction::Transaction(Account* fromAccount, Account* toAccount, Money amount) {
	//TODO Implement
	this->TransID = Transaction::NextTransactionID++;
	this->state = PENDING;
	this->FromAccount = fromAccount;
	this->ToAccount = toAccount;

	if (Account::aboveZero(amount)) {
		this->TransAmount = amount;
	}
	else {
		this->TransAmount = Money(0,0);
	}

}

bool Transaction::performTransaction(){
	//TODO Implement
	if ((FromAccount->amountValid(TransAmount, true)) && (ToAccount->amountValid(TransAmount,false)) ) {
		FromAccount->withdrawMoney(TransAmount);
		ToAccount->depositMoney(TransAmount);
		this->state = COMPLETED;
		return true;
	}

	else {
		this->state = FAILED;
		return false;
	}
}

TransactionState Transaction::getState() const {
	//TODO Implement
	return this->state;
}

Money Transaction::getAmount() const {
	//TODO Implement
	return this->TransAmount;
}

Account* Transaction::getToAccount() const {
	//TODO Implement
	return this->ToAccount;
}

Account* Transaction::getFromAccount() const {
	//TODO Implement
	return this->FromAccount;
}


int Transaction::getID() const {
	//TODO Implement
	return this->TransID;
}

Transaction::~Transaction() {
	// TODO implement
}

