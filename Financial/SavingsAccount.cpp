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

			if (amountValid(amount) && (this->Balance.getCents() >= amount.getCents() )) {

				this->Balance.subtract(amount);

					if (this->BonusVal.getCents() < Demerit.getCents()) {
									this->BonusVal = None;
								}
					else {
						this->BonusVal.subtract(Demerit);
					}
					return true;
				}

		return false;
}

bool SavingsAccount::depositMoney(Money amount) {
	// TODO implement
	bool valid =  amountValid(amount);

	if (valid) {
		Money bonus = getBonusValue();

			if (isSecond) {
				amount.add(bonus);
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
	// TODO implement0
	return this->BonusVal;
}

SavingsAccount::~SavingsAccount() {
	// TODO implement
}


