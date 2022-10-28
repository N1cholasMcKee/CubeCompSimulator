#include <vector>
#include <string>

class Competitor {
public:
	Competitor(std::string inputName, std::string inputWCAID);
	std::string WCAID;
	std::string name;
	void addTimes(std::vector<int> timeList);
	double dnfRate();
	int globalAverage();
	int stDev();
private:
	std::vector<int> times;
	int dnfs;
	int totalSolves;
};

