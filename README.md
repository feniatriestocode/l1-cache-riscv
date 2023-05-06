# PRISCV: Parallel RISC-V
A parallel risc-v implementation for our Parallel Computer Architecture Class.A

## Implemented ISA
The base ISA is RV32I. On top of that we plan to implement:
* The M extention
* The C extention
* The V extention 

## Installation
Download the repository
```
git clone git@github.com:akastoras/priscv.git
```

## RISC-V ISA Compliance
To run the device verification tests, build the docker image, or download it from the docker hub.


* To create the image from the Dockerfile run
	```
	docker build -t riscv .
	```

* To download the image from docker hub run
	```
	docker pull ipanagou/riscv
	```

After acquiring the docker image in either way, create the container with the following instructions
```
docker run -it -d --name <container_name> --mount type=bind,source=<absolute-path>/priscv,destination=/home/docker/priscv ipanagou/riscv
docker exec -it <container_name> bash
```

## Building the tests
To build the unit tests, run 
```
make
```
in the **priscv/tests** folder

## Compile the model
To compile the **toplevel.v** RISCV model and **main.cpp** testbench into one executable, run
```
make verilate 
make build
```

## Run the tests
To run an individual test (for example addi.S), change the variable **TEST** of **testbench/Makefile** file to the test name and run
```
make run
```

To run the complete suite of unit tests, run
```
make -i check
```

## Makefile notes
For each folder than contains a .v file which in turn defines a module used in a .v in (potentially another folder) add -I\<relative path to the folder from folder testbench\> to the VERILATOR_INCLUDES variable in the **testbench/Makefile**. Basically, include all folders that contain a .v file

You don't need to `include paths, just the name of the file, the -I flag will take care of the rest