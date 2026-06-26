# mergeit

A fast, local PDF merging utility written in C++. An offline alternative to web services like [ilovepdf](https://www.ilovepdf.com/) .This is Less bloated and is accessible from the terminal

## Dependencies

Install the QPDF development library for your operating system.

### macOS
```bash
brew install qpdf 
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

The repository consists of the following structure:
```plaintext
Merge-it/
├── contents/
│   ├── file1.pdf
│   └── file2.pdf
└── src/
    └── MergeingEngine.cpp
    └── Makefile
    
```

Navigate to the main project root directory (`Merge-it/`) in your terminal before running the compilation commands.

```
cd src
sudo make install
#enter the password
```

## Usage
Since `mergeit` is installed globally into your system's PATH, you can run it from any directory in your terminal.

To merge multiple PDFs, pass the input files sequentially and specify your desired output filename as the **final** argument:

```bash
mergeit "file1.pdf" "file2.pdf" "file3.pdf" "file-n.pdf" #file-n is the nth file
enclose the file name in double quotes if the filename has whitespace .
```
## TO-DO

- [x] Provide a Makefile for automated builds
- [ ] Handle file naming conflicts automatically
- [x] Support merging more than two PDFs sequentially

You have reached the end ThankYou :)
