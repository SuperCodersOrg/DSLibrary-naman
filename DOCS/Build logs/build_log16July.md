# Design Build Log

### Date: 16/07/2026

---

## Session 1 — Setting Up the WSL Development Environment

### Objective

Configure a Linux-based development environment using WSL to build and test the DSLibrary project.

### Work Completed

- Installed and configured WSL with Ubuntu.
- Cloned the DSLibrary repository inside the WSL environment.
- Verified the GCC toolchain and CMake installation.
- Began configuring the project using the Linux build system.

### Challenges

- Understanding the difference between the Windows and Linux development environments.
- Configuring the project correctly after moving from the Windows toolchain.

### Outcome

- Successfully established the WSL development environment.
- The project was ready to be configured and built using Linux tools.

---

## Session 2 — Build Configuration and Compilation

### Objective

Configure and compile the DSLibrary project successfully inside WSL.

### Work Completed

- Configured the project using CMake with the Linux GCC compiler.
- Resolved generator mismatch issues caused by previously generated Windows build files.
- Fixed the missing `LinkedList.tpp` include issue during compilation.
- Successfully generated build files and compiled the project.

### Challenges

- Resolving CMake generator conflicts caused by cached build files.
- Identifying and correcting missing template implementation file references.
- Handling permission-related issues while working with files inside the Windows-mounted directory.

### Outcome

- The project compiled successfully inside WSL.
- The Linux build environment became stable for future development.

---

## Session 3 — Executing and Verifying the Build

### Objective

Verify the generated executables and understand the Linux testing workflow.

### Work Completed

- Executed the generated project binaries after compilation.
- Explored the project build output and test executables.
- Learned the correct usage of Valgrind by identifying the executable instead of the test directory.
- Verified that the build process completed successfully without compilation errors.

### Challenges

- Distinguishing between build directories and executable files.
- Learning the workflow for running executables and debugging tools in WSL.

### Outcome

- Successfully understood the Linux build and execution workflow.
- Established a reliable environment for future implementation, testing, and debugging of the DSLibrary project.