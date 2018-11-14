cmake_minimum_required(VERSION 2.8)
 
if(POLICY CMP0020)
  cmake_policy(SET CMP0020 NEW)
endif()
 
PROJECT(FlowVis)
add_subdirectory(Utilities)
add_subdirectory(VectorField)



find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
 
if(${VTK_VERSION} VERSION_GREATER "6" AND VTK_QT_VERSION VERSION_GREATER "4")
  # Instruct CMake to run moc automatically when needed.
  set(CMAKE_AUTOMOC ON)
  find_package(Qt5Widgets COMPONENTS QtGui QtOpenGL REQUIRED QUIET)
else()
  find_package(Qt4 COMPONENTS QtGui QtOpenGL REQUIRED)
  include(${QT_USE_FILE})
endif()

find_package(OpenGL REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} )
include_directories( ${QT_QTOPENGL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} )

#target_link_libraries(testas ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

 
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
 
file(GLOB UI_FILES *.ui)
file(GLOB QT_WRAP *.h)
file(GLOB CXX_FILES *.cpp)
 
if(${VTK_VERSION} VERSION_GREATER "6" AND VTK_QT_VERSION VERSION_GREATER "4")
  qt5_wrap_ui(UISrcs ${UI_FILES} )
  # CMAKE_AUTOMOC in ON so the MOC headers will be automatically wrapped.
  add_executable(FlowVis MACOSX_BUNDLE
    ${CXX_FILES} ${UISrcs} ${QT_WRAP})
  qt5_use_modules(FlowVis Core Gui OpenGL)
  target_link_libraries(FlowVis ${VTK_LIBRARIES} Utilities VectorField)
else()
  QT4_WRAP_UI(UISrcs ${UI_FILES})
  QT4_WRAP_CPP(MOCSrcs ${QT_WRAP})
  add_executable(FlowVis MACOSX_BUNDLE ${CXX_FILES} ${UISrcs} ${MOCSrcs})
 
  if(VTK_LIBRARIES)
    if(${VTK_VERSION} VERSION_LESS "6")
      target_link_libraries(FlowVis ${OPENGL_LIBRARIES} ${VTK_LIBRARIES} QVTK Utilities VectorField)
    else()
      target_link_libraries(FlowVis ${OPENGL_LIBRARIES} ${VTK_LIBRARIES} Utilities VectorField)
    endif()
  else()
    target_link_libraries(FlowVis ${OPENGL_LIBRARIES} vtkHybrid QVTK vtkViews ${QT_LIBRARIES} Utilities VectorField)
  endif()
endif()
