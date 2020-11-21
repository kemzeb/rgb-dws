#
obj = rgbhlr.o rgbstats.o staging.o

cdws : $(obj)
	g++ -std=c++11 -Wall -W -o cdws $(obj)

rgbhlr.o : rgbhlr.cpp rgbhlr.h
	g++ -std=c++11 -Wall -W -c rgbhlr.cpp

rgbstats.o : rgbstats.cpp rgbhlr.h rgbstats.h
	g++ -std=c++11 -Wall -W -c rgbstats.cpp

staging.o : staging.cpp rgbhlr.h rgbstats.h
	g++ -std=c++11 -Wall -W -c staging.cpp

clean :
	rm cdws $(obj)



