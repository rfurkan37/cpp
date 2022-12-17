#include <iostream>
#include <iomanip>

#include <chrono>
#include <thread>

int main() {
  double pi = 0.0; // Initialize pi to 0

	unsigned long long i = 0 ;

	std::cout << std::setprecision(100000);
  // Calculate the sum of the Leibniz series
  while(i + 1) {
    // Alternately add and subtract the next term in the series
    pi += (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);


	std::cout << pi * 4 << std::endl; 

	//std::this_thread::sleep_for(std::chrono::milliseconds(1));
	
	i++;
	

  }

  // Multiply the sum by 4 to approximate pi
  

  

  return 0;
}

