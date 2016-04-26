//
// Created by Jake Olkin on 4/19/16.
//
#include <iostream>
#include "RobotList.h"


RobotList::RobotList()
{
    //robots = new Robot[tableSize];
};

void RobotList::printList()
{

    for(int i = 0; i < tableSize; i++)
    {
        if( robots[i].name.compare("") != 0) {

            cout << robots[i].name << "(" << robots[i].yearEst << "): " << robots[i].offensivePower << endl;
        }
    }
}

void RobotList::addRobot(string n, int p, int y)
{
    bool added = false;
    for(int i = 0; i < tableSize; i++)
    {
        if( robots[i].name.compare("") == 0 && !added)
        {
            robots[i] = Robot(n, p, y);
            added = true;
            break;
        }
        else if(robots[i].name.compare(n) == 0)
        {
            added = true;
            cout<<"this robot is already a part of this list"<<endl;
        }
    }
    if(!added)
    {
        cout<<"You have too many robots. You need to remove robots from your drafting list before you add again.";
    }

}

// Merges two sections of words[] together so elements from p to q are in order
void RobotList::mergeName(Robot robots[], int p, int mid, int q, int size)
{
    Robot *temp = new Robot[size];

    for (int i = p; i <= q; i++)
    {
        temp[i] = robots[i];
    }

    int i = p;
    int j = mid + 1;
    int k = p;

    while (i <= mid && j <= q)
    {
        if (temp[i].name.compare(temp[j].name) < 0)
        {
            robots[k] = temp[i];
            i++;
        }
        else
        {
            robots[k] = temp[j];
            j++;
        }
        k++;
    }
    while ( i <= mid )
    {
        robots[k] = temp[i];
        k++;
        i++;
    }
    while (j <= q)
    {
        robots[k] = temp[j];
        k++;
        j++;
    }

    // delete the temp array so there is no memory leak
    //delete[] *temp;
}

//use a merge sort to sort the list to find the most commonly used words
void RobotList::sortByName(Robot *robots, int low, int high, int size)
{
    if (low < high)
    {
        int mid = (high+low)/2;
        sortByName(robots, low, mid, size);
        sortByName(robots, mid+1, high, size);
        mergeName(robots, low, mid, high, size);
    }
}

// Merges two sections of words[] together so elements from p to q are in order
void RobotList::mergeYear(Robot robots[], int p, int mid, int q, int size)
{
    Robot *temp = new Robot[size];

    for (int i = p; i <= q; i++)
    {
        temp[i] = robots[i];
    }

    int i = p;
    int j = mid + 1;
    int k = p;

    while (i <= mid && j <= q)
    {
        if (temp[i].yearEst > temp[j].yearEst)
        {
            robots[k] = temp[i];
            i++;
        }
        else
        {
            robots[k] = temp[j];
            j++;
        }
        k++;
    }
    while ( i <= mid )
    {
        robots[k] = temp[i];
        k++;
        i++;
    }
    while (j <= q)
    {
        robots[k] = temp[j];
        k++;
        j++;
    }

    // delete the temp array so there is no memory leak
    //delete[] *temp;
}

//use a merge sort to sort the list to find the most commonly used words
void RobotList::sortByYear(Robot *robots, int low, int high, int size)
{
    if (low < high)
    {
        int mid = (high+low)/2;
        sortByYear(robots, low, mid, size);
        sortByYear(robots, mid+1, high, size);
        mergeYear(robots, low, mid, high, size);
    }
}

// Merges two sections of words[] together so elements from p to q are in order
void RobotList::mergePower(Robot robots[], int p, int mid, int q, int size)
{
    Robot *temp = new Robot[size];

    for (int i = p; i <= q; i++)
    {
        temp[i] = robots[i];
    }

    int i = p;
    int j = mid + 1;
    int k = p;

    while (i <= mid && j <= q)
    {
        if (temp[i].offensivePower > temp[j].offensivePower)
        {
            robots[k] = temp[i];
            i++;
        }
        else
        {
            robots[k] = temp[j];
            j++;
        }
        k++;
    }
    while ( i <= mid )
    {
        robots[k] = temp[i];
        k++;
        i++;
    }
    while (j <= q)
    {
        robots[k] = temp[j];
        k++;
        j++;
    }

    // delete the temp array so there is no memory leak
    //delete[] *temp;
}

//use a merge sort to sort the list to find the most commonly used words
void RobotList::sortByOffensivePower(Robot *robots, int low, int high, int size)
{
    if (low < high)
    {
        int mid = (high+low)/2;
        sortByOffensivePower(robots, low, mid, size);
        sortByOffensivePower(robots, mid+1, high, size);
        mergePower(robots, low, mid, high, size);
    }
}

void RobotList::sortByName()
{
    int top;
    for(int i = 0; i < tableSize; i++)
    {

        if(robots[i].name.compare("") == 0)
        {
            top = i-1;
            break;
        }
    }
    sortByName(robots, 0, top, top);
}

void RobotList::sortByOffensivePower()
{
    int top;
    for(int i = 0; i < tableSize; i++)
    {
        if(robots[i].name.compare("") == 0)
        {
            top = i;
            break;
        }
    }
    sortByOffensivePower(robots, 0, top, top);
}

void RobotList::sortByYear()
{
    int top;
    for(int i = 0; i < tableSize; i++)
    {
        if(robots[i].name.compare("") == 0)
        {
            top = i;
            break;
        }
    }
    sortByYear(robots, 0, top, top);
}

void RobotList::createAlliance(string team1, string team2, string team3)
{
    Alliance *current = start;
    while(current != NULL || current->next != NULL)
    {
        current = current->next;
    }
    current->next = new Alliance(find(team1), find(team2), find(team3));
}

void RobotList::printAlliances()
{
    Alliance *current = start;
    if(current == NULL)
    {
        cout<<"No alliances have been created"<<endl;
    }
    else
    {
        while(current != NULL)
        {
            for(int i = 0; i < 3; i++)
            {
                cout<<current->robots[i].name<<" ";
            }
            cout<<endl;
            current = current->next;
        }
    }
}

Robot RobotList::find(string name)
{
    for(int i = 0; i < tableSize; i++)
    {
            if (robots[i].name.compare(name) == 0) {
                return robots[i];
            }

    }
    return Robot("", 0, 0);
}

void RobotList::deleteRobot(string n)
{
    Robot target = Robot("", 0, 0);
    int index;
    for(int i = 0; i < tableSize; i++)
    {
            if (robots[i].name.compare(n) == 0) {
                target = robots[i];
                index = i;
            }

    }
    if(target.name.compare("") != 0)
    {
        target.name = "";
        target.offensivePower = 0;
        target.yearEst = 0;
        while(index < tableSize - 1 && robots[index+1].name.compare("") != 0)
        {
            robots[index].name = robots[index+1].name;
            robots[index].offensivePower = robots[index+1].offensivePower;
            robots[index].yearEst = robots[index+1].yearEst;
            index++;
        }
        robots[index].name = "";
        robots[index].offensivePower = 0;
        robots[index].yearEst = 0;
    }
}