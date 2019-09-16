#include "FinancialServicesSystem.hpp"
#include <iostream>
#include <vector>

FinancialServicesSystem::FinancialServicesSystem() {
//constructing the Financial service system
}

std::string FinancialServicesSystem::author(){
	//The author ID, Nikhil KUmar
	return "nkmu576";
}

bool FinancialServicesSystem::addCustomer(Customer* customer) {
//Function which adds a customer to the customers vector
	int ID = customer->getID();
	//verifying that the customer does not already exist in the customers vector
	if (verifyCustomer(ID)) {

		return false;
	}
	else {
		this->customers.push_back(customer); //adding the customer to the vector
		return verifyCustomer(ID);
	}
}

bool FinancialServicesSystem::addAccount(Account* account) {
	//Function which adds an account to the account vector
	int ID = account->getAccountID();
	//verifying if the customer exists first
	if (verifyCustomer(account->getCustomerID())) {
		//verifying that the account doesnt already exist in the account vector
		if (verifyAccount(ID)) {
			return false;
		}
		else {
			this->accounts.push_back(account); //adding to the account vector
			return verifyAccount(ID);
		}
	}
	return false;
}

bool FinancialServicesSystem::addTransaction(Transaction* transaction) {
////Function which adds a Transaction to the Transaction vector
	int ID = transaction->getID();
		//checking to see if the transaction doesnt exist in the vector and that the to and from accounts associated with the transaction exists
	if (!(verifyTransaction(ID)) && (verifyAccount( transaction->getToAccount()->getAccountID() ) ) && (verifyAccount( transaction->getFromAccount()->getAccountID() ) ) ) {
			this->transactions.push_back(transaction); //adding transaction to the vector
			return verifyTransaction(ID);
	}
	else {
		return false;
	}
}

std::vector<Transaction*>  FinancialServicesSystem::transactionSort(std::vector<Transaction*> toSort) {
//function which uses a bubble sort to sort a transaction vector in terms of the transaction ID
	std::vector<Transaction*>  v;
	//if the vector is empty, return an empty vector
	if (v == toSort) {
		return v;
	}
	//bubble sort logic
	for (unsigned int i =0; i <toSort.size(); i++) {
		for (unsigned int j =0; j < toSort.size()-i-1; j++) {
			if (toSort[j]->getID() > toSort[j+1]->getID()) {
				Transaction* temp = toSort[j+1];
				toSort[j+1] = toSort[j];
				toSort[j] = temp;
			}
		}
	}

	return toSort; //returning sorted vector
}

std::vector<Transaction*> FinancialServicesSystem::performPendingTransactions() {
//Function which obtains all pending transaction then performs all pending transactions
	std::vector<Transaction*> v = getTransactions(PENDING); //Pending transactions vector
	v = transactionSort(v);
	std::vector<Transaction*> completed;

	//looping through all transactions
	for (unsigned int i=0; i < v.size(); i++ ) {

			Transaction* transaction = v[i];
			//checking if the transaction is valid
			if (transaction->validTransaction()){

				transaction->performTransaction(); //performing transaction
				completed.push_back(transaction); //placing in a new vector

			}
			else {
				transaction->performTransaction();//performing failed transaction
			}
	}
	return completed;//returning completed transactions
}

Money FinancialServicesSystem::getCustomerBalance(int customerID) const {
//Function which goes through all customer accounts and returns the total balance among them
	Money runningTotal = Money(0,0);
	//looping through the accounts vector
	for ( unsigned int i=0; i < accounts.size(); i++ ) {
		Account* account = accounts[i];
		//checking if it is the customers account
		if (account->getCustomerID() == customerID){
			//checking if the balance is below zero
			if (!(Account::aboveZero(account->getBalance() ) )){
				runningTotal.subtract( account->getAbsoluteBalance() );//subtracting the absolute balance from a running total
			}
			else {
				runningTotal.add(account->getBalance()); //adding the balance to a running total
			}
		}

	}
	return runningTotal; //returning the total balance
}

bool FinancialServicesSystem::verifyCustomer(int customerID) const {
//Function which verifies if the customer exists in the customers vector
	for (unsigned int i=0; i < customers.size(); i++ ) {
		Customer* customer = customers[i];
		if (customer->getID() == customerID){
			return true; //customer does exist
		}
	}
	return false; //customer doesnt exist
}

bool FinancialServicesSystem::verifyAccount(int accountID) const {
//Function which verifies if the account exists in the account vector
	for (unsigned int i=0; i < accounts.size(); i++ ) {
			Account* account = accounts[i];
			if (account->getAccountID() == accountID){
				return true; //Account does exist
			}
		}
		return false; //Account doesnt exist
}

bool FinancialServicesSystem::verifyTransaction(int transactionID) const {
//Function which verifies if the Transaction exists in the Transaction vector
	for (unsigned int i=0; i < transactions.size(); i++ ) {

				Transaction* transaction = transactions[i];
				if (transaction->getID() == transactionID){
					return true; //Transaction does exist
				}
			}
			return false; //Transaction doesnt exist
}

std::vector<Account*> FinancialServicesSystem::getAccounts() const {
	//function which gets the accounts vector
	std::vector<Account*> v = accounts;
	return v;
}

std::vector<Customer*> FinancialServicesSystem::getCustomers() const {
	//function which gets the customers vector
	std::vector<Customer*> v = customers;
	return v;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions() const {
	//function which gets the Transactions vector
	std::vector<Transaction*> v = transactions;
	return v;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions(TransactionState state) const {
	//function which returns the specific transactions of a certain state
	std::vector<Transaction*> v;
	//looping through all transactions
	for (unsigned int i=0; i < transactions.size(); i++ ) {
					Transaction* transaction = transactions[i];
					//getting the transaction of a specific state
					if (transaction->getState() == state){
						v.push_back(transaction); //adding the transaction to a vector
					} else {
					}
				}
	return v; //returning all transactions of a specific state

}

FinancialServicesSystem::~FinancialServicesSystem() {

}

