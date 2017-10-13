#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> argVec(string process){

  vector<string> args;
  
  int i = 0;

  while(i != (int)process.size()){
    
    while(i != (int)process.size() && isspace(process[i])) i++;

    int j = i;
    
    while(j != (int)process.size() && !isspace(process[j])) j++;

    if(i != j){
      args.push_back(process.substr(i, j - i));
      i = j;
    }
  }//while
  
  return args;
}//argVec

int main(){

  cout.setf(std::ios_base::unitbuf);

  //  ProcessInfo info();

  while(true){

    string in;
    string pipeD = "|";
    string inputD = "<";
    string outputD = " > ";
    string outAppD = " >> ";
    string errorD = " e> ";
    string errAppD = " e>> ";

    cout << "repl$ ";
    getline(cin, in);

    if(in == "exit" || in == "quit") exit(EXIT_SUCCESS);
    
    string job_STDIN = "STDIN_FILENO";
    string job_STDOUT = "STDOUT_FILENO";
    string job_STDERR = "STDERR_FILENO";
    int numPipes = 0;
    int numProcesses = 1;    
    vector<string> args;
    
    if(in.find(pipeD) != string::npos){
      int count=0;

      for(unsigned int i = 0; i < in.size(); i++){
	if(in[i] == '|')
	  count++;
      }
      numPipes = count;
    }
    if(in.find(inputD) != string::npos){

      int eoi;
      int pos = in.find(inputD)+2;
      string input = in.substr(pos, in.size());
      
      if((eoi = input.find(" ")) != (int)string::npos){
	input.erase(eoi, in.size());
      }
      else eoi = in.size();
      
      job_STDIN = input;
      in.erase(pos-2, input.size()+2);
    }
    if(in.find(outputD) != string::npos){
      
      int eou;
      int pos = in.find(outputD)+3;
      string output = in.substr(pos, in.size());
            
      if((eou = output.find(" ")) != (int)string::npos){
	output.erase(eou, in.size());
      }
      else eou = in.size();
      job_STDOUT = output.append(" (truncate)");
      in.erase(pos-3, output.size()+3);
    }
    if(in.find(outAppD) != string::npos){
      
      int eou;
      int pos = in.find(outAppD)+4;
      string output = in.substr(pos, in.size());
      
      if((eou = output.find(" ")) != (int)string::npos){
	output.erase(eou, in.size());
      }
      else eou = in.size();
      job_STDOUT = output.append(" (append)");
      in.erase(pos-4, output.size()+4);
    }
    if(in.find(errorD) != string::npos){
      
      int eoe;
      int pos = in.find(errorD)+4;
      string error = in.substr(pos, in.size());
      
      if((eoe = error.find(" ")) != (int)string::npos){
	error.erase(eoe, in.size());
      }
      else eoe = in.size();
      job_STDERR = error.append(" (truncate)");
      in.erase(pos-4, error.size()+4);
    }
    if(in.find(errAppD) != string::npos){
      
      int eoe;
      int pos = in.find(errAppD)+5;
      string error = in.substr(pos, in.size());
      cout << "error: " << error << endl;

      if((eoe = error.find(" ")) != (int)string::npos){
	error.erase(eoe, in.size());
      }
      else eoe = in.size();
      job_STDERR = error.append(" (append)");
      in.erase(pos-5, error.size()+5);
    }
    
    numProcesses = numPipes + 1;

    //printing out everything
    cout << "\n";
    cout << "Job STDIN  = " << job_STDIN << endl;
    cout << "Job STDOUT = " << job_STDOUT << endl;
    cout << "Job STDERR = " << job_STDERR << endl;
    cout << "\n";
    cout << numPipes << " pipe(s)" << endl;
    cout << numProcesses << " process(es)" << endl;
    
    for(int i = 0; i < numProcesses; i++){
      
      int beg=0;
      int pos=0;
      string process;
      
      pos = in.find(" | ");
      
      if(pos == (int)string::npos){
	process = in.substr(0, in.size());
      }
      else{
	process = in.substr(beg, pos);
      }
      
      cout << "\n";
      cout << "Process " << i << " argv:\n";
      
      //create argc vector
      args = argVec(process);
      
      //for loop to print it out separating it by spaces
      for(int i = 0; i < (int)args.size(); i++){
	cout << i << ": " << args[i] << endl;
      }

      //removing the process
      in.erase(0, process.size()+3);
    }//for

    cout << "\n";
   }//while
}//main
