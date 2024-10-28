#include "receptTetel.h"

ReceptTetel::ReceptTetel(const Hozzavalo& hv, int quantity)
	: _hv(hv), _quantity(quantity)
{
}

Hozzavalo ReceptTetel::GetHozzavalo() const
{
	return _hv;
}

std::ostream& operator<<(std::ostream& os, const ReceptTetel& rt)
{
	os << std::string(rt._hv) << '(' << rt._quantity << ')';
	return os;
}
