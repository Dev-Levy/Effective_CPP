#pragma once
#include "receptTetel.h"
#include <vector>
class Recept
{
public:
	Recept() = default;
	Recept(std::string name);
	void UjReceptTetel(const ReceptTetel& rt);
	std::string GetName() const;
	std::vector<ReceptTetel> GetItems() const;
	friend std::ostream& operator<<(std::ostream& os, const Recept& rt);
private:
	std::string _name;
	std::vector<ReceptTetel> _items;
};

std::ostream& operator<<(std::ostream& os, const Recept& rt);