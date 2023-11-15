#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex station;

void railway_station(char name_train, int travel_time) {
	std::string depart;
	std::cout << "����� " << name_train << " � ����!" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(travel_time));
	station.lock();
	std::cout << "����� " << name_train << " ������ �� ������ � ���������� �������� � ������� ����������!" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "������� ���������, ������� ������� �� �����������: (depart)" << std::endl;
	std::cin >> depart;
	station.unlock();
}

int main() {
	setlocale(LC_ALL, "rus");
	int time1, time2, time3;
	std::cout << "������� ����� � ���� ��� ������� ������ ����� ������!" << std::endl;
	std::cin >> time1 >> time2 >> time3;

	std::thread train1(railway_station, 'A', time1);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::thread train2(railway_station, 'B', time2);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::thread train3(railway_station, 'C', time3);
	train1.join();
	train2.join();
	train3.join();

	return 0;
 }