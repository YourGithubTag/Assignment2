#include "ChequeAccount.hpp"
//TODO Implement ChequeAccount class


Money ChequeAccount::limit = Money(3000,0);
ChequeAccount::ChequeAccount(const int customerID) : Account(customerID) {
	// Construting the Cheque Account object
	this->TransactionsFee = Money(1,0); //setting the transaction fee
	this->TPointer = &TransactionsFee; //setting the pointer to the transaction fee

}

bool ChequeAccount::withdrawMoney(Money amount) {
//Function which contains the logic to withdraw money
	//Checking if the amount is valid
	if (amountValid(amount,true) ) {
		amount.add(TransactionsFee); //adding the fee for withdrawals
		this->Balance.subtract(amount); //withdrawing
		this->TransactionsFee.add(Money(1,0)); //increasing the transaction fee
		return true;
	}
	else {
		return false;
	}
}

bool ChequeAccount::depositMoney(Money amount) {
//Function which contains the logic to deposit money
	//Checking if the amount is valid
	if (amountValid(amount, false)) {
		this->Balance.add(amount); //Depositing
		return true;
	}
	else {
		return false;
	}
}

bool ChequeAccount::amountValid(Money amount, bool isWithdraw) {
//Function which contains logic which checks if the amount is valid
	//checking for non-negative amount
	if ( this->aboveZero(amount) ) {
			//Deposit logic
			if (!isWithdraw) {
				//checking to see if the deposit is not larger than the limit
				if (amount.asCents() <= limit.asCents()) {
					return true;
				}
				else {
					return false;
				}
			}
			//Withdraw logic
			else if (isWithdraw){
				amount.add(TransactionsFee); //adding the transaction fee
				//checking if the withdraw will not leave the account negative
				if (this->Balance.asCents() >= amount.asCents()) {
					return true;
				}
					else {
						return false;
					}
				}
			}

	return false;

}

Money* ChequeAccount::getTransactionFee() const {
	//getting the pointer for the transaction fee
	return TPointer;
}

ChequeAccount::~ChequeAccount() {

}

