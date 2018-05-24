#include "dmkqr.h"
#include "dconfmgr.h"
#include <fstream>

#include "implfunc\implrsa.h"

void test1(const char* &p) {
	++p;
}

int main(int argc, char *argv[]){
	DconfManager tg;
	if (tg.Load("F:\\code\\dmkqr\\bin\\qr_test.conf.xml") == 0){
		std::string mm = tg.RunScheme("smkp");
	}

    return 0;
}