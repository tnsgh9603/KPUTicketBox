#pragma once
#define SEAT_EMPTY_MARK '-'
#define SEAT_RESERVED_MARK 'R'
#define SEAT_COMPLETION_MARK '$' 
class Ticket {
	int nRow; // 좌석 행 
	int nCol; // 좌석 열
	char charCheck; // 예약 여부
	int nReservedID; // 예약 번호 
	int nPayAmount; // 결제 금액 
	int nPayMethod; // 결제 수단 
	char charreserved;
public:
	//Ticket() { }
	void setCheck(char check) { charCheck = check; } 
	char getCheck() { return charCheck; }
	void setSeat(int r, int c) { nRow = r; nCol = c; } // 좌석 예약 번호 저장 
	void setReservedID(int reserved) { nReservedID = reserved; } // 
	int getReservedID() { return nReservedID; }

};
