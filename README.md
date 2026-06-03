# mergeit

A fast, local PDF merging utility written in C++. An offline alternative to web services like ilovepdf.Less bloated and is accessible from the terminal

## Dependencies

Install the QPDF development library for your operating system.

### macOS
```bash
brew install qpdf pkg-config
```

### Arch Linux
```bash
sudo pacman -S qpdf
```

### Debian / Ubuntu
```bash
sudo apt update && sudo apt install libqpdf-dev pkg-config
```

## Compilation and Execution

Set up the repository with the following structure:
```plaintext
Merge-it/
├── contents/
│   ├── file1.pdf
│   └── file2.pdf
└── src/
    └── MergeingEngine.cpp
```

Navigate to the main project root directory (`Merge-it/`) in your terminal before running the compilation commands.

### Intel (x86) macOS
```bash
g++ -std=c++17 src/MergeingEngine.cpp -I/usr/local/include -L/usr/local/lib -lqpdf -o mergeit
./mergeit contents/file1.pdf contents/file2.pdf contents/out.pdf
```

### Apple Silicon (ARM) macOS
```bash
g++ -std=c++17 src/MergeingEngine.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lqpdf -o mergeit
./mergeit contents/file1.pdf contents/file2.pdf contents/out.pdf
```

### Linux
```bash
g++ -std=c++17 src/MergeingEngine.cpp $(pkg-config --cflags --libs libqpdf 2>/dev/null || echo "-lqpdf") -o mergeit
./mergeit contents/file1.pdf contents/file2.pdf contents/out.pdf
```

## TO-DO

- [ ] Provide a Makefile for automated builds
- [ ] Handle file naming conflicts automatically
- [ ] Support merging more than two PDFs sequentially
