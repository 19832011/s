#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Process structure to store process details
struct Process {
    int id;
    int priority;
    int burst_time;
};

// Function to implement priority scheduling
void priorityScheduling(vector<Process>& processes) {
    // Sort processes based on priority (higher priority comes first)
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.priority > b.priority;
    });

    int total_time = 0;

    // Display the Gantt chart and calculate waiting time
    cout << "Gantt Chart:" << endl;
    cout << "---------------------------" << endl;
    cout << "| ID | Priority | Burst Time |" << endl;
    cout << "---------------------------" << endl;

    for (const Process& p : processes) {
        cout << "| " << p.id << "  |    " << p.priority << "     |      " << p.burst_time << "     |" << endl;
        total_time += p.burst_time;
    }

    cout << "---------------------------" << endl;
    cout << "Total Execution Time: " << total_time << endl;
}

int main() {
    int num_processes;

    cout << "Enter the number of processes: ";
    cin >> num_processes;

    // Input process details
    vector<Process> processes;
    for (int i = 0; i < num_processes; ++i) {
        Process p;
        p.id = i + 1;
        cout << "Enter priority for process " << p.id << ": ";
        cin >> p.priority;
        cout << "Enter burst time for process " << p.id << ": ";
        cin >> p.burst_time;
        processes.push_back(p);
    }

    // Call the priority scheduling function
    priorityScheduling(processes);

    return 0;
}
