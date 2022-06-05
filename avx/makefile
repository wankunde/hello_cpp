CXXFLAGS = -pthread -fPIC $(COMMON_FLAGS) $(WARNINGS) -std=c++11

hello_avx: hello_avx.c
	g++ -o hello_avx $(CXXFLAGS) -mavx2 -Wall hello_avx.c
