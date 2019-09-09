#include "Transaction.hpp"
#include <string>

Transaction::Transaction(Account* fromAccount, Account* toAccount, Money amount) {
	//TODO Implement
}

bool Transaction::performTransaction(){
	//TODO Implement
	return false;
}

TransactionState Transaction::getState() const {
	//TODO Implement
	return FAILED;
}

Money Transaction::getAmount() const {
	//TODO Implement
	return Money(-1,-1);
}

Account* Transaction::getToAccount() const {
	//TODO Implement
	return 0;
}

Account* Transaction::getFromAccount() const {
	//TODO Implement
	return 0;
}


int Transaction::getID() const {
	//TODO Implement
	return 0;
}

Transaction::~Transaction() {
	// TODO implement
}

