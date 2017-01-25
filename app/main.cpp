////////////////////////////////////////////////////////
// ECE 4574, Assignment 1, Bowei Zhao
//// PID: 905789193
// email: bowei@vt.edu
// 
// description:  Main Implementation file
//

#include "path.h"

QTextStream outS(stdout); // output stream for standard output
QTextStream inS(stdin); // input stream for standard input
QTextStream errS(stderr); // error stream for standard error exception

//int BoardMap[XYSize][XYSize];

int StartX;
int StartY;
int FinishX;
int FinishY;

int main (int argc, char* argv[])
{ 
	QCoreApplication app(argc, argv); // used to create a seperate instance for error checking. 
    QStringList arginput = app.arguments();
	int initialSuccess = StartupErrorCheck(argc, arginput); // sneds to other function to check if valid


    if (initialSuccess == 0)
    {

		return 0;
    }
    else
    {
    	string Stdroute;
    	QString Qroute;
    	//qDebug() << "argc is: " << argc << endl;


		StartX = arginput[1].toInt();
		StartY = arginput[2].toInt();
		FinishX = arginput[3].toInt();
		FinishY = arginput[4].toInt();

		outS << "-- Welcome to Bowei's simple pathfinding program --" << endl;
		outS << "Start point: " << StartX << "," << StartY << endl;
		outS << "Finish Point: " << FinishX << "," << FinishY << endl;

		Stdroute = DisplayRes(StartX, StartY, FinishX, FinishY);
		//outS << "\n----------\nPathfinding Stdroute:" << endl;

		//Qroute = QString::fromStdString(Stdroute);
		//outS << Qroute << endl;


    }

	return 0;
}


