#include "pch.h"
#include "BusStation.h"

int main()
{
	BusStation a;

	a.GetStationName();
	a.GetWaitingTimeByName("100");

	return 0;
}