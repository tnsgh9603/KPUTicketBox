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
	virtual Screen* selectMenu(); // �󿵰� �޴� ( 1��, 2��, 3��) 
};
class KpuTicketBox : public TicketBox {
	EuropeScreen* pEuropeScreen;
	AsiaScreen* pAsiaScreen;
	PremiumScreen* pPremiumScreen;
public:
	void Initialize();
	Screen* selectMenu();
};

