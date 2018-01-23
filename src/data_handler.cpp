#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "json.hpp"

// for convenience
using json = nlohmann::json;

using namespace std;

class FileNotOpenedException : public runtime_error {
 public:

  FileNotOpenedException(string filepath)
      : runtime_error("File " + filepath + " not opened for write.") {
  }
};

class DataHandler {
 private:
  string filepath;
  bool headerWritten;
  ofstream out;

  void writeHeader() {
    if (!out.is_open()) {
      throw FileNotOpenedException(filepath);
    }

    // column names for output file
    out << "cte" << "\t";
    out << "speed" << "\t";
    out << "angle" << "\t";
    out << "d_error" << "\t";
    out << "i_error" << "\t";
    out << "p_error" << "\t";
    out << "steering_angle" << "\t";
    out << "throttle" << "\t";
    out << endl;
}

 public:
  DataHandler(string filepath) {
    this->filepath = filepath;
    this->headerWritten = false;
  }

  void openFile() {
    out.open(filepath, ios::out);
    cout << "File " << filepath << " open for write." << endl;
  }

  void closeFile() {
    if (out.is_open()) {
      out.close();
      cout << "File " << filepath << " closed." << endl;
    }
  }

  void write(json &stats) {
    if (!out.is_open()) {
      throw FileNotOpenedException(filepath);
    }

    if (!headerWritten) {
      writeHeader();
      headerWritten = true;
    }

    string type;
    stringstream st;

    st << stats["cte"] << "\t";
    st << stats["speed"] << "\t";
    st << stats["angle"] << "\t";
    st << stats["d_error"] << "\t";
    st << stats["i_error"] << "\t";
    st << stats["p_error"] << "\t";
    st << stats["steering_angle"] << "\t";
    st << stats["throttle"] << "\t";
    st << endl;

    out << st.str();
  }
};
