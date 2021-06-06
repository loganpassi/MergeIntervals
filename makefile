MergeIntervals: MergeIntervals.o
	g++ MergeIntervals.o -o MergeIntervals

MergeIntervals.o: MergeIntervals.cpp
	g++ -c MergeIntervals.cpp

clean:
	rm *.o MergeIntervals