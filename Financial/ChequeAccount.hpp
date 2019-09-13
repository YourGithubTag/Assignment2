#include "Account.hpp"

#ifndef CHEQUEACCOUNT_HPP_
#define CHEQUEACCOUNT_HPP_

class ChequeAccount : public Account {
//TODO Implement members as needed
private:
	Money TransactionsFee;
	Money* TPointer;
	static Money limit;
	ChequeAccount& operator=(const ChequeAccount &other);
    ChequeAccount(const ChequeAccount &other);
public:
	ChequeAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool depositMoney(Money amount);
	virtual bool amountValid(Money amount, bool isWithdraw);
	Money* getTransactionFee() const;
	virtual ~ChequeAccount();
};

#endif /* CHEQUEACCOUNT_HPP_ */
