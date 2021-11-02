#pragma once
#include <string> 
#include "Ticket.h" 
using namespace std;
class Screen { 
protected:
	int nTicketPrice; // 티켓 가격
	int nRowMax, nColMax; // 좌석 행과 열 최대 값
	int nCurrentReservedId; // 발급된 마지막 예약 번호
	Ticket ** pSeatArray; // 스크린 좌석에 대한 티켓 배열 
	string strMovieName; // 스크린 상영중인 영화 제목 
	Ticket* checkReservedID(int id);  // 예약 번호 확인
	int reservednumber = 99; //예약번호
	int num[10][10] = {0};

public: 
	Screen(string name, int price, int r, int c);
	void showSeatMap(); // 좌석 예약 여부 맵으로 보기 
	virtual void showMovieMenu();     // 영화 예매 메뉴 
	virtual void showMovieInfo() = 0;  // 영화 소개 정보 
	void reserveTicket();
	void cancelReservation(); // 좌석 예약 취소하기
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
