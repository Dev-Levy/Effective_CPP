#pragma once
#include "recept.h"
class ReceptKatalogus
{
public:
	ReceptKatalogus() = default;

	void UjRecept(const Recept& r);
	Recept Keres(std::string name) const;
	void Beolvas(std::string filename);
	std::vector<Recept> MelyikTartalmaz(std::string hv) const;

	friend std::ostream& operator<<(std::ostream& os, const ReceptKatalogus& rk);
private:
	std::vector<Recept> _kata;
};
std::ostream& operator<<(std::ostream& os, const ReceptKatalogus& rk);