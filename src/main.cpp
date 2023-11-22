#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex station;

void railway_station(char name_train, int travel_time) {
	std::string depart;
	std::cout << "Train " << name_train << " on the way!" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(travel_time));
	station.lock();
	std::cout << "Train " << name_train << " arrived at the station and performs unloading and boarding of passengers!" << std::endl;
	std::cout << "Boarding is completed, give the command to depart: (depart)" << std::endl;
	while (depart != "depart") {
		std::cin >> depart;
	}
	std::cout << "The train is leaving!" << std::endl;
	station.unlock();
}

int main() {
	int time1, time2, time3;
	std::cout << "Enter the travel time for each train separated by a space!" << std::endl;
	std::cin >> time1 >> time2 >> time3;

	std::thread train1(railway_station, 'A', time1);
	std::thread train2(railway_station, 'B', time2);
	std::thread train3(railway_station, 'C', time3);
	train1.join();
	train2.join();
	train3.join();

	return 0;
 }