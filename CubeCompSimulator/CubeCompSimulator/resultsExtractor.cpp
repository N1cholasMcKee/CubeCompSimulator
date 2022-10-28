#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "FileReader.cpp"

class resultsExtractor {
private:
	const std::map<std::string, int> eventformats = {{"333", 5}, {"222", 5}};
	FileReader f;
public:
	resultsExtractor(std::string name): f(name) {
	}
	std::vector<int> getResults(std::string event, std::string wcaID, int startDate, int endDate) {
		f.readLine();
		std::string line = f.readLine();
		std::vector<int> results;
		while (line != "") {
			if (line.find(wcaID) != std::string::npos && line.find(event + "\t") != std::string::npos) {
				for (int i = startDate; i <= endDate; i++) {
					if (line.find(std::to_string(i)) < line.find("\t")+4) { //something is wrong with this
						if (eventformats.at(event) == 5) {
							std::cout << line.substr(line.find("\ta\t"), line.find("\ta\t") + 20)<< std::endl;
						}
						else if (event == "666" || event == "777" || event == "fmc") {
							std::cout << line.substr(line.find("\tm\t"), line.find("\ta\t") + 20);
						}
					}
				}
			}
			line = f.readLine();
		}
		return results;
	}	
};
