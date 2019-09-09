#include "SavingsAccount.hpp"
//TODO Implement the SavingsAccount class

SavingsAccount::SavingsAccount(const int customerID) : Account(-1) {
	// TODO implement
}

bool SavingsAccount::withdrawMoney(Money amount) {
	// TODO implement
	Money Demerit(2,0);
	if (amountValid(amount)) {
			this->Balance.subtract(amount);
			if (this->BonusVal.getDollars >= 0){
				this->BonusVal.subtract(Demerit);
			}
			else ()
		}

	else {
		return false;
	}
}

bool SavingsAccount::depositMoney(Money amount) {
	// TODO implement
	if (amountValid(amount)) {
		Money bonus = getBonusValue();

			if (isSecond) {
				amount  = amount.add(bonus);
				isSecond = false;
			}
			else {
				isSecond = true;
			}

		this->Balance.add(amount);
		return true;
		}

	else {
		return false;
	}
}

Money SavingsAccount::getBonusValue() const {
	// TODO implement
	Money m;
	return m;
}

SavingsAccount::~SavingsAccount() {
	// TODO implement
}


