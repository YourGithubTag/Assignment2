#include <string>
#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_

class Customer {
private:
	// TODO add members as needed
	static int Gid;
	std::string Name;
	int id;
	Customer& operator=(const Customer &other);
    Customer(const Customer &other);

public:
	Customer(const std::string &name);
	std::string getName() const;
	int getID() const;
	virtual ~Customer();
};

#endif /* CUSTOMER_HPP_ */
