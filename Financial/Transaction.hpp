#ifndef TRANSACTION_HPP_
#define TRANSACTION_HPP_

#include <string>
#include "Account.hpp"
#include "Money.hpp"

enum TransactionState {
	COMPLETED,
	PENDING,
	FAILED
};

class Transaction {
	//TODO Implement members as needed
private:
	static int NextTransactionID;
	int TransID;
	TransactionState state;
	Money TransAmount;
	Account* FromAccount;
	Account* ToAccount;
	Transaction& operator=(const Transaction &other);
    Transaction(const Transaction &other);
public:
	Transaction(Account* fromAccount, Account* toAccount, Money amount);
	bool performTransaction();
	TransactionState getState() const;
	Money getAmount() const;
	Account* getFromAccount() const;
	Account* getToAccount() const;
	int getID() const;
	virtual ~Transaction();
};

#endif /* TRANSACTION_HPP_ */
