# 🚀 Pipex Project

## 📋 Overview
A C program that implements Unix/Linux pipe operations, allowing command execution with pipes and here_doc functionality.

## 💻 Usage

### First: Compile the Program
```bash
make        # Compile the program
```

### Two Main Operation Modes:

1. **Standard Pipeline Mode:**
```bash
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
This is equivalent to:
```bash
$> < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

2. **Here_doc Mode:**
```bash
$> ./pipex here_doc LIMITER cmd1 cmd2 file
```
This is equivalent to:
```bash
$> cmd1 << LIMITER | cmd2 >> file
```

### 📝 Real Examples:

**Example 1 - Multiple Pipes:**
```bash
$> ./pipex input.txt "ls -l" "grep .txt" "wc -l" output.txt
```
Equivalent to:
```bash
$> < input.txt ls -l | grep .txt | wc -l > output.txt
```

**Example 2 - Here_doc:**
```bash
$> ./pipex here_doc END "cat" "wc -l" output.txt
Hello, this is a test
This is another line
END
```
Equivalent to:
```bash
$> cat << END | wc -l >> output.txt
```

## 🛠️ Technical Implementation

### Key Components:
- Process creation and management (fork)
- Pipe communication between processes
- File descriptor handling
- Command execution with path resolution
- Input/Output redirection
- Error handling and memory management

### Process Flow:
1. Parse and validate input arguments
2. Set up necessary pipes
3. Fork processes for each command
4. Handle file descriptors and redirections
5. Execute commands
6. Clean up resources

## ⚙️ Building and Cleaning

```bash
make        # Build the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild the program
```

## 🚨 Error Handling

The program handles various error cases including:
- Invalid number of arguments
- File access errors
- Command not found
- Pipe creation failures
- Fork errors
- Memory allocation failures

## 📁 Project Structure

```
pipex/
├── src/
│   ├── main.c
│   ├── pipex.c
│   ├── utils.c
│   └── error.c
├── includes/
│   └── pipex.h
└── Makefile
```

## ✨ Features

- Multiple command pipeline support
- Here_doc implementation
- Path resolution for commands
- Robust error handling
- Memory leak prevention
- Clean process management

## 💡 Tips for Usage

1. Ensure proper permissions for input/output files
2. Use quotes for commands with arguments
3. Make sure commands exist in system PATH
4. Check error messages for troubleshooting

## Author

Created by [fatheddine-bicane]
