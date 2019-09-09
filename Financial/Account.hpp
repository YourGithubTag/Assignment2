#ifndef ACCOUNT_HPP_
#define ACCOUNT_HPP_
#include "Money.hpp"
class Account{
//TODO Implement members as needed
private:
	static int NextAccountID;
	int CustomerID;
	int AccountID;
	Money Balance;
	Account& operator=(const Account &other);
	Account(const Account &other);
public:
	Account(const int customerID);
	virtual bool withdrawMoney(Money amount) = 0;
	virtual bool depositMoney(Money amount) = 0;
	static bool amountValid(Money amount) const;
	int getCustomerID() const;
	int getAccountID() const;
	Money getBalance() const;
	virtual ~Account();
};

#endif /* ACCOUNT_HPP_ */
