#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(void){
    while(1){
        cout << "myshell> ";
        string input;

        getline(cin, input);

        if(input == "exit"){
            break;
        }

        pid_t pid = fork();

        if(pid == 0){
            const char *command = input.c_str();
            char *args[] = {(char *)command, nullptr};

            if(execve(args[0], args, nullptr) == -1){
                cout << "Command not found" << endl;
            }
        }
        else{
            int status;
            waitpid(pid, &status, 0);

            if(WIFEXITED(status)){
                cout << "Child process exited with status " << WEXITSTATUS(status) << endl;
            }
            else{
                cout << "Child process did not exit normally" << endl;
            }
        }
    }

    cout << "Exiting shell" << endl;   
    return 0;
}