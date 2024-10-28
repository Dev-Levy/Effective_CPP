#pragma once
#include "hozzavalo.h"
class ReceptTetel
{
public:
	ReceptTetel() = default;
	ReceptTetel(const Hozzavalo& hv, int quantity);
	Hozzavalo GetHozzavalo() const;
	friend std::ostream& operator<<(std::ostream& os, const ReceptTetel& rt);
private:
	Hozzavalo _hv;
	int _quantity;
};

std::ostream& operator<<(std::ostream& os, const ReceptTetel& rt);

