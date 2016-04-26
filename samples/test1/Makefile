# Sample code for Keystone Assembler Engine (www.keystone-engine.org).
# By Nguyen Anh Quynh, 2016

.PHONY: all clean

KEYSTONE_LDFLAGS = -lkeystone -lstdc++ -lm

all:
	${CC} -o test1 test1.c ${KEYSTONE_LDFLAGS}
	${CC} -o test2 test2.c ${KEYSTONE_LDFLAGS}

clean:
	rm -rf *.o test1 test2
