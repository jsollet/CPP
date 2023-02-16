#include "Fixed.hpp"
#include "point.hpp"


bool bsp( Point const a, Point const b, Point const c, Point const p)
 {
	Point ab = translate(a,b);
	Point bc = translate(b,c);
	Point ca = translate(c,a);
	Point ap = translate(a,p);
	Point bp = translate(b,p);
	Point cp = translate(c,p);
	Fixed AxB = cross(ab, bc);
	Fixed BxC = cross(bc, ca);
	Fixed CxA = cross(ca, ab);
	Fixed Axp = cross(ab, ap);
	Fixed Bxp = cross(bc, bp);
	Fixed Cxp = cross(ca, cp);
	Fixed signe_triangle = AxB * BxC * CxA;
	Fixed signe_p = Axp * Bxp * Cxp;
/*
	std::cout << "\n test bsp  \n";
	std::cout << "A = (" << ab.getX() << " , " << ab.getY() << ")" << std::endl;
	std::cout << "B = (" << bc.getX() << " , " << bc.getY() << ")" << std::endl;
	std::cout << "C = (" << ca.getX() << " , " << ca.getY() << ")" << std::endl;
	std::cout << " AxB =\t" << AxB << std::endl;
	std::cout << " BxC =\t" << BxC << std::endl;
	std::cout << " CxA =\t" << CxA << std::endl;

	std::cout << "\n test partie p  \n";
	std::cout << "pA = (" << ap.getX() << " , " << ap.getY() << ")" << std::endl;
	std::cout << "pB = (" << bp.getX() << " , " << bp.getY() << ")" << std::endl;
	std::cout << "pC = (" << cp.getX() << " , " << cp.getY() << ")" << std::endl;
	std::cout << " Axp =\t" << Axp << std::endl;
	std::cout << " Bxp =\t" << Bxp<< std::endl;
	std::cout << " Cxp =\t" << Cxp << std::endl;
*/
	if (signe_triangle == 0 || signe_p == 0)
		return (false);
	if (signe_triangle > 0 && signe_p < 0)
		return (false);
	if (signe_triangle < 0 &&  signe_p > 0)
		return (false);
	return (true);
}
