CC 			= gcc
CCFLAGS 	= -Wall -Wextra -std=c99 -ggdb
LDFLAGS 	= -lGL -lGLU -lglut -lm
TARGET 		= americki-fudbal

.PHONY: clean zip

$(TARGET): main.o callbacks.o functions.o actions.o image.o
	$(CC) $(CCFLAGS) -o $@ $^ $(LDFLAGS)

main.o: main.c
	$(CC) $(CCFLAGS) -c -o $@ $<

callbacks.o: callbacks.c callbacks.h global_variables.h
	$(CC) $(CCFLAGS) -c -o $@ $<

functions.o: functions.c functions.h global_variables.h
	$(CC) $(CCFLAGS) -c -o $@ $<

actions.o: actions.c actions.h global_variables.h 
	$(CC) $(CCFLAGS) -c -o $@ $<
	
image.o : image.c image.h
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f *.o
	rm -f $(TARGET)

zip:
	zip -r $(TARGET).zip ./
