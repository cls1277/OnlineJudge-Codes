// checker.cpp: for check the participant's output of black-hole
// Author: HeRaNO
#include "testlib.h"

const double EPS = 1E-6;

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	int T = inf.readInt();
	for (int cas = 1; cas <= T; cas++)
	{
		// setTestCase(cas);
		std::string pans = ouf.readToken("possible|impossible", "verdict");
		std::string jans = ans.readToken();
		if (jans != pans)
			quitf(_wa, "jury: %s, but participant: %s", jans.c_str(), pans.c_str());
		if (jans == "impossible")
			continue;
		int jn = ans.readInt();
		double ja = ans.readDouble();
		int pn = ouf.readInt(1, 200, "n'");
		double pa = ouf.readDouble(0, 100000, "a'");
		if (jn != pn)
			quitf(_wa, "jury n' = %d, but participant n' = %d", jn, pn);
		if (!doubleCompare(ja, pa, EPS))
			quitf(_wa, "found '%.7f', expected '%.7f', error '%.7f'", pa, ja, doubleDelta(ja, pa));
	}
	quitf(_ok, "ok");
	return 0;
}