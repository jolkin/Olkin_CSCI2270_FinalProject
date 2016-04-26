//
// Created by Jake Olkin on 4/18/16.
//

#include <string>

#ifndef OLKIN_CSCI2270_FINALPROJECT_ROBOTLIST_H
#define OLKIN_CSCI2270_FINALPROJECT_ROBOTLIST_H

using namespace std;

struct Robot
{
    string name;
    int offensivePower;
    int yearEst;

    Robot()
    {
        name = "";
        offensivePower = 0;
        yearEst = 0;
    }
    Robot(string n, int p, int y)
    {
        name = n;
        offensivePower = p;
        yearEst = y;
    }
};

struct Alliance
{
    Robot robots[3];
    Alliance(Robot r1, Robot r2, Robot r3)
    {
        robots[0] = r1;
        robots[1] = r2;
        robots[2] = r3;
    }
    Alliance *next;
};

class RobotList
{
public:
    RobotList();
    ~RobotList();
    void printList();
    void addRobot(string n, int p, int y);
    void deleteRobot(string n);
    void sortByName(Robot *robots, int low, int high, int size);
    void sortByOffensivePower(Robot *robots, int low, int high, int size);
    void sortByYear(Robot *robots, int low, int high, int size);
    void createAlliance(string team1, string team2, string team3);
    void sortByName();
    void sortByOffensivePower();
    void sortByYear();
    void printAlliances();
    Robot find(string name);


private:
    int tableSize = 12;
    Robot *robots = new Robot[12];
    Alliance *start;
    void mergeName(Robot robots[], int low, int mid, int high, int size);
    void mergeYear(Robot robots[], int low, int mid, int high, int size);
    void mergePower(Robot robots[], int low, int mid, int high, int size);
};

#endif //OLKIN_CSCI2270_FINALPROJECT_ROBOTLIST_H
