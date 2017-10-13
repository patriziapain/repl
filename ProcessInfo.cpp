#include "ProcessInfo.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//getters for global variables
string getJobStdin(){
  return job_STDIN;
}

string getJobStdout(){
  return job_STDOUT;
}

string getJobStderr(){
  return job_STDERR;
}

int getNumPipes(){
  return numPipes;
}

int getNumProcesses(){
  return numProcesses;
}

vector<string> getProcesses(){
  return processes;
}

//setters for global variables
void setJobStdin(string job){
  job_STDIN = job;
}

void setJobStdout(string job){
  job_STDOUT = job;
}

void setJobStderr(string job){
  job_STDERR = job;
}

void setNumPipes(int num){
  numPipes = num;
}

void setNumProcesses(int num){
  numProcesses = num;
}

void setProcesses(vector<string> p){
  processes = p;
}
