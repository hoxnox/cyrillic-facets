#############
# targets:
#   all - build test and example application
#   test - build test application
#   example - build example application
#   lib - compile only sdtflib in release mode

first: all

#### Defige release/debug dependent vars
ifdef debug
OBJECTS_DIR   := Debug
CXXFLAGS      = -Wall -ggdb -g3 -O0 -DDEBUG
else
OBJECTS_DIR   := Release
CXXFLAGS      = -Wall -O2
endif

#### SOURCES
SRC_DIR     =  ./
OBJ_DIR     := $(OBJECTS_DIR)
SRC         :=  test.cpp 
HDR         =  

### Define compile variables
MAKEFILE        = Makefile
CC              = gcc
CXX             = g++
INCPATH         = -I"./"
LINK            = g++
LFLAGS          = 
LIBS            = -lboost_unit_test_framework
DEL_FILE        = del /Q
DEL_DIR         = rmdir /Q /S
CHK_DIR_NEXISTS = if not exist
CHK_DIR_EXISTS  = if exist
MKDIR           = mkdir
CXXOUTPUT       = -o

### SOURCES TRANSLATION
HDR  = $(addprefix $(SRC_DIR)/,$(HDR))
OBJ := $(addprefix $(OBJ_DIR)/,$(addsuffix .obj,$(basename $(SRC))))
SRC  = $(addprefix $(SRC_DIR)/,$(SRC))

### Build directory creation/deletion
mk_dir:
	-@$(CHK_DIR_NEXISTS) $(OBJECTS_DIR) $(MKDIR) $(OBJECTS_DIR)
clean:
	-@$(CHK_DIR_EXISTS) $(OBJECTS_DIR) $(DEL_DIR) $(OBJECTS_DIR)

#### Implicit rules
$(OBJ_DIR)/%.obj: $(SRC_DIR)/%.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) $(INCPATH) $(CXXOUTPUT)$@ -c $<

all: mk_dir test.exe
test.exe : $(OBJECTS_DIR)/test.obj
	$(LINK) -static $(LFLAGS) -o $(OBJECTS_DIR)/test.exe $(OBJ) \
		$(LIBS)

.PHONY: all first

