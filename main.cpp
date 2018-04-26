#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include "Rosenbrock.h"
#include "pso.h"

using namespace std;
using namespace chrono;

int main()
{
    srand(time(0));
	bool run = true;
	double value;
	double maxvalue = 0;
	double minvalue = 1e10;
	double avgvalue = 0;
	double sum = 0;
	int psogen[4] = { 10, 100, 1000, 10000 };
	int num = 100;;

	auto start = system_clock::now();

    PSO pso;
	for (int j = 3; j < 4; j++)
	{
		sum = 0;
		maxvalue = 0;
		minvalue = 1e10;
		avgvalue = 0;
		cout << endl << "pso gen = " << psogen[j] << endl;
		cout << "runing";
		for (int i = 0; i < num; i++)
		{
			//cout << ".";//TODO:输出一个点，再输出一个退格
			pso.init(40, 50, -30, 30, psogen[j]);
			pso.run();
			value = pso.getbestpvalue();
			//cout << value << endl;
			sum += value;
			if (value < minvalue)
			{
				minvalue = value;
			}
			if (value > maxvalue)
			{
				maxvalue = value;
			}
		}
		cout << endl;
		avgvalue = sum / num;
		cout << "min value = " << minvalue << endl;
		cout << "max value = " << maxvalue << endl;
		cout << "avg value = " << avgvalue << endl;

		auto end = system_clock::now();
		auto duration = duration_cast<microseconds>(end - start);
		cout << "use"
			<< double(duration.count()) * microseconds::period::num / microseconds::period::den << "sec" << endl;
	}
	cout << "press any key to kill me..." << endl;
	getchar();

    return 0;
}
