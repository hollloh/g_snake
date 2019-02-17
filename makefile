CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
sfml_lib = -lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR = src
INCLUDES = -Iinclude # when compiling, check this folder for include files.
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# we first make a variable to find all .cpp files in the src directory.
# we then make all those .cpp files object files (check out 'patsubst' if you forget how that's done).
# we then remove the path/to/src/dir/ with $(notdir).
# we then add the prefix path/to/obj/dir/ so the makefile knows where the object files are.
source_files = $(wildcard $(SRC_DIR)/*.cpp)
object_files = $(addprefix $(OBJ_DIR)/, $(notdir $(source_files:.cpp=.o)))


all: $(BUILD_DIR)/executable

remake:
	rm -rv $(BUILD_DIR) && make all

clean:
	rm -rv $(BUILD_DIR)

.PHONY: all executable remake clean


# make a build and object directory if not already made.
$(info $(shell mkdir -p $(BUILD_DIR)))
$(info $(shell mkdir -p $(OBJ_DIR)))


# make the executable; put it in the build directory.
$(BUILD_DIR)/executable: $(object_files)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(sfml_lib)


# compile an object file for every .cpp file.
# using -o $@ places the output at the location of the 'target'.
# i note it because it wasn't obvious for me.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ $(INCLUDES) -o $@

