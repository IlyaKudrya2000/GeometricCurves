all: build_with_static build_with_dynamic 
main.o: main.cpp
	g++ -c main.cpp -o main.o
GeometricCurves.o: GeometricCurves.cpp
	g++ -c -fPIC GeometricCurves.cpp -o GeometricCurves.o
GeometricCurves.so: GeometricCurves.o
	g++ -shared -o libGeometricCurves.so GeometricCurves.o
clean:
	rm -rf * *.o *.so
rebuild:
	Make clean
	Make all
build_with_static: main.o GeometricCurves.o
	g++ main.o GeometricCurves.o -o CurvesStatic
build_with_dynamic: main.o GeometricCurves.so
	g++ main.o -L. libGeometricCurves.so -Wl,-rpath,. -o CurvesDynamic
