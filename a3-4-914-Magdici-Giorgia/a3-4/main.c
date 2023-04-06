#include "UI.h"
#include <crtdbg.h>

int main()
{
	OfferRepo* repo = createRepo();
	Service* ctrl = createService(repo);
	testsOfferRepo();

	addOfferServ(ctrl, "seaside", "Vama Veche", "2022/05/01", 1200);
	addOfferServ(ctrl, "seaside", "Neptun", "2022/09/13", 800);
	addOfferServ(ctrl, "seaside", "Mamaia", "2022/08/10", 1500);
	addOfferServ(ctrl, "city break", "Bucuresti", "2022/04/20", 1300);
	addOfferServ(ctrl, "city break", "Paris", "2022/03/28", 2000);
	addOfferServ(ctrl, "mountain", "Busteni", "2022/02/10", 2500);
	addOfferServ(ctrl, "mountain", "Sinaia", "2022/01/27", 2600);


	UI* ui = createUI(ctrl);

	startUI(ui);

	destroyUI(ui);

	_CrtDumpMemoryLeaks();

	return 0;
}