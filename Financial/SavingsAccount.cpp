#include "SavingsAccount.hpp"
//TODO Implement the SavingsAccount class

SavingsAccount::SavingsAccount(const int customerID) : Account(customerID) {
	// TODO implement
	Money Bonus(10,0);
	this->isSecond = false;
	this->BonusVal = Bonus;
}

bool SavingsAccount::withdrawMoney(Money amount) {
	// TODO implement
	Money Demerit(2,0);
	Money None(0,0);
	bool valid =  amountValid(amount);
	if (valid) {
			this->Balance.subtract(amount);

			if (!(amountValid(Balance))) {
				this->Balance = None;
			}

			if ((this->BonusVal.getDollars) > Demerit.getDollars()){
				this->BonusVal.subtract(Demerit);
			}

			else if ((this->BonusVal.getDollars) < Demerit.getDollars()) {
				this->BonusVal = None;
			}
		}
	return valid;
}

bool SavingsAccount::depositMoney(Money amount) {
	// TODO implement
	bool valid =  amountValid(amount);
	if (valid) {
		Money bonus = getBonusValue();

			if (isSecond) {
				amount  = amount.add(bonus);
				isSecond = false;
			}
			else {
				isSecond = true;
			}
		this->Balance.add(amount);
		}
		return valid;
}

Money SavingsAccount::getBonusValue() const {
	// TODO implement
	return this->BonusVal;
}

SavingsAccount::~SavingsAccount() {
	// TODO implement
}


