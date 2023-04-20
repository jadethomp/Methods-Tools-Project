#include <iostream>
#include <vector>
#include <string>

#include "User.h"
//FIXME include other class files

using namespace std;

//this might be a good idea, i dunno
int readFile(string filename){



}

int main(){
    int numInput;
    int loggedIn = 0;
    string input;
    User current;
    vector<User> users;

    //read in files//



    cout << "Welcome to Totally Real Games - the best e-commerce store in town!" << endl;
    //main loop
    while(1) {
        //pre-login loop
        while (loggedIn == 0) {
            cout << "Please select an option to continue.\n"
                    "(1)Login\n(2)Register\n(3)Exit\n>>";
            cin >> numInput;
            if (numInput == 1) {
                //login loop
                while(1) {
                    //prompt for login
                    cout << "Enter your username, or enter X to cancel.\n>>";
                    cin >> input;
                    //check if username is registered
                        //if registered, keep going
                        //if not, go back to beginning of login loop
                        //if 'X', break loop and loop back to pre-login options
                    //enter password loop
                    while(1){
                        input = "";
                        cout << "Enter your password, or enter X to cancel.\n>>";
                        cin >> input;
                        //check if password is correct
                            //if correct, loggedIn = 1, break
                            //if incorrect, go back to beginning of password loop
                            //if 'X', break loop and loop back to pre-login options
                    }
                    //if input == 'X', break
                }
            }
            else if (numInput == 2) {
                //make a new user
            }
            else if (numInput == 3) {
                return 0;
            }
        }
        //they made it through! post-login below..



    }

    return 0;
}
