//
// Created by Jake Olkin on 4/18/16.
//

#ifndef OLKIN_CSCI2270_FINALPROJECT_ROBOTLIST_H
#define OLKIN_CSCI2270_FINALPROJECT_ROBOTLIST_H

using namespace std;

struct Robot
{
    string name;
    int offensivePower;
    int yearEst;

    Robot(string n, int p, int y)
    {
        name = n;
        offensivePower = p;
        yearEst = y;
    }
};

struct Alliance
{
    Robot[] robots;
    Alliance(Robot r1, Robot r2, Robot r3)
    {
        robots = new Robot[3];
        robots[0] = r1;
        robots[1] = r2;
        robots[2] = r3;
    }
};

class RobotList
{
public:
    RobotList();
    ~RobotList();
    void printList();
    void addRobot(string n, int p, int y);
    void deleteRobot(string n);
    void sortByName();
    void sortByOffensivePower();
    void sortByYear();
    int listSize();
    void createAlliance(string team1, string team2, string team3);
    void printAlliances();
};

#endif //OLKIN_CSCI2270_FINALPROJECT_ROBOTLIST_H
