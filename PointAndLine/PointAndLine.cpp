#include<iostream>


using namespace std;

class pointType
{
protected:
	double x;
	double y;


public:
	pointType()
	{
		x = 0;
		y = 0;

	}
	void setx(double X)
	{
		x = X;
	}
	void sety(double Y)
	{
		y = Y;
	}

	double getx()
	{
		return x;
	}
	double gety()
	{
		return y;
	}


	double distance(pointType p)
	{
		double dis, dx, dy;

		dx = x - p.x;
		dy = y - p.y;
		dis = sqrt(pow(dx, 2) + pow(dy, 2));

		return dis;
	}

};

class lineType :public pointType
{
private:
	pointType p1;
	pointType p2;
public:
	lineType() : pointType()
	{
		p1.setx(0);
		p1.sety(0);
		p2.setx(0);
		p2.sety(0);
		//p1 p2 not input
	}
	void setl(double x1, double y1, double x2, double y2)
	{
		p1.setx(x1);
		p1.sety(y1);
		p2.setx(x2);
		p2.sety(y2);
	}

	void line()
	{
		double m;

		if (p1.getx() == p2.getx())
		{
			cout << "Line is vertical with the equation of x = " << p1.getx() << endl;
		}
		else if (p1.gety() == p2.gety())
		{
			cout << "Line is horizontal with the equation of y = " << p1.gety() << endl;
		}
		else
		{
			double x = 0, y, b;
			m = ((p2.gety() - p1.gety()) / (p2.getx() - p1.getx()));
			b = p1.gety() - m * p1.getx();
			cout << "Line is slanted with the slope equation of y = " << m << " x + " << b << endl;
		}
	}

	void pOIntersec(lineType l2)
	{
		double m1 = 0, m2 = 0;
		m1 = (p2.gety() - p1.gety()) / (p2.getx()) - p1.getx();
		m2 = (l2.p2.gety() - l2.p1.gety()) / (l2.p2.getx()) - l2.p1.getx();

		if (m1 == m2)
		{
			cout << "Lines are parallel" << endl;
		}
		else if (m1 == -(1 / m2))
		{
			double b1, x1, y1 = 0, b2, x2, y2 = 0, inx, inb;
			b1 = p1.gety() - m1 * p1.getx();
			b2 = l2.p1.gety() - m2 * l2.p1.getx();

			inx = (m1 - m2);
			inb = (b2 - b1);
			x1 = inb / inx;
			y1 = m1 * x1 + b1;



			cout << "Point of intersection is (" << x1 << "," << y1 << ")" << endl;
		}
		else
		{
			cout << "Lines are neither parallel or  perpendicular" << endl;
		}
	}


};


int main()

{
	pointType p1, p2;
	lineType l1, l2, l3, l4;
	double dis;

	p1.setx(3);
	p1.sety(2);
	p2.setx(9);
	p2.sety(7);

	dis = p1.distance(p2);

	l1.setl(0, 2, 2, 10);
	l2.setl(0, 2, 2, 1.5);
	l3.setl(2, 1, 2, 4);
	l4.setl(1, 3, 4, 3);

	l1.line();
	l2.line();
	l3.line();
	l4.line();

	l1.pOIntersec(l2);
	l3.pOIntersec(l4);

	return 0;

}




