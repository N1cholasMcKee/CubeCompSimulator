#include <math.h>
#include <string>
#include <vector>
#include "Competitor.h"


Competitor::Competitor(std::string inputName, std::string inputWCAID) 
{
	WCAID = inputWCAID;
	name = inputName;
}


void Competitor::addTimes(std::vector<int> timeList) {
	for (int time : timeList) {
		if (time != -1) {
			times.push_back(time);
		}
		else {
			dnfs++;
		}
		totalSolves++;
	}
}


double Competitor::dnfRate() {
	return (double) dnfs / totalSolves;
}


int Competitor::globalAverage() {
	int sum = 0;
	for (int time : times) {
		sum = sum + time;
	}
	return sum / times.size();
}


int Competitor::stDev() {
	int sum = 0;
	int mean = globalAverage();
	for (int time : times) {
		sum = sum + pow((time - mean), 3);
	}
	return (sqrt(sum / times.size()));
}
