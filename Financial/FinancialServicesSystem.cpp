#include "FinancialServicesSystem.hpp"
#include <iostream>
#include <vector>

FinancialServicesSystem::FinancialServicesSystem() {
	// TODO implement
}

std::string FinancialServicesSystem::author(){
	// TODO implement
	return "nkmu576";
}

bool FinancialServicesSystem::addCustomer(Customer* customer) {
	// TODO implement
	return false;
}

bool FinancialServicesSystem::addAccount(Account* account) {
	// TODO implement
	return false;
}

bool FinancialServicesSystem::addTransaction(Transaction* transaction) {
	// TODO implement
	return false;
}

std::vector<Transaction*> FinancialServicesSystem::performPendingTransactions() {
	// TODO implement
	std::vector<Transaction*> v;
	return v;
}

Money FinancialServicesSystem::getCustomerBalance(int customerID) const {
	// TODO implement
	return Money(-1,-1);
}

bool FinancialServicesSystem::verifyCustomer(int customerID) const {
	// TODO implement
	return false;
}

bool FinancialServicesSystem::verifyAccount(int accountID) const {
	// TODO implement
	return false;
}

bool FinancialServicesSystem::verifyTransaction(int transactionID) const {
	// TODO implement
	return false;
}

std::vector<Account*> FinancialServicesSystem::getAccounts() const {
	// TODO implement
	std::vector<Account*> v;
	return v;
}

std::vector<Customer*> FinancialServicesSystem::getCustomers() const {
	// TODO implement
	std::vector<Customer*> v;
	return v;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions() const {
	// TODO implement
	std::vector<Transaction*> v;
	return v;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions(TransactionState state) const {
	// TODO implement
	std::vector<Transaction*> v;
	return v;
}

FinancialServicesSystem::~FinancialServicesSystem() {
	// TODO implement
}

