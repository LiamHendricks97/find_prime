// loops.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <chrono>

int main()
{
	auto begin = std::chrono::high_resolution_clock::now();

	// Initial vector of primes
	std::vector <int> vector_primes{ 3, 5, 7 };
	std::cout << "Enter a number to see all the primes leading up to it: ";

	// Maximum number that primes will be calulated to
	int max_num{1'000'000};
	//std::cin >> max_num;

	while (vector_primes.back() < max_num)
	{		
		for (unsigned i{ 0 }; i < vector_primes.size(); i++) {
			//Test output stream
			//std::cout << "if: " << vector_primes.back() << "	%	" << vector_primes[i] << "	== 0 &&	" << vector_primes.back() << "	!=	" << vector_primes[i] 
			//	<< "	:bool:" << (vector_primes.back() % vector_primes[i] == 0 && vector_primes.back() != vector_primes[i]) 
			//	<< "	:Equalib factor:" << (vector_primes.back() / vector_primes[i] < vector_primes[i]) << std::endl;

			if (vector_primes.back() % vector_primes[i] == 0 && vector_primes.back() != vector_primes[i] )
			{
				vector_primes.push_back(vector_primes.back() + 2);
				vector_primes.erase(vector_primes.end() - 2);
				//Study above erase
				break;
			}

			else if (vector_primes.back() / vector_primes[i] < vector_primes[i]){
				vector_primes.push_back(vector_primes.back() + 2);
				break;
			}

			else if (vector_primes.back() == vector_primes[i]) {
				//Why didnt the above or statement work with a for pointer vector? -----> for (vector_prime : vectorprimes)
				vector_primes.push_back(vector_primes.back() + 2);
				break;

			}
		}
	}
	//Show the entire list of primes
	/*for (int test : vector_primes) {
		std::cout << test << ", ";

	}*/
	//std::cout << "\nTest numbers: " << "3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149" << std::endl << std::endl;

	//Show max_num
	std::cout << "\nmax_num used: " << max_num << std::endl;

	//Show last primes
	std::cout << "\nLast five primes (-1 explicitly not included)" << std::endl;
	for (int i{-2}; i > -7; i--)
		std::cout << "Index: " << i  << ": "<< vector_primes.end()[i] << std::endl;

	//Total primes within vector
	std::cout << "\nPrimes within vector: " << vector_primes.size() << std::endl;


	//Timer
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "\nExecution time: " << ("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}