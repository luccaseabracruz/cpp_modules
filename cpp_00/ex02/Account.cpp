/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:25:26 by lucca             #+#    #+#             */
/*   Updated: 2026/08/13 17:40:27 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

// Public Member Functions
int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts << ';'
				<< "total:" << _totalAmount << ';'
				<< "deposits:" << _totalNbDeposits << ';'
				<< "withdrawals:" << _totalNbWithdrawals << '\n';
}

Account::Account(int initial_deposit)
	:	_accountIndex(_nbAccounts), _amount(initial_deposit),
		_nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ';'
				<< "amount:" << _amount << ';'
				<< "created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ';'
				<< "amount:" << _amount << ';'
				<< "closed\n";
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ';'
				<< "p_amount:" << _amount << ';';
	if (deposit <= 0)
	{
		std::cout << "refused\n";
		return ;
	}
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout	<< "deposit:" << deposit << ';'
				<< "amount:" << _amount << ';'
				<< "nb_deposits:" << _nbDeposits << '\n';
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ';'
				<< "p_amount:" << _amount << ';'
				<< "withdrawal:";
	if (withdrawal <= 0 || _amount - withdrawal < 0)
	{
		std::cout << "refused\n";
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout	<< withdrawal << ';'
				<< "amount:" << _amount << ';'
				<< "nb_withdrawals:" << _nbWithdrawals << '\n';
	return true;
}

int	Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "deposits:" << _nbDeposits << ';';
	std::cout << "withdrawals:" << _nbWithdrawals << '\n';
}

// Private Member Functions
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void){}

void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(NULL);
	std::tm *local = std::localtime(&now);
	char timestamp[16];

	std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", local);
	std::cout << '[' << timestamp << "] ";
}
