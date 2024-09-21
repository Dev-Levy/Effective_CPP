#include <vector>
#include <random>
#include <iostream>

static bool ContainsThisNum(int num, std::vector<int> vec);

int main()
{

	//kérj be 5 számot console-ról 1-90 között, nem ismétlõdhet
	//generálj 5 random számot ua. feltételekkel

	//nézd meg mennyi egyezik

	std::vector<int> user_nums;
	std::vector<int> rand_nums;
	int v_size = 5;

	std::random_device rand;
	std::mt19937 engine(rand());
	std::uniform_int_distribution<> dist(1, 90);

	std::cout << "Enter 5 different numbers (1-90)!" << std::endl;
	while (user_nums.size() != v_size)
	{
		int num;
		std::cin >> num;
		if (num > 0 && num < 91 && !ContainsThisNum(num, user_nums))
			user_nums.push_back(num);
		else
			std::cout << "Invalid input!" << std::endl;
	}
	std::sort(user_nums.begin(), user_nums.end());

	while (rand_nums.size() != v_size)
	{
		int num = dist(engine);
		if (!ContainsThisNum(num, rand_nums))
			rand_nums.push_back(num);
	}
	std::sort(rand_nums.begin(), rand_nums.end());

	std::cout << "user\trand" << std::endl;
	int counter = 0;
	for (size_t i = 0; i < v_size; i++)
	{
		std::cout << user_nums[i] << '\t' << rand_nums[i] << std::endl;
		if (user_nums[i] == rand_nums[i])
			counter++;
	}
	std::cout << "Number of matching numbers: " << counter << std::endl;
}

static bool ContainsThisNum(int num, std::vector<int> vec)
{
	for (const int& item : vec)
		if (item == num)
			return true;
	return false;
}