#include <iostream>
#include <future>
#include <thread>

int asyncFoo(int num)
{
	int result1 = num + 10;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "asyncFoo has been worked asynchronously!" << std::endl;
	return result1;
}

int defferedFoo(int num)
{
	int result1 = num + 20;
	std::this_thread::sleep_for(std::chrono::seconds(10));
	std::cout << "defferedFoo has been worked in that thread!" << std::endl;
	return result1;
}

int main()
{
	std::future<int> ft1 = std::async(std::launch::async, asyncFoo, 12);
	std::future<int> ft2 = std::async(std::launch::deferred, defferedFoo, 20);

	std::cout << "Res of defferedFoo: " << ft2.get() << std::endl;

	std::cout << "Res of asyncFoo: " << ft1.get() << std::endl;


	return 0;
}