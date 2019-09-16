#include "Customer.hpp"
#include <string>

int Customer::Gid = 0;
Customer::Customer(const std::string &name) {
	//constructing the customer object
	this->Name = name;
	this->id = Customer::Gid++; //setting the customerID
}

std::string Customer::getName() const {
	//returning customer name
	return this->Name;
}

int Customer::getID() const {
	//returning customer ID
	return this->id;
}

Customer::~Customer() {

}

