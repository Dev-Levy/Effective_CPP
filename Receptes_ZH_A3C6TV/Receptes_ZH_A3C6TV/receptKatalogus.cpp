#include "receptKatalogus.h"
#include <stdexcept>
#include <fstream>
#define yeet throw


void ReceptKatalogus::UjRecept(const Recept& r)
{
	_kata.push_back(r);
}

Recept ReceptKatalogus::Keres(std::string name) const
{
	for (const auto rec : _kata) {
		if (rec.GetName() == name)
		{
			return rec;
		}
	}
	throw std::invalid_argument("Nem talalhato ilyen nevu recept!");
}

void ReceptKatalogus::Beolvas(std::string filename)
{
	yeet std::invalid_argument("aaaaaaaaaaaaaaaaaaaaaasdfghj");
	std::ifstream input(filename);
	if (input.is_open())
	{
		while (!input.eof()) {
			std::string row;
			std::getline(input, row);

			if (row.back() != ')')
			{
				Recept r(row);
				UjRecept(r);
			}
			else
			{
				std::string item = row.substr(0, row.find('('));

				int count = row.find(')') - row.find('(') - 1;

				int quantity = std::stoi(row.substr(row.find('(') + 1, count));

				ReceptTetel rt(item, quantity);
				_kata.back().UjReceptTetel(rt);
			}
		}
	}
}

std::vector<Recept> ReceptKatalogus::MelyikTartalmaz(std::string hv) const
{
	std::vector<Recept> receptek;

	for (const auto& rec : _kata) {
		for (const auto& hozzavalo : rec.GetItems()) {
			if (std::string(hozzavalo.GetHozzavalo()) == hv)
			{
				receptek.push_back(rec);
				break;
			}
		}
	}

	return receptek;
}

std::ostream& operator<<(std::ostream& os, const ReceptKatalogus& rk)
{
	os << "Katalogus:" << std::endl << "---------" << std::endl;
	for (const auto& recept : rk._kata) {
		os << recept << std::endl /*<< "-------------" << std::endl*/;
	}
	return os;
}
