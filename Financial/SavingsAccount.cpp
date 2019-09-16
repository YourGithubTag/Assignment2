#include "SavingsAccount.hpp"
//TODO Implement the SavingsAccount class

SavingsAccount::SavingsAccount(const int customerID) : Account(customerID) {
	//Creating the savings account
	this->isSecond = false; //setting the 2nd transaction counter
	this->BonusVal = Money(10,0); //Creating the Bonus Value
}

bool SavingsAccount::withdrawMoney(Money amount) {
	//Function which contains logic for withdrawing money in the saving account
	Money Demerit(2,0); //Demerit created to reduce Bonus Value

			//CHecking if the amount is valid
			if (amountValid(amount, true)) {

				this->Balance.subtract(amount);
					//CHecking if the bonus value is less than the Demerit
					if (this->BonusVal.asCents() < Demerit.asCents()) {
									this->BonusVal = Money(0,0); //Bonus value is set to zero
								}
					else {
						this->BonusVal.subtract(Demerit); //reducing the bonus value
					}
					return true;

				}

		return amountValid(amount, true);
}

bool SavingsAccount::depositMoney(Money amount) {
//Function which contains logic for depositing money in the saving account
	//Checking if the amount is valid
	if (amountValid(amount,false)) {
		//getting the bonus to add.
		Money bonus = getBonusValue();
			//logic to check if 2nd transaction is occuring
			if (isSecond) {
				amount.add(bonus); //adding the bonus to the amount
				isSecond = false; //the next transaction is no longer the 2nd
			}
			else {
				isSecond = true; //the next transaction will be the 2nd
			}
		this->Balance.add(amount); //depositing the money

		}

		return amountValid(amount, true);
}

Money SavingsAccount::getBonusValue() const {
	//returning the bonus value
	return this->BonusVal;
}

bool SavingsAccount::amountValid(Money amount, bool isWithdraw) {
//Function which contains the logic that checks if the withdraw or deposit is indeed valid.

		//checking if the amount is above zero
		if ( this->aboveZero(amount) ) {
			//checking whether the transaction is a deposit or withdraw
			if (!isWithdraw) {
				return true; //Valid transaction
			}
			//checking whether the transaction is a deposit or withdraw
			else if (isWithdraw){
				//logic checking if the amount can be withdrawn where the savings will not be negative
				if (this->Balance.asCents() >= amount.asCents()) {
					return true; //Valid transaction
				}
				else {
					return false; //Invalid transaction
				}
			}
		}
		return false; //Invalid transaction
}

SavingsAccount::~SavingsAccount() {

}


