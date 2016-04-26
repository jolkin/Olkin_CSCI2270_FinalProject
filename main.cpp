//
// Created by Jake Olkin on 4/12/16.
//

#include "RobotList.cpp"
#include <iostream>

//print the menu
void printMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Print Robot Pool" << endl;
    cout << "2. Add Robot to Roster" << endl;
    cout << "3. Delete Robot from Roster" << endl;
    cout << "4. Print Your Robot List" << endl;
    cout << "5. Sort Roster by Name" << endl;
    cout << "6. Sort Roster by Power" << endl;
    cout << "7. Sort Roster by Year Established." << endl;
    cout << "8. Create Alliance" << endl;
    cout << "9. Print Alliances" << endl;
    cout << "10. Quit" << endl;
}

RobotList *createPool()
{
    RobotList *out = new RobotList();

    out->addRobot("Beta", 3, 2015);
    out->addRobot("Bite Force", 10, 2000);
    out->addRobot("Bronco", 7, 2013);
    out->addRobot("Bull Dog", 5, 2012);
    out->addRobot("Captain Shrederator", 8, 2015);
    out->addRobot("Chomp", 2, 2008);
    out->addRobot("Chronic", 4, 2012);
    out->addRobot("Complete Control Mk V", 8, 2005);
    out->addRobot("Counter Revolution", 5, 2009);

    return out;



}

int main(int argc, char *argv[])
{


    RobotList *pool = createPool();
    RobotList *list = new RobotList();
    bool done = false;

    //iterate through the menu until the program has quit
    while(!done)
    {
        printMenu();
        string com;
        getline(cin, com);
        int command = stoi(com);

        switch(command)
        {
            case 1:
            {
                pool->printList();
                break;
            }
            //add a robot
            case 2:
            {
                cout<<"Enter name:"<<endl;
                string title;
                getline(cin, title);
                Robot *target = pool->find(title);
                if(target == NULL)
                {
                    cout<<"That robot doesn't exist in the pool"<<endl;
                }
                else
                {
                    list->addRobot(target->name, target->offensivePower, target->yearEst);
                    pool->deleteRobot(title);
                }
                break;
            }
                //delete a robot
            case 3:
            {
                cout<<"Enter title:"<<endl;
                string title;
                getline(cin, title);
                Robot *target = list->find(title);
                if(target == NULL)
                {
                    cout<<"That robot doesn't exist in your list"<<endl;
                }
                else
                {
                    pool->addRobot(target->name, target->offensivePower, target->yearEst);
                    list->deleteRobot(title);
                }
                break;
            }
                //print contents
            case 4:
            {
                list->printList();
                break;
            }
            case 5:
            {
                list->sortByName();
                break;
            }
            case 6:
            {
                list->sortByOffensivePower();
                break;
            }
            case 7:
            {
                list->sortByYear();
                break;
            }
            case 8:
            {
                string names[3];
                for(int i = 0; i < 3; i++)
                {
                    cout << "Enter team name" << endl;
                    string team;
                    getline(cin, team);
                    if (list->find(team) == NULL)
                    {
                        cout<<"Team does not exist"<<endl;
                        break;
                    }
                    else
                    {
                        names[i] = team;
                    }
                }
                list->createAlliance(names[0], names[1], names[2]);
                break;
            }

            case 9:
            {
                list->printAlliances();
                break;
            }
                //quit
            case 10:
            {
                cout <<"Goodbye!"<<endl;
                done = true;
            }
        }
    }

}