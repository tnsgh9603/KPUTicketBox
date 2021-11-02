#include <iostream> 
#include <string> 
#include "Screen.h"
using namespace std;

Screen::Screen(string name, int price, int r, int c) {
	strMovieName = name;
	nRowMax = r;
	nColMax = c;
	nTicketPrice = price;
	pSeatArray = new Ticket * [nRowMax];
	for (int r = 0; r < nRowMax; r++) {
		pSeatArray[r] = new Ticket[nColMax];
	}
	for (int i = 0; i < nRowMax; i++) {
		for (int j = 0; j < nColMax; j++) {
			pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);
		}
	}
}
void EuropeScreen::showMovieInfo() {
	cout << "------------------------------\n";
	cout << "      [ 비포 선 라이즈 ]      \n";
	cout << "------------------------------\n";
	cout << " 영화관 : 유럽 영화 1관\n";
	cout << " 주인공 : 에단 호크, 줄리 델피\n";
	cout << " 줄거리 : 제시와 셀린느는 유럽 횡단 열차안에서 우연히 ...\n";
	cout << " 가격 : 10000\n";
}
void EuropeScreen::showMovieMenu()
{
	cout << "\n-----------------------------------\n";
	cout << "     영화 메뉴 - 비포 선 라이즈    \n";
	cout << "-----------------------------------\n";
	cout << "1. 상영 영화 정보\n";
	cout << "2. 좌석 예약 현황\n";
	cout << "3. 예약 하기\n";
	cout << "4. 예약 취소\n";
	cout << "7. 메인 메뉴 이동\n\n";
}
void AsiaScreen::showMovieInfo() {
	cout << "------------------------------\n";
	cout << "          [ 패왕별희 ]\n";
	cout << "------------------------------\n";
	cout << " 영화관 : 아시아 영화 2관\n";
	cout << " 주인공 : 장국영, 공리\n";
	cout << " 줄거리 : 어렸을 때부터 함께 경극을 해온 두지와 시투...\n";
	cout << " 가격 : 12000\n";
}
void AsiaScreen::showMovieMenu()
{
	cout << "\n-----------------------------------\n";
	cout << "        영화 메뉴 -  패왕별희      \n";
	cout << "-----------------------------------\n";
	cout << "1. 상영 영화 정보\n";
	cout << "2. 좌석 예약 현황\n";
	cout << "3. 예약 하기\n";
	cout << "4. 예약 취소\n";
	cout << "7. 메인 메뉴 이동\n\n";
}
void PremiumScreen::showMovieInfo() {
	cout << "------------------------------\n";
	cout << "     [ 프리즌 이스케이프 ]    \n";
	cout << "------------------------------\n";
	cout << " 영화관 : 프리미엄 영화 3관\n";
	cout << " 주인공 : 다니엘 래드클리프\n";
	cout << " 줄거리 : 인권운동가 팀과 스티븐은 억울한 판결로 투옥된다...\n";
	cout << " 가격 : 30000\n";
}
void PremiumScreen::showMovieMenu()
{
	cout << "\n-----------------------------------\n";
	cout << "     영화 메뉴 - 비포 선 라이즈    \n";
	cout << "-----------------------------------\n";
	cout << "1. 상영 영화 정보\n";
	cout << "2. 좌석 예약 현황\n";
	cout << "3. 예약 하기\n";
	cout << "4. 예약 취소\n";
	cout << "7. 메인 메뉴 이동\n\n";
}
void Screen::showSeatMap() {
	cout << "\t[ 좌석 예약 현황 ]\n\t";
	for (int k = 1; k <= nColMax; k++) {
		cout << "[" << k << "]";
	}
	cout << "\n";
	for (int i = 0; i < nRowMax; i++) {
		cout << "[" << i + 1 << "]\t";
		for (int j = 0; j < nColMax; j++) {
			cout << "[" << pSeatArray[i][j].getCheck() << "]";
		}
		cout << "\n";
	}
}
void Screen::showMovieMenu() {
}
void Screen::reserveTicket()
{
	cout << " [ 좌석 예약 ]\n";
	int row, col;
	cout << "좌석 행 번호 입력( 1 - " << nRowMax << " ): ";
	cin >> row;
	cout << "좌석 열 번호 입력( 1 - " << nColMax << " ): ";
	cin >> col;
	cout << "행[" << row << "]" << "열[" << col << "]" << ++reservednumber << " 예약 번호로 접수되었습니다.\n";
	pSeatArray[row - 1][col - 1].setCheck(SEAT_RESERVED_MARK);

	num[row][col] = reservednumber;
}
Ticket* Screen::checkReservedID(int id)
{
	//int tempid = id;;
	int check = 0;
	int tempi, tempj;
	for (int i = 0; i <= nRowMax; i++) {
		for (int j = 0; j <= nColMax; j++) {
			if (num[i][j] == id) {
				check++;
				tempi = i;
				tempj = j;
				num[i][j] = 0;
			}
		}
	}
	if (check != 0) {
		cout << id << " 예약 번호가 취소 처리되었습니다.\n";
		pSeatArray[tempi - 1][tempj - 1].setCheck(SEAT_EMPTY_MARK);
	}
	else
		cout << "해당하는 예약번호가 없습니다.";
	return nullptr;
}
void Screen::cancelReservation()
{
	int num;
	cout << " [ 좌석 예약 취소 ]\n";
	cout << "예약 번호 입력 : ";
	cin >> num;
	Screen::checkReservedID(num);
}