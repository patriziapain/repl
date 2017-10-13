#ifndef PROCESSINFO_H
#define PROCESSINFO_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Holds information about a process
 **/
class ProcessInfo{
  
  string job_STDIN;
  string job_STDOUT;
  string job_STDERR;
  
  int numPipes;
  int numProcesses;
  
  vector<string> processes;
  
 public:

  /**
   * Getters for the global variables
   **/
  string getJobStdin();
  string getJobStdout();
  string getJobStderr();
  int getNumPipes();
  int getNumProcesses();
  vector<string> getProcesses();

  /**
   * Setters for the global variables
   **/
  void setJobStdin(string job);
  void setJobStdout(string job);
  void setJobStderr(string job);
  void setNumPipes(int num);
  void setNumProcesses(int num);
  void setProcesses(vector<string> p);
  
};//ProcessInfo

#endif
