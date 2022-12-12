# CS225_Final_Project

## Summary

This is a final project repo for UIUC CS225 fall 2022. In this project, we aim to use page rank analysis, graph implementation, and shortest path algorithm to find out which website has greater importance than others. The data set we're using is [Web Graph from the Google programming contest, 2002](http://snap.stanford.edu/data/web-Google.html).

## Github File Structure

- All major files are located at root directory at [`final_project`](https://github.com/lucyzhou1031/CS225_Final_Project/tree/main/final_project).

- `main.cpp` at [/entry](https://github.com/lucyzhou1031/CS225_Final_Project/tree/main/final_project/entry).

- `test.cpp` at [/tests](https://github.com/lucyzhou1031/CS225_Final_Project/tree/main/final_project/tests).

## Code Execution

Clone this [repository](https://github.com/lucyzhou1031/CS225_Final_Project/tree/main/final_project) in your cs 225 docker.

`mkdir build` command to create the build folder
`cd build` command to enter the folder
`cmake ..` to build the make file that can execute the code
To run either the test cases or the main, `make` will always be the general command
To be more specific: `make main` is used only for execute main.cpp, and `make test` is used only for execute test.cpp
### Run Main

- `make` or `make main`

- `./main`

Then follow the instruction and enter any of the appropriate node IDs as required otherwise error will occur. Wait a few seconds for the data to come out: especially when the data set is large.
To terminate the program, use `Ctrl + C` if your are using a windows PC, or `Command + C` if it is a Mac. 

### To test the algorithm: Run Test

- `make` or `make test`

- `./test`
Then you can see that all tests are passed. 

## Team Members

**Xiaoqi Guo** (NetID: xiaoqig2)

**Xinyi Ye** (NetID: xinyiye4)

**Yixuan Zhou** (NetID: yixuan25)
