#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

queue<int> stack;

int returnSomethingWithStack(string command, queue<int> ans){
    if (command == "front") return ans.empty() ? -1 : ans.front();
    if (command == "back") return ans.empty() ? -1 : ans.back();
    else if (command == "pop") {
        if (ans.empty()) {
            return -1;
        }
        int a = stack.front();
        stack.pop();
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
            stack.push(stoi(cmd2));
        }
        else {
            cout << returnSomethingWithStack(command, stack) << '\n';
        }

    }

    return 0;
}