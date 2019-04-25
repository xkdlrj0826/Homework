#include "pch.h"
#include "BusStation.h"

BusStation::BusStation() {
	m_pHeader = new Node("A");

	m_pTail = m_pHeader;
	m_pCur = m_pHeader;
	m_Size = 1;

	Push_Back("B", "100");
	Push_Back("C");
	Push_Back("D");
	Push_Back("E", "200");
	Push_Back("F");
	Push_Back("G", "300");

	Next();
	Next();
	Next();
}

BusStation::~BusStation() {
	m_pCur = m_pHeader;
	for (; m_Size > 1; m_Size--) {
		Pop_Back();
	}

	delete m_pCur;
	m_pCur = nullptr;
	m_pHeader = nullptr;
	m_pTail = nullptr;
}

void BusStation::GetStationName() {
	cout << "현재 정류장의 이름은 " << m_pCur->m_StationName << " 입니다." << endl;
}

void BusStation::GetWaitingTimeByName(string name) {
	int count = 0;
	Node* m_pComp = m_pCur;
	while (true) {
		if (m_pComp->m_BusName.compare(name) != 0) {
			if (m_pComp->m_pPrev != nullptr) m_pComp = m_pComp->m_pPrev;
			else break;
			count++;
		}
		else {
			cout << name << "번 버스가 현재 " << count << "개 정류장 전에 있습니다." << endl;
			return;
		}
	}

	cout << "기다리시는 버스가 현재 운행중이지 않습니다." << endl;
}

void BusStation::Push_Back(string name) {
	Node* pNext = new Node(name);

	m_pTail->m_pNext = pNext;
	pNext->m_pPrev = m_pTail;
	m_pTail = pNext;
	m_Size++;
}

void BusStation::Push_Back(string name, string busName) {
	Node* pNext = new Node(name, busName);

	m_pTail->m_pNext = pNext;
	pNext->m_pPrev = m_pTail;
	m_pTail = pNext;
	m_Size++;
}

void BusStation::Push_Front(string name) {
	Node* pPrev = new Node(name);

	m_pHeader->m_pPrev = pPrev;
	pPrev->m_pNext = m_pHeader;
	m_pHeader = pPrev;
	m_Size++;
}

void BusStation::Push_Front(string name, string busName) {
	Node* pPrev = new Node(name, busName);

	m_pHeader->m_pPrev = pPrev;
	pPrev->m_pNext = m_pHeader;
	m_pHeader = pPrev;
	m_Size++;
}

void BusStation::Pop_Back() {
	if (m_pCur == m_pTail) return;
	m_pTail = m_pTail->m_pPrev;
	delete m_pTail->m_pNext;
	m_pTail->m_pNext = nullptr;
	m_Size--;
}

void BusStation::Pop_Front() {
	if (m_pCur == m_pHeader) return;
	delete m_pHeader->m_pPrev;
	m_pHeader->m_pPrev = nullptr;
	m_Size--;
}

void BusStation::Next() {
	if (m_pCur->m_pNext == nullptr) return;
	m_pCur = m_pCur->m_pNext;
}

void BusStation::Prev() {
	if (m_pCur->m_pPrev == nullptr) return;
	m_pCur = m_pCur->m_pPrev;
}