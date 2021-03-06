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
	virtual Screen* selectMenu(); // 상영관 메뉴 ( 1관, 2관, 3관) 
};
class KpuTicketBox : public TicketBox {
	EuropeScreen* pEuropeScreen;
	AsiaScreen* pAsiaScreen;
	PremiumScreen* pPremiumScreen;
public:
	void Initialize();
	Screen* selectMenu();
};

