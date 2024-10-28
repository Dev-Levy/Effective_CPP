#include "recept.h"

Recept::Recept(std::string name)
	:_name(name)
{
}

void Recept::UjReceptTetel(const ReceptTetel& rt)
{
	_items.push_back(rt);
}

std::string Recept::GetName() const
{
	return _name;
}

std::vector<ReceptTetel> Recept::GetItems() const
{
	return _items;
}

std::ostream& operator<<(std::ostream& os, const Recept& rt)
{
	os << rt._name;
	for (const auto& item : rt._items) {
		os << std::endl << item;
	}
	return os;
}
