#include "scan.h"
#include <iostream>

int main() {
	Scan::openDirectory();
	std::cout << "size: " << Scan::allScans.size() << std::endl;
}
