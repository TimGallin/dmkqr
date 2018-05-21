#include "dmkqr.h"
#include "dconfmgr.h"
#include <fstream>

#include "implfunc\implrsa.h"

int main(int argc, char *argv[]){

	DconfManager tg;
	if (tg.Load("qr_test.conf.xml") == 0){
		std::string mm = tg.RunScheme("smkp");
	}

    return 0;
}