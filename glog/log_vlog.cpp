#include <glog/logging.h>

//g++ glog.cpp -lglog
//GLOG_v=7 GLOG_logtostderr=1 ./a.out

//https://stackoverflow.com/questions/40394102/vlog-doesnt-work-for-google-logging-library-glog

int main(int argc, char* argv[]) {
  // Initialize Google's logging library.
  google::InitGoogleLogging(argv[0]);
  int i = 3;

  LOG(INFO) << "Found " << 3 << " cookies";
  LOG(ERROR) << "Found " << 3 << " cookies";
  VLOG(5) << "vlog" << 4 << "abc" << 4.3 << i;
}

/*
I0109 14:14:01.028268 30790 glog.cpp:11] Found 3 cookies
E0109 14:14:01.028389 30790 glog.cpp:12] Found 3 cookies
I0109 14:14:01.028403 30790 glog.cpp:13] vlog4abc4.33
*/
