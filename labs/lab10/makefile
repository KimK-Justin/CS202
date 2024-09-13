CXX = g++
CXXFLAGS = -Wall

lab10: Landmass.o Continent.o Island.o lab10.cpp
	$(CXX) $(CXXFLAGS) Landmass.o Island.o Continent.o lab10.cpp -o lab10

Landmass.o: Landmass.h Landmass.cpp
	$(CXX) $(CXXFLAGS) -c Landmass.cpp

Continent.o: Continent.h Continent.cpp Landmass.o
	$(CXX) $(CXXFLAGS) -c Continent.cpp

Island.o: Island.h Island.cpp Landmass.o
	$(CXX) $(CXXFLAGS) -c Island.cpp

run:
	./lab10

clean:
	rm *.o
	rm *~