#include "FinancialServicesSystem.hpp"
#include <iostream>
#include <vector>

FinancialServicesSystem::FinancialServicesSystem() {
	// TODO implement
		std::vector<Account*> accounts;
		std::vector<Customer*> customers;
		std::vector<Transaction*> transactions;
}

std::string FinancialServicesSystem::author(){
	// TODO implement
	return "nkmu576";
}

bool FinancialServicesSystem::addCustomer(Customer* customer) {
	// TODO implement
	int ID = customer->getID();

	if (verifyCustomer(ID)) {

		return false;
	}
	else {
		this->customers.push_back(customer);
		return verifyCustomer(ID);
	}
}

bool FinancialServicesSystem::addAccount(Account* account) {
	// TODO implement
	int ID = account->getAccountID();

	if (verifyCustomer(account->getCustomerID())) {
		if (verifyAccount(ID)) {
			return false;
		}
		else {
			this->accounts.push_back(account);
			return verifyAccount(ID);
		}
	}
	return false;
}

bool FinancialServicesSystem::addTransaction(Transaction* transaction) {
	// TODO implement
	int ID = transaction->getID();
	if (!(verifyTransaction(ID)) && (verifyAccount( transaction->getToAccount()->getAccountID() ) ) && (verifyAccount( transaction->getFromAccount()->getAccountID() ) ) ) {
			this->transactions.push_back(transaction);
			return verifyTransaction(ID);
	}
	else {
		return false;
	}
}

std::vector<Transaction*>  FinancialServicesSystem::transactionSort(std::vector<Transaction*> toSort) {
	std::vector<Transaction*>  v;
	if (v == toSort) {
		return v;
	}
	for (int i =0; i <toSort.size(); i++) {
		for (int j =0; j < toSort.size()-i-1; j++) {
			if (toSort[j]->getID() > toSort[j+1]->getID()) {
				Transaction* temp = toSort[j+1];
				toSort[j+1] = toSort[j];
				toSort[j] = temp;
			}
		}
	}

	return toSort;
}

std::vector<Transaction*> FinancialServicesSystem::performPendingTransactions() {
	// TODO implement
	std::vector<Transaction*> v = getTransactions(PENDING);
	v = transactionSort(v);
	std::vector<Transaction*> d;


	for (int i=0; i < v.size(); i++ ) {

			Transaction* transaction = v[i];

			if (transaction->validTransaction()){

				transaction->performTransaction();
				d.push_back(transaction);

			}
			else {
				transaction->performTransaction();
			}
	}
	return d;
}

Money FinancialServicesSystem::getCustomerBalance(int customerID) const {
	// TODO implement

	Money runningTotal = Money(0,0);
	for (int i=0; i < accounts.size(); i++ ) {
		Account* account = accounts[i];

		if (account->getCustomerID() == customerID){
			if (account->getBalance().asCents() < 0){
				runningTotal.subtract( account->getAbsoluteBalance() );
			}
			else {
				runningTotal.add(account->getBalance());
			}
		}

	}
	return runningTotal;
}

bool FinancialServicesSystem::verifyCustomer(int customerID) const {
	// TODO implement
	for (int i=0; i < customers.size(); i++ ) {
		Customer* customer = customers[i];
		if (customer->getID() == customerID){
			return true;
		}
	}
	return false;
}

bool FinancialServicesSystem::verifyAccount(int accountID) const {
	// TODO implement
	//std::vector<Account*> Accountz = getAccounts();
	for (int i=0; i < accounts.size(); i++ ) {
			Account* account = accounts[i];
			if (account->getAccountID() == accountID){
				return true;
			}
		}
		return false;
}

bool FinancialServicesSystem::verifyTransaction(int transactionID) const {
	// TODO implement
	for (int i=0; i < transactions.size(); i++ ) {

				Transaction* transaction = transactions[i];
				if (transaction->getID() == transactionID){
					return true;
				}
			}
			return false;
}

std::vector<Account*> FinancialServicesSystem::getAccounts() const {
	// TODO implement
	std::vector<Account*> v = accounts;
	return v;
}

std::vector<Customer*> FinancialServicesSystem::getCustomers() const {
	// TODO implement
	std::vector<Customer*> v = customers;
	return v;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions() const {
	// TODO implement
	std::vector<Transaction*> v = transactions;
	return v;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions(TransactionState state) const {
	// TODO implement
	std::vector<Transaction*> v;

	for (int i=0; i < transactions.size(); i++ ) {
					Transaction* transaction = transactions[i];
					if (transaction->getState() == state){
						v.push_back(transaction);
					} else {
					}
				}
	return v;

}

FinancialServicesSystem::~FinancialServicesSystem() {
	// TODO implement
}

