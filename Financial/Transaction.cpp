#include "Transaction.hpp"
#include <string>

int Transaction::NextTransactionID = 1;

Transaction::Transaction(Account* fromAccount, Account* toAccount, Money amount) {
	//Setting the different VAriables to the inputs
	this->TransID = Transaction::NextTransactionID++;
	this->state = PENDING;
	this->FromAccount = fromAccount;
	this->ToAccount = toAccount;
	//Checking if the amount is above zero
	if (Account::aboveZero(amount)) {
		this->TransAmount = amount;
	}
	else {
		//negative values set to zero
		this->TransAmount = Money(0,0);
	}

}

bool Transaction::validTransaction() const{
	//FUnction to check if the transaction is valid, using the amountValid Function
	if ((FromAccount->amountValid(TransAmount, true)) && (ToAccount->amountValid(TransAmount,false)) ) {
		return true;
	}
	else {
		return false;
	}

}

bool Transaction::performTransaction(){
	//Function which performs the transaction.
	if (validTransaction() ) {
		//Withdrawing and depositing from one account to the other, then setting the transaction to Complete
		FromAccount->withdrawMoney(TransAmount);
		ToAccount->depositMoney(TransAmount);
		this->state = COMPLETED;
		return true;
	}
	else {
		//the transaction is invalid, thus it fails.
		this->state = FAILED;
		return false;
	}
}

TransactionState Transaction::getState() const {
	//returning the state
	return this->state;
}

Money Transaction::getAmount() const {
	//returning the Amount
	return this->TransAmount;
}

Account* Transaction::getToAccount() const {
	//returning the Depositing Account
	return this->ToAccount;
}

Account* Transaction::getFromAccount() const {
	//returning the Withdrawing Account
	return this->FromAccount;
}


int Transaction::getID() const {
	//returning the  Transaction ID
	return this->TransID;
}

Transaction::~Transaction() {
	// TODO implement
}

