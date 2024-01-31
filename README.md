
# Cesarean Cypher Project Documentation

This documentation provides an overview of the Makefile configuration and its usage within the Cesarean Cypher project, developed in C.

## Overview of Makefile Configuration

The Makefile orchestrates the build process, defining how the Cesarean Cypher is compiled, linked, and executed. It streamlines development by automating tasks such as building the executable, cleaning up artifacts, and running the program.

### Makefile Components

- **Variables**: Define the compiler (`CC`), flags (`CFLAGS`), program name (`PROGRAM`), and paths for artifacts (`BUILD_DIR`, `BIN_DIR`, `OBJ_DIR`).
- **Compilation and Linking**: Specific rules are set for compiling source files to object files and linking these to create the executable.
- **Directory Structure**: Implements a clean separation of source files from build artifacts, organizing executables in `bin` and object files in `obj`, all under a `/build` directory.

### Building, Execution and Testing

A special `run` target is included for executing the Cesarean Cypher, facilitating immediate testing post-build. Additionally, the `all` target has been adjusted to automatically run the program after building it, enhancing the development workflow by combining build and execution steps.
To build the project the target `build` is available.

### Cleaning Up
To clean up the project the target `clean` is available. It removes all build artifacts, including the executable, object files, and the build directory itself.

## Understanding the Makefile

The Makefile serves as the backbone of the project's build system, employing:

- **Automation**: Through `make`, compiling and linking tasks are automated based on file dependencies.
- **Modularity**: Variables and targets make the build process adaptable and maintainable.
- **Efficiency**: Phony targets like `build`, `clean` and `run` simplify project maintenance and testing.

## Additional Resources

For further exploration and to support the development of the Cesarean Cypher project, the following resources are recommended:

- **GNU Make Manual**: Essential reading for mastering Makefile usage. [GNU Make](https://www.gnu.org/software/make/manual/make.html)
- **Makefile Tutorial by Example**: A practical guide to Makefile concepts. [Tutorial](https://makefiletutorial.com/)
- **Project Structure Best Practices**: Advises on organizing C/C++ projects efficiently. [Structure Guide](https://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/)

This documentation aims to enhance the development experience by providing a clear framework for using Makefiles within the Cesarean Cypher project.
