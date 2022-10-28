#include <iostream>
#include <string>
#include "Competitor.h"
#include "FileReader.cpp"
#include "resultsExtractor.cpp"

int main() {
    resultsExtractor r("C:\\Users\\Nicholas\\Documents\\WCA_export_Results.tsv");
    r.getResults("333", "2015MCKE02", 2020, 2022);
    return 0;
}
