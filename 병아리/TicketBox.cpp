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
	// Screen(��ȭ����, Ƽ�ϰ���, �¼�(nRowMax), �¼�(nColMax)) 
	pEuropeScreen = new EuropeScreen("������ ������", 10000, 10, 10);
	pAsiaScreen = new AsiaScreen("�пպ���", 12000, 10, 10);
	pPremiumScreen = new PremiumScreen("������ �̽�������", 30000, 6, 6);
}
Screen* KpuTicketBox::selectMenu()
{
	cout << "------------------------------\n";
	cout << "       �󿵰� ���� �޴�\n";
	cout << "------------------------------\n";
	cout << "1.  ����\t ��ȭ 1��\n";
	cout << "2. �ƽþ�\t ��ȭ 2��\n";
	cout << "3. �����̾�\t ��ȭ 3��\n\n";
	cout << "����(1~3) �׿� ���� : ";
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