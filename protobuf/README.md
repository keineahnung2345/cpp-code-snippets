# Proto Buffers
Proto Buffers is a data format for your data to be serialized.  

## protoc
```sh
protoc -I=$SRC_DIR --cpp_out=$DST_DIR --java_out=$DST_DIR --python_out=$DST_DIR $SRC_DIR/<your_messages>.proto
```

## g++
```sh
g++ <file_that_access_your_messages>.cpp <your_messages>.pb.cc -lprotobuf -pthread -std=c++11
```
