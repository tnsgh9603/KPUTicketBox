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
	cout << "      [ ���� �� ������ ]      \n";
	cout << "------------------------------\n";
	cout << " ��ȭ�� : ���� ��ȭ 1��\n";
	cout << " ���ΰ� : ���� ȣũ, �ٸ� ����\n";
	cout << " �ٰŸ� : ���ÿ� �������� ���� Ⱦ�� �����ȿ��� �쿬�� ...\n";
	cout << " ���� : 10000\n";
}
void EuropeScreen::showMovieMenu()
{
	cout << "\n-----------------------------------\n";
	cout << "     ��ȭ �޴� - ���� �� ������    \n";
	cout << "-----------------------------------\n";
	cout << "1. �� ��ȭ ����\n";
	cout << "2. �¼� ���� ��Ȳ\n";
	cout << "3. ���� �ϱ�\n";
	cout << "4. ���� ���\n";
	cout << "7. ���� �޴� �̵�\n\n";
}
void AsiaScreen::showMovieInfo() {
	cout << "------------------------------\n";
	cout << "          [ �пպ��� ]\n";
	cout << "------------------------------\n";
	cout << " ��ȭ�� : �ƽþ� ��ȭ 2��\n";
	cout << " ���ΰ� : �屹��, ����\n";
	cout << " �ٰŸ� : ����� ������ �Բ� ����� �ؿ� ������ ����...\n";
	cout << " ���� : 12000\n";
}
void AsiaScreen::showMovieMenu()
{
	cout << "\n-----------------------------------\n";
	cout << "        ��ȭ �޴� -  �пպ���      \n";
	cout << "-----------------------------------\n";
	cout << "1. �� ��ȭ ����\n";
	cout << "2. �¼� ���� ��Ȳ\n";
	cout << "3. ���� �ϱ�\n";
	cout << "4. ���� ���\n";
	cout << "7. ���� �޴� �̵�\n\n";
}
void PremiumScreen::showMovieInfo() {
	cout << "------------------------------\n";
	cout << "     [ ������ �̽������� ]    \n";
	cout << "------------------------------\n";
	cout << " ��ȭ�� : �����̾� ��ȭ 3��\n";
	cout << " ���ΰ� : �ٴϿ� ����Ŭ����\n";
	cout << " �ٰŸ� : �αǿ�� ���� ��Ƽ���� ����� �ǰ�� �����ȴ�...\n";
	cout << " ���� : 30000\n";
}
void PremiumScreen::showMovieMenu()
{
	cout << "\n-----------------------------------\n";
	cout << "     ��ȭ �޴� - ���� �� ������    \n";
	cout << "-----------------------------------\n";
	cout << "1. �� ��ȭ ����\n";
	cout << "2. �¼� ���� ��Ȳ\n";
	cout << "3. ���� �ϱ�\n";
	cout << "4. ���� ���\n";
	cout << "7. ���� �޴� �̵�\n\n";
}
void Screen::showSeatMap() {
	cout << "\t[ �¼� ���� ��Ȳ ]\n\t";
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
	cout << " [ �¼� ���� ]\n";
	int row, col;
	cout << "�¼� �� ��ȣ �Է�( 1 - " << nRowMax << " ): ";
	cin >> row;
	cout << "�¼� �� ��ȣ �Է�( 1 - " << nColMax << " ): ";
	cin >> col;
	cout << "��[" << row << "]" << "��[" << col << "]" << ++reservednumber << " ���� ��ȣ�� �����Ǿ����ϴ�.\n";
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
		cout << id << " ���� ��ȣ�� ��� ó���Ǿ����ϴ�.\n";
		pSeatArray[tempi - 1][tempj - 1].setCheck(SEAT_EMPTY_MARK);
	}
	else
		cout << "�ش��ϴ� �����ȣ�� �����ϴ�.";
	return nullptr;
}
void Screen::cancelReservation()
{
	int num;
	cout << " [ �¼� ���� ��� ]\n";
	cout << "���� ��ȣ �Է� : ";
	cin >> num;
	Screen::checkReservedID(num);
}