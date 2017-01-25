// ECE 4574, Assignment 1, Bowei Zhao
//// PID: 905789193
// email: bowei@vt.edu
// 
// description:  Open Source Module used from KeithM (FB36) from ActiveStateCode
//                What was used here was the module on node creation and A* algorithim
//

#include "path.h"

const int dir=8; 
int tempX1 = 0;
int tempY1 = 0;
int tempX2 = 0;
int tempY2 = 0;

node::node(int xp, int yp, int d, int p) 
{
	xPos=xp;
	yPos=yp;
	level=d; 
	priority=p;
}

int node::getxPos() const
{
	return xPos;
}

int node::getyPos() const
{
	return yPos;
}

int node::getLevel() const
{
	return level;
}

int node::getPriority() const
{
	return priority;
}

void node::updatePriority(const int & xDest, const int & yDest)
{
	priority=level+estimate(xDest, yDest)*10; //A*
}

void node::nextLevel(const int & i) // i: direction
{
	level+=(dir==8?(i%2==0?10:14):10);
}

const int & node::estimate(const int & xDest, const int & yDest) const
{
	            static int xd, yd, d;
            xd=xDest-xPos;
            yd=yDest-yPos;         

            // Euclidian Distance
            d=static_cast<int>(sqrt(xd*xd+yd*yd));

            // Manhattan distance
            //d=abs(xd)+abs(yd);
            
            // Chebyshev distance
            //d=max(abs(xd), abs(yd));

            return(d);
}

int samplecase(int input)
{
	return input;
}

int StartupErrorCheck(int &argc, QStringList arginput)
{
	int successRun = 1;


	bool convok1;
	bool convok2;
	bool convok3;
	bool convok4;

	tempX1 = arginput[1].toInt(&convok1, 10);
	tempY1 = arginput[2].toInt(&convok2, 10);
	tempX2 = arginput[3].toInt(&convok3, 10);
	tempY2 = arginput[4].toInt(&convok4, 10);

	try
	{
		if (argc != 5)
		{
			successRun = 0;
			throw "Provide four inputs of X and Y start address\n Ex: ./Program 0 10 50 35\n - For starting point of (0,10) and end of (50,35)";

			return successRun;
		}
		else if ((tempX1 >= XYSize) || (tempY1 >= XYSize) || (tempX2 >= XYSize) || (tempY2 >= XYSize))
		{			
			successRun = 0;
			throw "Input X,Y integers can not be greater than or EQUAL to 60";

			return successRun;

		}
		else if ((tempX1 < MinSize) || (tempY1 < MinSize) || (tempX2 < MinSize) || (tempY2 < MinSize))
		{			
			successRun = 0;
			throw "Input X,Y integers can not be negative (less than 0)";

			return successRun;
		}
		else if ((convok1 == false) || (convok2 == false) || (convok3 == false) || (convok4 == false))
		{
			successRun = 0;
			throw "Conversion of one of the inputs to Integers failed. Check to make sure inputs are integer numbers";

			return successRun;
		}


	}
	catch (const char* msg)
	{
		successRun = 0;
		cout << "\nWARNING: " << msg << "\nThe program will now exit!!.\n" << endl;
	}

	return successRun;
}

int retX1()
{
	return tempX1;
}
int retY1()
{
	return tempY1;
}
int retX2()
{
	return tempX2;
}
int retY2()
{
	return tempY2;
}
int sendtoStartup(int x1, int y1, int x2, int y2)
{
	int backval;
	int t_argc = 5;
	QStringList tInput;

	QString in1 = QString::number(x1, 10);
	QString in2 = QString::number(y1, 10);
	QString in3 = QString::number(x2, 10);
	QString in4 = QString::number(y2, 10);

	tInput.append(in1);
	tInput.append(in2);
	tInput.append(in3);
	tInput.append(in4);

	backval = StartupErrorCheck(t_argc, tInput);

	return backval;
}
