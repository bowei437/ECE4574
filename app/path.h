////////////////////////////////////////////////////////
// ECE 4574, Assignment 1, Bowei Zhao
//// PID: 905789193
// email: bowei@vt.edu
// 
// description:  Path Header file
//

#ifndef PATH_H
#define PATH_H

#include <QDate>
#include <QDateTime>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QList>
#include <QTextStream>
#include <QDebug>
#include <QLocale>
#include <QtAlgorithms>
#include <QChar>
#include <QCoreApplication>
#include <QRegularExpression>
//#include <QApplication>
//#include <QMainWindow>
#include <QVector>
#include <QMap>


#include <iostream>
#include <fstream>
#include <algorithm> 
#include <string>
#include <vector>
#include <stdbool.h>
#include <stdlib.h>
#include <exception>
#include <stdio.h>
#include <math.h>
#include <ctime>
#include <iomanip>
#include <queue>
///////////////////////////////////////////////////////////////////

using namespace std;

#define XYSize 		60
#define MinSize 	0

extern int BoardMap[XYSize][XYSize];

int StartupErrorCheck(int &argc, QStringList arginput);


string pathFind( const int & xStart, const int & yStart, 
                 const int & xFinish, const int & yFinish );

string DisplayRes(int inX1, int inY1, int inX2, int inY2);

int samplecase(int input);
int retX1();
int retY1();
int retX2();
int retY2();
int retArgc();
int sendtoStartup(int x1, int y1, int x2, int y2);
/*
int StartX;
int StartY;
int FinishX;
int FinishY;
*/

class node
{
    // current position
    int xPos;
    int yPos;
    // total distance already travelled to reach the node
    int level;
    // priority=level+remaining distance estimate
    int priority;  // smaller: higher priority

    public:
        node(int xp, int yp, int d, int p);
    
        int getxPos() const;
        int getyPos() const;
        int getLevel() const;
        int getPriority() const;

        void updatePriority(const int & xDest, const int & yDest);


        // give better priority to going strait instead of diagonally
        void nextLevel(const int & i); // i: direction

        
        // Estimation function for the remaining distance to the goal.
        const int & estimate(const int & xDest, const int & yDest) const;
};

#endif // PATH_H
