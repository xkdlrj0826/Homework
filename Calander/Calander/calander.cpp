#include "pch.h"
#include "calander.h"

calander::calander(int a_month) {				// ������
	assert(a_month > 0 && a_month <= 12);		// 1~12 �̿��� ���� �Է��ϸ� ����!

	month = a_month;

	switch (month) {
	case 1:										// 31���� �Ǵ� �޵�
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		for (int i = 1; i <= 31; i++) {			
			date.push_back(Day(i));
		}
		break;
	case 4:										// 30���� �Ǵ� ����
	case 6:
	case 9:
	case 11:
		for (int i = 1; i <= 30; i++) {
			date.push_back(Day(i));
		}
		break;
	case 2:										// 2��
		for (int i = 1; i <= 28; i++) {
			date.push_back(Day(i));
		}
		break;
	}

	switch (month) {							// �� �޺��� 1���� �������� ������ ù���� �����մϴ�.
	case 1:										// �� ���� 31���̸� +3, 30���̸� +2, 28���̸� ��ȭ�� �����ϴ�.
		firstDay = DayofWeek::Tuesday;			// 7�� %�����ؼ� 0~6 ������ ���� ��ȯ�ϰ� ��������ϴ�.
		break;
	case 2:
		firstDay = (calander(1).firstDay + 3) % 7;
		break;
	case 3:
		firstDay = calander(2).firstDay;
		break;
	case 4:
		firstDay = (calander(3).firstDay + 3) % 7;
		break;
	case 5:
		firstDay = (calander(4).firstDay + 2) % 7;
		break;
	case 6:
		firstDay = (calander(5).firstDay + 3) % 7;
		break;
	case 7:
		firstDay = (calander(6).firstDay + 2) % 7;
		break;
	case 8:
		firstDay = (calander(7).firstDay + 3) % 7;
		break;
	case 9:
		firstDay = (calander(8).firstDay + 3) % 7;
		break;
	case 10:
		firstDay = (calander(9).firstDay + 2) % 7;
		break;
	case 11:
		firstDay = (calander(10).firstDay + 3) % 7;
		break;
	case 12:
		firstDay = (calander(11).firstDay + 2) % 7;
		break;
	}

	for (int i = 0; i < date.size(); i++) {					//���� ù ���� �������� �� ��¥�� ������ ���մϴ�.
		if (i == 0) {
			date[i].dayofweek = firstDay;
			continue;
		}

		date[i].dayofweek = (date[i - 1].dayofweek + 1) % 7;
	}
}

calander::~calander(){										// �Ҹ���. �ʿ��ϸ� ������ �����Դϴ�.
}

void calander::View() {										// ���� ��¥�� ȭ�鿡 ����� �Լ�
	int count = 0;
	cout << "         " << month << "��" << endl;
	cout << "�� �� ȭ �� �� �� ��" << endl;
	for (int j = 0; j < date[0].dayofweek; j++) {
		cout << "   ";
		count++;
	}
	for (int i = 0; i < date.size(); i++) {
		if (i < 10) cout << " ";
		cout << date[i].nDay << " ";
		count++;
		if (count == 7) {
			cout << endl;
			count = 0;
		}
	}

	cout << endl;
}