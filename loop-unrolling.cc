#include <iostream>
#include <string>
#include <vector>

std::string A = "abcde";
std::string B = "12345";
std::string C = "ABCDE";

std::vector<std::string> S(3);

void
test1()
{
	for (auto a: A ){
		for (auto b: B ){
			for (auto c: C ){
				std::cout << a << " " << b << " " << c << " " << std::endl;
			}
		}
	}
}

void loop()
{
	std::vector<int> I(3);
	std::vector<int> N(3);

	N[0] = A.size();
	N[1] = B.size();
	N[2] = C.size();

	S[0] = A;
	S[1] = B;
	S[2] = C;

	int NN = 1, loops = 3;
	for (auto n : N)
		NN *= n;
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
	if (argv[1][0] == '0')
		test1();
	else
		loop();
	return 0;
}
