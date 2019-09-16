#include "CreditAccount.hpp"
//TODO Implement CreditAccount class

Money CreditAccount::limit = Money(5000,0);

CreditAccount::CreditAccount(const int customerID) : Account(customerID) {
	//Constructing the Credit Account
}

bool CreditAccount::withdrawMoney(Money amount) {
//Function which contains the logic to withdraw money
	//checking if the amount is valid for the withdraw
		if (amountValid(amount, true)) {
			this->Balance.subtract(amount); //withdrawing
			return true; // valid withdraw
		}
	return false; //invalid withdraw
}

bool CreditAccount::depositMoney(Money amount) {
	//Function which contains the logic to deposit money
	//checking if the amount is valid for the deposit
	if (amountValid(amount,false)) {
		this->Balance.add(amount); //depositing
		return true;// valid deposit
	}
	return false; //invalid deposit
}

bool CreditAccount::amountValid(Money amount , bool isWithdraw) {
//Function which contains logic which checks if the amount is valid
	//checking for non-negative amount
	if ( this->aboveZero(amount) ) {
		//Deposit logic
		if (!isWithdraw) {
			//checking to see if the deposit does not increase the account balance above the limit
			if ((this->Balance.asCents() + amount.asCents()) <= limit.asCents()) {
				return true; //deposit is valid
			}
			else {
				return false; //invalid deposit
			}
		}
		//Withdraw logic
		else if (isWithdraw){
			return true; //withdraw is valid
		}
	}
	return false; //invalid amount
}

CreditAccount::~CreditAccount() {

}
