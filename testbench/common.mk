
VERILATOR_INCLUDE=/usr/share/verilator/include
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)
CXXFLAGS=-I ${VERILATOR_INCLUDE} -I ${VERILATOR_INCLUDE}/vltstd
V_SOURCES= $(wildcard ../../src/$(CORETYPE)/*.v*) ../config.vh 
VFLAGS=-Wno-fatal -I.. -I../../src/$(CORETYPE)
TESTDIR=../../tests
TESTS=$(notdir $(patsubst %.S,%,$(wildcard $(TESTDIR)/*.S)))

build: Vtoplevel.h main.cpp
	${MAKE} run

Vtoplevel.h: $(V_SOURCES)
	verilator ${VFLAGS} --cc ../../src/$(CORETYPE)/toplevel.v --Mdir .

run: $(addsuffix .run,$(TESTS))

%.run: testbench
	./testbench +text_file=$(TESTDIR)/$(@:.run=).text.vh +data_file=$(TESTDIR)/$(@:.run=).data.vh

testbench: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} ${VERILATOR_INCLUDE}/verilated.cpp ${VERILATOR_INCLUDE}/verilated_vcd_c.cpp -o testbench

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

main.cpp: ../main.cpp
	cp ../main.cpp .

clean:
	rm -f testbench main.cpp ${OBJS} $(wildcard V*)
