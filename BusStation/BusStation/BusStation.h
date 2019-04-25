#pragma once

class BusStation{
	using uint32 = unsigned int;
public:
	BusStation();
	~BusStation();

	void GetStationName();
	void GetWaitingTimeByName(string name);

private:
	void Push_Back(string name);
	void Push_Back(string name, string busName);

	void Push_Front(string name);
	void Push_Front(string name, string busName);

	void Pop_Back();
	void Pop_Front();

	void Next();
	void Prev();

private:
	class Node {
	public:
		Node(string name) {
			m_pNext = nullptr;
			m_pPrev = nullptr;
			m_StationName = name;
			m_BusName = "";
		}

		Node(string name, string busName) {
			m_pNext = nullptr;
			m_pPrev = nullptr;
			m_StationName = name;
			m_BusName = busName;
		}

		~Node() {

		}

		Node* m_pNext;
		Node* m_pPrev;
		string m_StationName;
		string m_BusName;
	};

	Node* m_pHeader;
	Node* m_pTail;
	Node* m_pCur;
	uint32 m_Size;
};

