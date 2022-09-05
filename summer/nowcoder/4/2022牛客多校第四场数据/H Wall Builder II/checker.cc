// Author: HeRaNO
#include "testlib.h"

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	int T = inf.readInt();
	for (int cas = 1; cas <= T; cas++)
	{
		// setTestCase(cas);
		int n = inf.readInt();
		int L = (n + 2) * (n + 1) * n / 6;
		int jans = ans.readInt();
		int pans = ouf.readInt(1, 2'000'000'000, "pans");
		if (jans != pans)
			quitf(_wa, "the minimum circumference differ, jans = %d, pans = %d", jans, pans);
		std::vector<int> cntL(n, 0);
		std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> psol;
		int mxX = 0, mxY = 0;
		for (int i = 1; i <= n * (n + 1) / 2; i++)
		{
			int x1 = ouf.readInt(0, L, "x1");
			int y1 = ouf.readInt(0, L, "y1");
			int x2 = ouf.readInt(0, L, "x2");
			int y2 = ouf.readInt(0, L, "y2");
			ans.readInts(4, 0, 2147483647);
			quitif((x1 >= x2) || (y1 >= y2), _wa, "(%d, %d) - (%d, %d) is not a valid brick", x1, y1, x2, y2);
			if ((x2 - x1 != 1) && (y2 - y1 != 1))
				quitf(_wa, "no brick with size %d x %d", x2 - x1, y2 - y1);
			if (y2 - y1 != 1)
				quitf(_wa, "cannot rotate the brick");
			else
			{
				if (x2 - x1 > n)
					quitf(_wa, "no brick with size 1 x %d", x2 - x1);
				++cntL[x2 - x1 - 1];
			}
			mxX = std::max(mxX, x2);
			mxY = std::max(mxY, y2);
			psol.push_back({{x1, y1}, {x2, y2}});
		}
		for (int i = 0; i < n; i++)
			quitif(cntL[i] != n - i, _wa, "participant use %d brick(s) of size 1 x %d", cntL[i], i + 1);
		if (2 * (mxX + mxY) != jans)
			quitf(_wa, "participant's solution doesn't match the minimum circumference");
		if (1LL * mxX * mxY != L)
			quitf(_wa, "participant's solution is wrong - real size = %lld, expect size = %d", 1LL * mxX * mxY, L);
		std::vector<std::vector<bool>> vis(mxX, std::vector<bool>(mxY, false));
		for (auto [ll, ur] : psol)
		{
			int x1, y1, x2, y2;
			std::tie(x1, y1) = ll;
			std::tie(x2, y2) = ur;
			for (int i = x1; i < x2; i++)
				for (int j = y1; j < y2; j++)
				{
					quitif(vis[i][j], _wa, "participant's solution is wrong - two bricks overlap");
					vis[i][j] = true;
				}
		}
		for (int i = 0; i < mxX; i++)
			for (int j = 0; j < mxY; j++)
				quitif(!vis[i][j], _wa, "participant's solution is wrong - no brick on (%d, %d)", i, j);
	}
	quitf(_ok, "ok");
	return 0;
}