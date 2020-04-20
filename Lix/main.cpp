//
//  main.cpp
//  Lix
//
//  Created by Conner Vieira/V0LT on 4/20/20

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    string i = ""; // Set a placeholder for the user's input
    bool sudoverified = false; // Set a placeholder for whether or not the user has entered the correct root passwords
    cout << "" << endl;
    for (;;) {
        cout << "lix@linuxsimulator:~$ ";
        getline(cin, i); // Take the user's input
        
        // Determine what the input is and provide the appropriate response
        if (i == "apt-get update" || i == "apt update") {
            cout << "Reading package lists... Done" << endl;
            cout << "E: Could not open lock file /var/lib/apt/list/lock - open (13: Permission deined)" << endl;
            cout << "E: Unable to lock directory /var/lib/apt/lists" << endl;
            cout << "W: Problem unlinking the file /var/cache/apt/pkgcache.bin - RemoveCaches (13: Permission denied)" << endl;
            cout << "W: Problem unlinking the file /var/cache/apt/srcpkgcache.bin - RemoveCaches (13: Permission denied)" << endl;
            // Simulate apt-get update being run without root, and show appropriate errors
        } else if (i == "sudo apt-get update" || i == "sudo apt update") {
            cout << "[sudo] password for lix: ";
            getline(cin, i); // Take the input from the user
            if (i == "root") {
                sudoverified = true;
            } else {
                system("sleep 1"); // Wait 1 second to simulate authentication
                cout << "Sorry, try again." << endl;
                cout << "[sudo] password for lix: ";
                getline(cin, i); // Take the input from the user
                if (i == "root") {
                    sudoverified = true;
                } else {
                    system("sleep 1"); // Wait 1 second to simulate authentication
                    cout << "Sorry, try again." << endl;
                    cout << "[sudo] password for lix: ";
                    getline(cin, i); // Take the input from the user
                    if (i == "root") {
                        sudoverified = true;
                    } else { // Indicate that the user failed to enter the correct sudo password 3 times
                        sudoverified = false;
                    }
                }
            }
            
            if (sudoverified == true) {
                cout << "Hit:1 http://us.archive.ubuntu.com/ubuntu eoan InRelease" << endl;
                cout << "Hit:2 http://us.archive.ubuntu.com/ubuntu eoan-updates InRelease" << endl;
                cout << "Hit:3 http://us.archive.ubuntu.com/ubuntu eoan-backports InRelease [88.8 kB]" << endl;
                cout << "Hit:4 http://us.archive.ubuntu.com/ubuntu eoan-security InRelease" << endl;
                cout << "Fetched 88.8 kB in 1s (500 kB/s)" << endl;
                cout << "Reading package lists... Done" << endl;
            } else {
                cout << "sudo: 3 incorrect password attempts" << endl;
            }
        } else if (i == "clear") {
            system("clear");
        } else if (i == "sudo") {
            cout << "usage: sudo -h | -K | -k | -V" << endl;
            cout << "usage: sudo -v [-AknS] [-g group] [-h host] [-p prompt] [-u user]" << endl;
            cout << "usage: sudo -l [-AknS] [-g group] [-h host] [-p prompt] [-U user] [-u user] [command]" << endl;
            cout << "usage: sudo [-AbEHkPS] [-r role] [-t type] [-C num] [-g group] [-h host] [-p prompt] [-T timeout] [-u user] [VAR=value] [-i|-s] [<command>]" << endl;
            cout << "usage: sudo [-AknS] [-r role] [-t type] [-C num] [-g group] [-h host] [-p prompt] [-T timeout] [-u user] file ..." << endl;
        } else if (i == "pwd") {
            cout << "/home/lix" << endl;
            
            
            // Create placeholders for file management commands
        } else if (i.substr(0, 3) == "cd ") {
            cout << "You've entered the 'cd' command, which is used to change directories in your file system. However, file management commands have not yet been implemented into Lix." << endl;
        } else if (i.substr(0, 3) == "rm ") {
            cout << "You've entered the 'rm' command, which is used to remove files and directories in your file system. However, file management commands have not yet been implemented into Lix." << endl;
        } else if (i.substr(0, 6) == "mkdir ") {
            cout << "You've entered the 'mkdir' command, which is used to create directories in your file system. However, file management commands have not yet been implemented into Lix." << endl;
        } else if (i.substr(0, 6) == "touch ") {
            cout << "You've entered the 'touch' command, which is used to create files in your file system. However, file management commands have not yet been implemented into Lix." << endl;
        } else if (i.substr(0, 4) == "cat ") {
            cout << "You've entered the 'cat' command, which is used to read contents of files in your file system. However, file management commands have not yet been implemented into Lix." << endl;
        } else if (i.substr(0, 3) == "ls ") {
            cout << "You've entered the 'ls' command, which is used to list the contents of directories in your file system. However, file management commands have not yet been implemented into Lix." << endl;
        
        
        } else if (i.substr(0, 5) == "echo " || i == "echo") {
            if (i.length() != 4) {
                cout << i.substr(5, 10000000) << endl;
            }
        } else if (i == "exit") {
            cout << "logout" << endl;
        } else if (i == "logout") {
            break;
        } else if (i == "shutdown") {
            cout << "Scheduling for shutdown in 60 seconds, use 'shutdown -c' to cancel." << endl;
            cout << "shutdown: Failed to schedule. Lix is a single threaded process." << endl;
        } else if (i == "shutdown now") {
            cout << "Shutting down..." << endl;
            break;
        }
    }
    return 0;
}
