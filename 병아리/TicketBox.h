#pragma once
#include <iostream>
#include "Ticket.h"
#include "Screen.h"
using namespace std;
class TicketBox {
public:

	EuropeScreen* pEuropeScreen;
	AsiaScreen* pAsiaScreen;
	PremiumScreen* pPremiumScreen;
	void Initialize();
	virtual Screen* selectMenu(); // 惑康包 皋春 ( 1包, 2包, 3包) 
};
class KpuTicketBox : public TicketBox {
	EuropeScreen* pEuropeScreen;
	AsiaScreen* pAsiaScreen;
	PremiumScreen* pPremiumScreen;
public:
	void Initialize();
	Screen* selectMenu();
};

