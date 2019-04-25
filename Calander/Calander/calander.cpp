#include "pch.h"
#include "calander.h"

calander::calander(int a_month) {				// 생성자
	assert(a_month > 0 && a_month <= 12);		// 1~12 이외의 값을 입력하면 에러!

	month = a_month;

	switch (month) {
	case 1:										// 31일이 되는 달들
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
	case 4:										// 30일이 되는 달을
	case 6:
	case 9:
	case 11:
		for (int i = 1; i <= 30; i++) {
			date.push_back(Day(i));
		}
		break;
	case 2:										// 2월
		for (int i = 1; i <= 28; i++) {
			date.push_back(Day(i));
		}
		break;
	}

	switch (month) {							// 각 달별로 1월을 기준으로 전달의 첫날을 참조합니다.
	case 1:										// 전 달이 31일이면 +3, 30일이면 +2, 28일이면 변화가 없습니다.
		firstDay = DayofWeek::Tuesday;			// 7을 %연산해서 0~6 사이의 값이 순환하게 만들었습니다.
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

	for (int i = 0; i < date.size(); i++) {					//구한 첫 날을 기준으로 각 날짜의 요일을 구합니다.
		if (i == 0) {
			date[i].dayofweek = firstDay;
			continue;
		}

		date[i].dayofweek = (date[i - 1].dayofweek + 1) % 7;
	}
}

calander::~calander(){										// 소멸자. 필요하면 구현할 예정입니다.
}

void calander::View() {										// 구한 날짜를 화면에 띄워줄 함수
	int count = 0;
	cout << "         " << month << "월" << endl;
	cout << "일 월 화 수 목 금 토" << endl;
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