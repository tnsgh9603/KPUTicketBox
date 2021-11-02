#include <iostream>
#include "TicketBox.h"
#include "Screen.h"
using namespace std;




void TicketBox::Initialize()
{
	pEuropeScreen = nullptr;
	pAsiaScreen = nullptr;
	pPremiumScreen = nullptr;
}
Screen* TicketBox::selectMenu()
{
	return nullptr;
}
void KpuTicketBox::Initialize() {
	// Screen(영화제목, 티켓가격, 좌석(nRowMax), 좌석(nColMax)) 
	pEuropeScreen = new EuropeScreen("비포선 라이즈", 10000, 10, 10);
	pAsiaScreen = new AsiaScreen("패왕별희", 12000, 10, 10);
	pPremiumScreen = new PremiumScreen("프리즌 이스케이프", 30000, 6, 6);
}
Screen* KpuTicketBox::selectMenu()
{
	cout << "------------------------------\n";
	cout << "       상영관 메인 메뉴\n";
	cout << "------------------------------\n";
	cout << "1.  유럽\t 영화 1관\n";
	cout << "2. 아시아\t 영화 2관\n";
	cout << "3. 프리미엄\t 영화 3관\n\n";
	cout << "선택(1~3) 그외 종료 : ";
	int a;
	cin >> a;
	switch (a) {
	case 1:
		return pEuropeScreen;
		break;
	case 2:
		return	pAsiaScreen;
		break;
	case 3:
		return pPremiumScreen;
		break;
	default :
		return nullptr;
	}
}