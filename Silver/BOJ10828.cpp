#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

vector<int> stack;

int returnSomethingWithStack(string command, vector<int> ans){
    if (command == "top") return ans.empty() ? -1 : ans.back();
    else if (command == "pop") {
        if (ans.empty()) {
            return -1;
        }
        int a = stack.back();
        stack.pop_back();
        return a;
    }
    else if (command == "size") return ans.size();
    else if (command == "empty") return ans.empty() ? 1 : 0;
    else {      
        return 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int command_num;
    cin >> command_num;
    cin.ignore();

    for (int i=0;i<command_num;i++){

        string command;

        getline(cin, command, '\n');

        string cmd1;
        string cmd2;
        cmd1 = command.substr(0, command.find(" "));
        cmd2 = command.substr(command.find(" ") + 1, command.length());
        if (cmd1 == "push") {
            stack.push_back(stoi(cmd2));
        }
        else {
            cout << returnSomethingWithStack(command, stack) << '\n';
        }

    }

    return 0;
}