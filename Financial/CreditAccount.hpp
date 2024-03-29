#include "Account.hpp"

#ifndef CREDITACCOUNT_HPP_
#define CREDITACCOUNT_HPP_

class CreditAccount : public Account {
//TODO Implement members as needed
private:
	static Money limit;
	CreditAccount& operator=(const CreditAccount &other);
    CreditAccount(const CreditAccount &other);
public:
	CreditAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool depositMoney(Money amount);
	virtual bool amountValid(Money amount, bool isWithdraw);
	virtual ~CreditAccount();
};

#endif /* CREDITACCOUNT_HPP_ */
