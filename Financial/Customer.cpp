#include "Customer.hpp"
#include <string>

int Customer::Gid = 0;
Customer::Customer(const std::string &name) {
	// TODO implement
	this->Name = name;
	this->id = Customer::Gid++;
}

std::string Customer::getName() const {
	// TODO implement
	return this->Name;
}

int Customer::getID() const {
	// TODO implement
	return this->id;
}

Customer::~Customer() {
	// TODO implement
}

