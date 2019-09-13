#include "Transaction.hpp"
#include <string>

int Transaction::NextTransactionID = 1;

Transaction::Transaction(Account* fromAccount, Account* toAccount, Money amount) {
	//TODO Implement
	this->TransID = Transaction::NextTransactionID++;
	this->state = PENDING;
	this->TransAmount = amount;
	this->FromAccount = fromAccount;
	this->ToAccount = toAccount;
}

bool Transaction::performTransaction(){
	//TODO Implement

	if (FromAccount->aboveZero(TransAmount)){
		if (FromAccount->amountValid(TransAmount) && ToAccount->amountValid(TransAmount) ){
				FromAccount->withdrawMoney(TransAmount);
				ToAccount->depositMoney(TransAmount);
	}

	return false;
	}
}

TransactionState Transaction::getState() const {
	//TODO Implement
	return this->state;
}

Money Transaction::getAmount() const {
	//TODO Implement
	return Money(-1,-1);
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

