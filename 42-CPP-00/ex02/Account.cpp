/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 05:57:40 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/18 19:32:55 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;

int Account::_totalNbWithdrawals = 0;

int Account::_totalNbDeposits = 0;

int Account::_totalAmount = 0;

void Account::_displayTimestamp(void)
{
	std::time_t t = time(NULL);
	tm *now = localtime(&t);

	char buffer[20];
	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", now);

	std::cout << "[" << std::string(buffer) << "] ";
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->getNbAccounts();
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";";
	this->_amount = initial_deposit;
	t::_totalAmount += initial_deposit;
	std::cout << "amount:" << this->checkAmount();
	std::cout << ";";
	std::cout << "created" << std::endl;
	t::_nbAccounts++;
}

Account::~Account(void)
{
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";";
	std::cout << "amount:" << this->checkAmount();
	std::cout << ";";
	std::cout << "closed" << std::endl;
	t::_nbAccounts--;
}

bool Account::makeWithdrawal(int withdrawal)
{
	t::_displayTimestamp();
	if ((this->_amount - withdrawal) < 0)
	{
		std::cout << "index:" << this->_accountIndex;
		std::cout << ";";
		std::cout << "p_amount:" << this->checkAmount();
		std::cout << ";";
		std::cout << "withdrawal:" << "refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << "index:" << this->_accountIndex;
		std::cout << ";";
		std::cout << "p_amount:" << this->checkAmount();
		this->_nbWithdrawals++;
		t::_totalNbWithdrawals++;
		std::cout << ";";
		std::cout << "withdrawal:" << withdrawal;
		this->_amount -= withdrawal;
		t::_totalAmount -= withdrawal;
		std::cout << ";";
		std::cout << "amount:" << this->checkAmount();
		std::cout << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::makeDeposit(int deposit)
{
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";";
	std::cout << "p_amount:" << this->checkAmount();
	this->_nbDeposits++;
	t::_totalNbDeposits++;
	this->_amount += deposit;
	t::_totalAmount += deposit;
	std::cout << ";";
	std::cout << "deposit:" << deposit;
	std::cout << ";";
	std::cout << "amount:" << this->checkAmount();
	std::cout << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

int Account::getNbAccounts(void)
{
	return (t::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (t::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (t::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (t::_totalNbWithdrawals);
}

void Account::displayStatus(void) const
{
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";";
	std::cout << "amount:" << this->checkAmount();
	std::cout << ";";
	std::cout << "deposits:" << this->_nbDeposits;
	std::cout << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void)
{
	t::_displayTimestamp();
	std::cout << "accounts:" << t::getNbAccounts();
	std::cout << ";";
	std::cout << "total:" << t::getTotalAmount();
	std::cout << ";";
	std::cout << "deposits:" << t::getNbDeposits();
	std::cout << ";";
	std::cout << "withdrawals:" << t::getNbWithdrawals() << std::endl;
}
