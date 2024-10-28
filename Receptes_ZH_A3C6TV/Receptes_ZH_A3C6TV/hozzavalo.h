#pragma once
#include <string>
#include <unordered_map>
#include <iostream>

class Hozzavalo
{
public:
	enum eHozzavalo {
		liszt, vaj, tej, rizs, hus, hagyma, tojas
	};
	Hozzavalo();
	Hozzavalo(const std::string hv);
	Hozzavalo(const eHozzavalo hv);
	operator std::string() const;
	static Hozzavalo ToEnum(std::string hv);

private:
	eHozzavalo _hozzavalo;
	static const std::unordered_map<eHozzavalo, std::string> eHozzavaloToString;
};

std::ostream& operator<<(std::ostream& os, const Hozzavalo& hv);