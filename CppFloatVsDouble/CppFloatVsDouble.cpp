#include <iostream>
#include <cmath>
#include <chrono>

const int ITERATIONS = 1000000000;

//euclidean distance formula in 32 bit float
float euclideanDistanceFloat(float x1, float y1, float x2, float y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

//euclidean distance formula in 64 bit double
double euclideanDistanceDouble(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main()
{
    //run the float euclidean distance function 1 billion times and measure the time
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < ITERATIONS; i++)
	{
		euclideanDistanceFloat(1.0f, 2.0f, 3.0f, 4.0f);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "Float time: " << elapsed_seconds.count() << "s\n";

	//run the double euclidean distance function 1 billion times and measure the time
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < ITERATIONS; i++)
	{
		euclideanDistanceDouble(1.0, 2.0, 3.0, 4.0);
	}
	end = std::chrono::high_resolution_clock::now();
	elapsed_seconds = end - start;
	std::cout << "Double time: " << elapsed_seconds.count() << "s\n";
}
