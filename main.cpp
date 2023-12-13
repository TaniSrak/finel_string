#include <iostream>
#include <string>

//Task1 пробелы в строке между каждым символом
std::string spaces_str(std::string str)
//возвращаемое         принимаемое
{
	std::string result(str.length() * 2 - 1, ' ');
	for (int i = 0; i < str.length(); i++)
	{
		result[i * 2] = str[i];
	}
	return result;
}

//Task2 проверка на спам
bool is_spam(std::string str);

int main() {
	system("chcp 1251>null");
	int n;

	//Task1 
	/*std::cout << "Введите строку -> ";
	std::string str1; //создали переменную
	std::getline(std::cin, str1); //взял(поместил)
	std::cout << spaces_str(str1) << "\n\n";
	*/

	//Task2
	std::cout << "Введите строку -> ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))
		std::cout << "Обнаружен спам\n\n";
	else
		std::cout << "Спама не обнаружено\n\n";

	return 0;
}

//Task2
bool is_spam(std::string str)
{
	//возедение строки в нижний региср для обеспечения нерегистрозависимой функции
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);

	const int spams_number = 4; //создаем массив для нахождения того самого спама
	static const std::string spams[spams_number] //статик для того, чтобы для всех элементов работало одинаково
	{
		"100% free",
		"sales increase",
		"only today",
		"black friday"
	};

	for (int i = 0; i < spams_number; i++)
	{
		if (str.find(spams[i]) < str.length())
			return true;
	}
	return false;
}