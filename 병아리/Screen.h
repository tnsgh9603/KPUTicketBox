#pragma once
#include <string> 
#include "Ticket.h" 
using namespace std;
class Screen { 
protected:
	int nTicketPrice; // Ƽ�� ����
	int nRowMax, nColMax; // �¼� ��� �� �ִ� ��
	int nCurrentReservedId; // �߱޵� ������ ���� ��ȣ
	Ticket ** pSeatArray; // ��ũ�� �¼��� ���� Ƽ�� �迭 
	string strMovieName; // ��ũ�� ������ ��ȭ ���� 
	Ticket* checkReservedID(int id);  // ���� ��ȣ Ȯ��
	int reservednumber = 99; //�����ȣ
	int num[10][10] = {0};

public: 
	Screen(string name, int price, int r, int c);
	void showSeatMap(); // �¼� ���� ���� ������ ���� 
	virtual void showMovieMenu();     // ��ȭ ���� �޴� 
	virtual void showMovieInfo() = 0;  // ��ȭ �Ұ� ���� 
	void reserveTicket();
	void cancelReservation(); // �¼� ���� ����ϱ�
}; 

class EuropeScreen :public Screen { 
public: 
	EuropeScreen(string name, int price, int r, int c) : Screen( name, price, r, c) {}
	void showMovieInfo();
	void showMovieMenu();
};
class AsiaScreen : public Screen { 
public: 
	AsiaScreen(string name, int price, int r, int c) : Screen(name, price, r, c) {} 
	void showMovieInfo();
	void showMovieMenu();
}; 

class PremiumScreen : public Screen {
public:
	PremiumScreen(string name, int price, int r, int c) : Screen(name, price, r, c) {}
	void showMovieInfo();
	void showMovieMenu();
}; 
