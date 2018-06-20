#include <iostream>
#include <string>
#include <vector>

std::string A = "abcdefg";
std::string B = "1234567890";
std::string C = "ABCDEFG";
std::string D = "+-=/*";
std::string E = "!@#$%^&";


std::vector<std::string> S2 = { A, B};
std::vector<std::string> S3 = { A, B, C};
std::vector<std::string> S4 = { A, B, C, D};
std::vector<std::string> S5 = { A, B, C, D, E};

void
test_loops2(std::vector<std::string> & S)
{
	for (auto a: S[0] ){
		for (auto b: S[1] ){
			std::cout << a << " " << b << " " << std::endl;
		}
	}
}

void
test_loops3(std::vector<std::string> & S)
{
	for (auto a: S[0] ){
		for (auto b: S[1] ){
			for (auto c: S[2] ){
				std::cout << a << " " << b << " " << c << " " << std::endl;
			}
		}
	}
}

void
test_loops4(std::vector<std::string> & S)
{
	for (auto a: S[0] ){
		for (auto b: S[1] ){
			for (auto c: S[2] ){
				for (auto d: S[3] ){
					std::cout << a << " " << b << " " << c << " " << d << " " << std::endl;
				}
			}
		}
	}
}

void
test_loops5(std::vector<std::string> & S)
{
	for (auto a: S[0] ){
		for (auto b: S[1] ){
			for (auto c: S[2] ){
				for (auto d: S[3] ){
					for (auto e: S[4] ){
						std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << std::endl;
					}
				}
			}
		}
	}
}

void loop(std::vector<std::string> & S)
{
	int loops = S.size();
	std::vector<int> I(loops);
	std::vector<int> N(loops);

	for (int i=0; i<loops; i++)
		N[i] = S[i].size();

	int NN = 1;;
	for (auto n : N)
		NN *= n;

	// Ii = Mi % Ni
	// Mi-1 = Mi / Ni;
	// Mn-1 = k
	int M = 0;
	for (int k=0; k<NN; k++ ){
		M = k;
		for (int i=loops-1; i>=0; i--) {
			I[i] = M % N[i];
			M = M / N[i];
		}
		for (int loop=0; loop<S.size(); loop++){
			int idx = I[loop];
			std::cout << S[loop][idx] << " " ;
		}
		std::cout << std::endl;
	}
}


int main(int argc, char ** argv)
{
	if (argv[1][0] == '0') {
		test_loops2(S2);
		test_loops3(S3);
		test_loops4(S4);
		test_loops5(S5);
	}
	else {
		loop(S2);
		loop(S3);
		loop(S4);
		loop(S5);
	}
	return 0;
}
