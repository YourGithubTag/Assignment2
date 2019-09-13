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

			if (amountValid(amount, true)) {

				this->Balance.subtract(amount);

					if (this->BonusVal.asCents() < Demerit.asCents()) {
									this->BonusVal = None;
								}
					else {
						this->BonusVal.subtract(Demerit);
					}
					return true;

				}

		return amountValid(amount, true);
}

bool SavingsAccount::depositMoney(Money amount) {

	if (amountValid(amount,false)) {
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

		return amountValid(amount, true);
}

Money SavingsAccount::getBonusValue() const {
	// TODO implement0
	return this->BonusVal;
}

bool SavingsAccount::amountValid(Money amount, bool isWithdraw) {

		if ( this->aboveZero(amount) ) {
			if (!isWithdraw) {
				return true;
			}

			else if (isWithdraw){
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

SavingsAccount::~SavingsAccount() {
	// TODO implement
}


