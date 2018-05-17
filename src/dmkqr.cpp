#include "dmkqr.h"
#include "dconfmgr.h"

int main(int argc, char *argv[]){
	DconfManager tg;
	if (tg.Load("qr_test.conf.xml") == 0){
		tg.RunScheme("smkp");
	}

    return 0;
}