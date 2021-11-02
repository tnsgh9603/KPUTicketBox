#pragma once
#define SEAT_EMPTY_MARK '-'
#define SEAT_RESERVED_MARK 'R'
#define SEAT_COMPLETION_MARK '$' 
class Ticket {
	int nRow; // �¼� �� 
	int nCol; // �¼� ��
	char charCheck; // ���� ����
	int nReservedID; // ���� ��ȣ 
	int nPayAmount; // ���� �ݾ� 
	int nPayMethod; // ���� ���� 
	char charreserved;
public:
	//Ticket() { }
	void setCheck(char check) { charCheck = check; } 
	char getCheck() { return charCheck; }
	void setSeat(int r, int c) { nRow = r; nCol = c; } // �¼� ���� ��ȣ ���� 
	void setReservedID(int reserved) { nReservedID = reserved; } // 
	int getReservedID() { return nReservedID; }

};
