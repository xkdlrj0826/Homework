#pragma once

enum DayofWeek {			// ���� ǥ��
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
};

class calander {
public:
	calander(int a_month);	// ������. ����Ʈ ���� ���� �ʰ� ������ ���� �Է¹޾ƾ� �մϴ�.
	~calander();			// �Ҹ���

	void View();			// �Է��� �޿� ���� ��¥�� �ٸ��� ������� �Լ�

private:
	struct Day {					//�Ϸ��� ������ ���� ����ü
		Day(int day) : nDay(day) {	
		}
		int dayofweek;
		int nDay;
	};

	vector<Day> date;				//�Ϸ��Ϸ縦 ��� �Ѵ޷� ����� �� ���͹迭
	int month;						//�Է¹޴� ��. �� ���� �������� ù ���� �޶����ϴ�.
	int firstDay;					//�� ���� ù��. �޿� ���� �� ���� �����ؼ� �� �޷� �����մϴ�.
};