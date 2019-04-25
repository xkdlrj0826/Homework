#pragma once

enum DayofWeek {			// 요일 표기
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
	calander(int a_month);	// 생성자. 디폴트 값을 쓰지 않고 무조건 달을 입력받아야 합니다.
	~calander();			// 소멸자

	void View();			// 입력한 달에 따라 날짜를 다르게 출력해줄 함수

private:
	struct Day {					//하루의 정보를 담을 구조체
		Day(int day) : nDay(day) {	
		}
		int dayofweek;
		int nDay;
	};

	vector<Day> date;				//하루하루를 모아 한달로 만들어 줄 벡터배열
	int month;						//입력받는 달. 이 값을 기준으로 첫 날이 달라집니다.
	int firstDay;					//각 달의 첫날. 달에 따라 이 값을 변경해서 한 달로 정렬합니다.
};