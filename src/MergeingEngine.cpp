#include <iostream>
#include <qpdf/QPDF.hh>
#include <qpdf/QPDFPageDocumentHelper.hh>
#include <qpdf/QPDFWriter.hh>
#include <string>
#include <vector>


void append_pages(QPDF& main_pdf, const char* input_filename) {
    try {
        QPDF next_pdf;
        next_pdf.processFile(input_filename);

        QPDFPageDocumentHelper main_helper(main_pdf);
        QPDFPageDocumentHelper next_helper(next_pdf);

        std::vector<QPDFPageObjectHelper> next_pages = next_helper.getAllPages();

        for (auto& page : next_pages) {
            main_helper.addPage(page, false); // Append to the end of main_pdf in memory
        }
        std::cout << "Accumulated: " << input_filename << "\n";
    } catch (std::exception& e) {
        std::cerr << "Error processing " << input_filename << ": " << e.what() << "\n";
    }
}
int main(int argc, char *argv[]) {
  if (argc < 4) {
    std::cerr << "During Compilation use this format -> " << "<File1.pdf> "
              << "<File2.pdf> "
              << "<output_file.pdf> \n"; // hardcoded use sys calls to create
                                         // non existing files and stuff
    return 1;
  }
  char* output_file = argv[argc - 1];
  QPDF main_pdf;
  main_pdf.processFile(argv[1]);

  for (int i = 2; i < argc - 1; i++) {
      append_pages(main_pdf, argv[i]);
  }
  try {
        std::cout << "Writing finalized merged file to: " << output_file << "\n";
        QPDFWriter writer(main_pdf, output_file);
        writer.setStaticID(true);
        writer.write();
        std::cout << "Success!\n";
    } catch (std::exception& e){
        std::cerr << "Failed to write output file: " << e.what() << "\n";
        return 1;
    }
  


  return 0;
}
