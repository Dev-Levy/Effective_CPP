#include "receptKatalogus.h"

#define f_ck_around try
#define find_out catch

int main() {
	f_ck_around
	{
		ReceptKatalogus rk;
		rk.Beolvas("receptek.txt");
		std::cout << rk << std::endl;
		Hozzavalo hv(Hozzavalo::ToEnum("Liszt"));

		auto asd = rk.MelyikTartalmaz("Tej");
	} find_out(std::exception e) {
		std::cout << e.what();
	}

}