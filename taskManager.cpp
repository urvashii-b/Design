// a task manager that can add new tasks and delete the least frequent ones
#include<bits/stdc++.h>
using namespace std;

class TaskManager{
  private:
    unordered_map<string,int> taskFreq;
    list<string> taskList;
    unordered_map<string,list<string>::iterator> taskPos;
  public:
    void addTask(const string& task){
      if(taskFreq.find(task)==taskFreq.end()){
        taskList.push_back(task);
        taskPos[task] = --taskList.end();
        taskFreq[task] = 1;
      }else{
        taskFreq[task]++;
      }
    }

    void removeLeastFrequent(){
      if(taskList.empty()){
        cout<<"No tasks to remove";
        return;
      }
      string leastFreqTask = taskList.front();
      taskList.pop_front();
      cout<<"Removing least frequent task";
      taskFreq.erase(leastFreqTask);
      taskPos.erase(leastFreqTask);
    }

    void displayTasks() const{
      cout<<"Tasks in order: "<<endl;
      for(const auto& task: taskList){
        cout<<task<<" frequency: "<<taskFreq.at(task)<<")"<<endl;
      }
    }
};

int main(){
  TaskManager taskmanager;
  taskmanager.addTask("Task1");
  taskmanager.addTask("Task2");
  taskmanager.addTask("Task1");
  taskmanager.addTask("Task3");

  return 0;
}