#include "hozzavalo.h"
#include <stdexcept>



const std::unordered_map<Hozzavalo::eHozzavalo, std::string> Hozzavalo::eHozzavaloToString{
	{liszt, "Liszt"},
	{vaj, "Vaj"},
	{tej, "Tej"},
	{rizs, "Rizs"},
	{hus, "Hus"},
	{hagyma, "Hagyma"},
	{tojas, "Tojas"},
};

Hozzavalo::Hozzavalo()
	:_hozzavalo(Hozzavalo::liszt)
{
}

Hozzavalo::Hozzavalo(const std::string hv)
{
	for (const auto& it : eHozzavaloToString) {
		if (it.second == hv)
		{
			_hozzavalo = it.first;
			return;
		}
	}
}

Hozzavalo::Hozzavalo(const eHozzavalo hv)
	: _hozzavalo(hv)
{
}

Hozzavalo::operator std::string() const
{
	auto it = eHozzavaloToString.find(_hozzavalo);
	if (it != eHozzavaloToString.end())
	{
		return it->second;
	}
	return "";
}

Hozzavalo Hozzavalo::ToEnum(std::string hv)
{
	for (const auto& it : eHozzavaloToString) {
		if (it.second == hv)
		{
			Hozzavalo h(it.first);
			return h;
		}
	}
	throw std::invalid_argument("Nem lehet ilyen nevu hozzavalot kesziteni!");
}

std::ostream& operator<<(std::ostream& os, const Hozzavalo& hv)
{
	os << std::string(hv);
	return os;
}
